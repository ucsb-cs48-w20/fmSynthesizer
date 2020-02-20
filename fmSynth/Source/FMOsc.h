#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

////EXPERIMENTAL FILES BLEHHH



struct FMSound : public SynthesiserSound
{

    FMSound() {}

    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }

};

class FMVoice : public SynthesiserVoice
{
public:

    FMVoice() {}

    bool canPlaySound(SynthesiserSound* sound) override
    {
        return dynamic_cast<FMSound*> (sound) != nullptr;
    }

    //    DUMMY FUNCTION
    //    void setParam1(float* param1);

    void startNote(int midiNoteNumber, float velocity,
        SynthesiserSound* sound, int currentPitchWheelPosition) override;

    void stopNote(float /*velocity*/, bool allowTailOff) override;

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

private:
    
    Oscillator  mCarrier;
    Oscillator mModulator;
    
};
