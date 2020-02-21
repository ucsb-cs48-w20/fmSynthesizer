//
//  FMOsc.h
//  fmSynth
//
//  Created by Jack Kilgore on 2/19/20.
//



#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"


struct FMSound : public SynthesiserSound
{

    FMSound() {}

    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }

};

class FMVoice : public SynthesiserVoice
{
public:
    
    FMVoice() : ModBuffer(1, 512) { params = NULL; }
    FMVoice(AudioProcessorValueTreeState* params) : ModBuffer(1, 512), mModulator(params), mCarrier(params) { this->params = params; }

    bool canPlaySound(SynthesiserSound* sound) override
    {
        return dynamic_cast<FMSound*> (sound) != nullptr;
    }
    
    /**
     @brief Set x in the equation ModulatorFrequency = CarrierFrequency * x;
     */
    void setModMultiple(int value);
    
    /**
        @brief Set f in the equation ModulatorFrequency = CarrierFrequency *( x + f);
                where f is a number between 0 and 1. For detuning the modulator.
    */
    void setModDetune(float value);
    
    void startNote(int midiNoteNumber, float velocity,
        SynthesiserSound* sound, int currentPitchWheelPosition) override;

    void stopNote(float velocity, bool allowTailOff) override;

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

private:
    
    
    void angleCap(); // call after you increment currentAngle to avoid overflows
    
    void setAngleDelta(float freq);
    
    float currentAngle = 0.0, angleDelta = 0.0,
            level = 0.0, frequency = 0.0, tailOff = 0.0, twoPi = 0.0;
    
    float TESTSAMPLKE;
    
    OscillatorVoice mModulator;
    OscillatorVoice mCarrier;
    
    AudioProcessorValueTreeState* params;
    AudioBuffer<float> ModBuffer;
    
    
};
