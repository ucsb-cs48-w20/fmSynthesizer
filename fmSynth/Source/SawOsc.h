//
//  SawOsc.h
//  fmSynth
//
#pragma one

#include "../JuceLibraryCode/JuceHeader.h"

struct SawSound : public SynthesiserSound
{
    
    SawSound() {}
    
    bool appliesToNote    (int) override        { return true; }
    bool appliesToChannel (int) override        { return true; }
    
};

class SawVoice : public SynthesiserVoice
{
public:
    
    SawVoice() {}
    
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<SawSound*> (sound) != nullptr;
    }
    
//    DUMMY FUNCTION
//    void setParam1(float* param1);
    
    void startNote (int midiNoteNumber, float velocity,
                    SynthesiserSound* sound, int /*currentPitchWheelPosition*/) override;
    
    void stopNote (float /*velocity*/, bool allowTailOff) override;
    
    void pitchWheelMoved (int) override      {}
    void controllerMoved (int, int) override {}
    
    void renderNextBlock (AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
    
private:
    // TO DO TO DO
};
