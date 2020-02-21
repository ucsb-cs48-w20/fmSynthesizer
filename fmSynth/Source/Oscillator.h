/*
  ==============================================================================

    Oscillator.h
    Created: 20 Feb 2020 8:44:43pm
    Author:  Tom

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "utilities.h"

#define SINE 1
#define SQUARE 2
#define SAW 3

struct OscillatorSound : public SynthesiserSound
{

    OscillatorSound() {}

    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }

};

class OscillatorVoice : public SynthesiserVoice
{
public:

    OscillatorVoice() { params = NULL;}
    OscillatorVoice(AudioProcessorValueTreeState* params) { this->params = params;}

    bool canPlaySound(SynthesiserSound* sound) override
    {
        return dynamic_cast<OscillatorSound*> (sound) != nullptr;
    }
    
    void isCarrier(bool carrier) {this->carrier = carrier;}
    
    float getLevel() const {return level;}
    void setLevel(float level) {this->level = level;}
    
    float getFrequency() const {return frequency;}
    void setFrequency(float frequency) {this->frequency = frequency;}
    
    void startNote(int midiNoteNumber, float velocity,
        SynthesiserSound* sound, int /*currentPitchWheelPosition*/) override;

    void stopNote(float /*velocity*/, bool allowTailOff) override;
    
    /**
            Pointer to the buffer where the modulate audio will be stored.
     */
    void setModBuffer(AudioBuffer<float>* buffer) {ModBuffer = buffer;};

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
    
    //temp
    void setAngleDelta(float freq);
    
protected:
    float generateSample(float angle);
    float sineWave(float angle);
    float squareWave(float angle);
    float sawWave(float angle);

    void angleCap(); // call after you increment currentAngle to avoid overflows
    void parameterUpdate(); // check all relevant parameters and adjust members accordingly (this allows for changes mid-note)

private:
    float nextSample = 0.0, delta = 0.0,
        currentAngle = 0.0, previousAngle = 0.0, angleDelta = 0.0,
        frequency, level = 0.0, tailOff = 0.0, twoPi = 0.0;
    
    int currentOctave = 0;
    
    bool carrier;
    
    AudioBuffer<float>* ModBuffer;
    
    AudioProcessorValueTreeState* params;
};
