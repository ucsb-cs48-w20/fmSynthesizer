//
//  Synth.hpp
//  fmSynth
//
//  Created by Jack Kilgore on 2/7/20.
//
#pragma one

#include "../JuceLibraryCode/JuceHeader.h"


struct SineSound : public SynthesiserSound
{
    
    SineSound() {}
    
    bool appliesToNote    (int) override        { return true; }
    bool appliesToChannel (int) override        { return true; }
    
};

class SineVoice : public SynthesiserVoice
{
public:
    
    SineVoice() {}
    
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<SineSound*> (sound) != nullptr;
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
    
    PolySynth (MidiKeyboardState& keyState): keyboardState (keyState) {}
    
    template<typename T1, typename T2>
    void addVoice(int number)
    {
        static_assert(std::is_base_of<SynthesiserSound, T1>::value,
                      "First type must derive from the SynthesiserSound class.");
        static_assert(std::is_base_of<SynthesiserVoice, T2>::value,
                      "Second type must derive from the SynthesiserVoice class.");
        for (auto i = 0; i < number; ++i)
            synth.addVoice (new T2());
    
        synth.addSound (new T1());
    }
    
    void clearSounds()
    {
       synth.clearSounds();
    }
    
    void prepareToPlay (double sampleRate)
    {
       synth.setCurrentPlaybackSampleRate (sampleRate);
    }
    
     void renderNextAudioBlock (AudioBuffer<float>& outputBuffer, int startSample, int numSamples, MidiBuffer& incomingMidi)
    {
        outputBuffer.clear();

        keyboardState.processNextMidiBuffer (incomingMidi, startSample,
                                             numSamples, true);

        synth.renderNextBlock (outputBuffer, incomingMidi,
                               startSample, numSamples);
    }
    
private:
    MidiKeyboardState& keyboardState;
    MidiMessageCollector midiCollector;
    Synthesiser synth;
    
    
};

