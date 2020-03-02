//
//  ModOscillators.h
//  fmSynth
//
//  Created by Jack Kilgore on 2/21/20.
//

#pragma one
#include "Oscillator.h"

struct ModOscSound_0 : public OscillatorSound
{

    ModOscSound_0() {}

    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }

};

class ModOscVoice_0 : public OscillatorVoice
{
public:

    ModOscVoice_0() {
        params = NULL;
    }
    ModOscVoice_0(AudioProcessorValueTreeState* params) : OscillatorVoice(params){}

    bool canPlaySound(SynthesiserSound* sound) override
    {
       return dynamic_cast<ModOscSound_0*> (sound) != nullptr;
    }
    
     void startNote(int midiNoteNumber, float velocity,
           SynthesiserSound* sound, int /*currentPitchWheelPosition*/) override;
                
protected:
    void parameterUpdatePerBlock() override;
    void parameterUpdatePerSample() override {};

private:
    float carrierFrequency, multipleOfCarrier, detune, amount;
    int rawMultiple;
};

class LFO : public OscillatorVoice
{
public:

    LFO() {
        params = NULL;
    }
    /**
     LFOindex must be a value from 1-4
     */
    LFO(AudioProcessorValueTreeState* params, int LFOindex);
    
    void generateLFOSample();

    bool canPlaySound(SynthesiserSound* sound) override {return true;}
    void startNote(int midiNoteNumber, float velocity,
                    SynthesiserSound* sound, int /*currentPitchWheelPosition*/) override {};
    
    void parameterUpdate(int Hz);
    
protected:
    void parameterUpdatePerBlock() override{};
    void parameterUpdatePerSample() override {};

private:
    std::string freq_ID, wave_ID, amt_ID, value_ID;
    
};
