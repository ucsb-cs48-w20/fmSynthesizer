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

    OscillatorVoice() { params = NULL; carrier = false;}
    OscillatorVoice(AudioProcessorValueTreeState* params) { this->params = params; carrier = false;}

    bool canPlaySound(SynthesiserSound* sound) override
    {
        return dynamic_cast<OscillatorSound*> (sound) != nullptr;
    }
    
    /**
     @brief If true, the oscillator assumes that the frequency is being modulated per sample based on the value found in buffer.
     @param carrier :  If true, you must pass in a non nullptr to an AudioBuffer. If false just pass a nullptr.
     @param buffer : The buffer containing the samples from a modulation source.
     */
    void isCarrier(bool carrier, AudioBuffer<float>* buffer);
    bool getCarrier() const {return carrier;}
    void setLevel(float level) {this->level = level;}
    float getLevel() const {return level;}
    
    float getFrequency() const {return frequency;}
    void setFrequency(float frequency) {this->frequency = frequency;}
        
    void startNote(int midiNoteNumber, float velocity,
        SynthesiserSound* sound, int /*currentPitchWheelPosition*/) override;

    void stopNote(float /*velocity*/, bool allowTailOff) override;

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
    
    void setAngleDelta(float freq);
        
    virtual void parameterUpdate() = 0; // check all relevant parameters and adjust members accordingly (this allows for changes mid-note)
    
    
protected:
    AudioProcessorValueTreeState* params;

    float generateSample(float angle);
    float sineWave(float angle);
    float squareWave(float angle);
    float sawWave(float angle);
    void angleCap(); // call after you increment currentAngle to avoid overflows
    float nextSample = 0.0, delta = 0.0,
        currentAngle = 0.0, previousAngle = 0.0, angleDelta = 0.0,
        frequency, level = 0.0, tailOff = 0.0;
    
    constexpr static float TWO_PI = 6.28318530718;
    
    int waveID, currentOctave;

private:
    
    bool carrier;
    
    AudioBuffer<float>* ModBuffer;
};