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

    OscillatorVoice() { params = NULL; }
    OscillatorVoice(AudioProcessorValueTreeState* params) { this->params = params; }

    bool canPlaySound(SynthesiserSound* sound) override
    {
        return dynamic_cast<OscillatorSound*> (sound) != nullptr;
    }

    //    DUMMY FUNCTION 
    //    void setParam1(float* param1);

    void startNote(int midiNoteNumber, float velocity,
        SynthesiserSound* sound, int /*currentPitchWheelPosition*/) override;

    void stopNote(float /*velocity*/, bool allowTailOff) override;

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

private:
    float generateSample(float angle);
    float sineWave(float angle);
    float squareWave(float angle);
    float sawWave(float angle);

    void angleCap(); // call after you increment currentAngle to avoid overflows
    void parameterUpdate(); // check all relevant parameters and adjust members accordingly (this allows for changes mid-note)

    float nextSample = 0.0, delta = 0.0,
        currentAngle = 0.0, previousAngle = 0.0, angleDelta = 0.0,
        level = 0.0, tailOff = 0.0, twoPi = 0.0;

    int currentOctave = 0;

    AudioProcessorValueTreeState* params;
};
