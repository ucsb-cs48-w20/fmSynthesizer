//
//  Synth.hpp
//  fmSynth
//
//  Created by Jack Kilgore on 2/7/20.
//
#pragma one

#include "../JuceLibraryCode/JuceHeader.h"


struct SynthSound : SynthesiserSound
{
    
    SynthSound() {}
    
    bool appliesToNote    (int) override        { return true; }
    bool appliesToChannel (int) override        { return true; }
    
};

class SynthVoice : SynthesiserVoice
{
public:
    
    SynthVoice() {}
    
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<SynthSound*> (sound) != nullptr;
    }
    
    void startNote (int midiNoteNumber, float velocity,
                    SynthesiserSound*, int /*currentPitchWheelPosition*/) override;
    
    void stopNote (float /*velocity*/, bool allowTailOff) override;
    
    void pitchWheelMoved (int) override      {}
    void controllerMoved (int, int) override {}
    
    void renderNextBlock (AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
    
private:
     float currentAngle = 0.0, angleDelta = 0.0,
            level = 0.0, tailOff = 0.0;
};

class PolySynth
{
public:
    
private:
    MidiKeyboardState keyboardState;
    Synthesiser synth;
    
};

