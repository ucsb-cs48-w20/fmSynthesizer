//
//  ModOscillators.cpp
//  fmSynth
//
//  Created by Jack Kilgore on 2/21/20.
//

#include "ModOscillators.h"

void ModOscVoice_0::startNote(int midiNoteNumber, float velocity,
    SynthesiserSound* sound, int /*currentPitchWheelPosition*/)
{
    rawMultiple = (int)(*params->getRawParameterValue(MOD_MULTIPLE_ID));
    if(rawMultiple < 0)
      multipleOfCarrier = -1 * 1/(float)rawMultiple;
    else multipleOfCarrier = rawMultiple;
    detune = *params->getRawParameterValue(MOD_DETUNE_ID);

    amount = *params->getRawParameterValue(MOD_AMT_ID);
    
    currentOctave = (int)(*params->getRawParameterValue(OCTAVE_ID));
    
    waveID = (int)(*params->getRawParameterValue(CARRIER_WAVE_ID));

    previousAngle = 0.0;
    nextSample = 0.0;
    currentAngle = 0.0;
    setLevel(amount);
    tailOff = 0.0;
    frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    setAngleDelta(frequency * multipleOfCarrier + detune);
}


void ModOscVoice_0::parameterUpdatePerBlock()
{
    int change;
    float changeF;
       
    change = (int)(*params->getRawParameterValue(MOD_WAVE_ID)) - waveID;
    if (change != 0)
        waveID = change + waveID;
    
    change = (int)(*params->getRawParameterValue(MOD_MULTIPLE_ID)) - rawMultiple;
    
    if (change != 0)
    {
        rawMultiple = (int)(*params->getRawParameterValue(MOD_MULTIPLE_ID));
        if(rawMultiple < 0)
            multipleOfCarrier = -1 * 1/(float)rawMultiple;
        else multipleOfCarrier = rawMultiple;
        setAngleDelta(carrierFrequency * multipleOfCarrier + detune);
    }
    
    changeF = (*params->getRawParameterValue(MOD_DETUNE_ID)) - detune;
    if (changeF != 0)
    {
        detune = *params->getRawParameterValue(MOD_DETUNE_ID);
        setAngleDelta(carrierFrequency * multipleOfCarrier + detune);
    }
    
    changeF = (*params->getRawParameterValue(MOD_AMT_ID)) - amount;
    if (changeF != 0)
    {
        detune = *params->getRawParameterValue(MOD_AMT_ID);
        setAngleDelta(carrierFrequency * multipleOfCarrier + detune);
    }
}

LFO::LFO(AudioProcessorValueTreeState* params, int LFOindex) : OscillatorVoice(params)
{
    switch(LFOindex)
    {
        case 1:
            freq_ID = LFO_FREQ_ID_1;
            wave_ID = LFO_WAVE_ID_1;
            amt_ID = LFO_AMT_ID_1;
            value_ID = LFO_VAL_ID_1;
            break;
        case 2:
            freq_ID = LFO_FREQ_ID_2;
            wave_ID = LFO_WAVE_ID_2;
            amt_ID = LFO_AMT_ID_2;
            value_ID = LFO_VAL_ID_2;
            break;
        case 3:
            freq_ID = LFO_FREQ_ID_3;
            wave_ID = LFO_WAVE_ID_3;
            amt_ID = LFO_AMT_ID_3;
            value_ID = LFO_VAL_ID_3;
            break;
        case 4:
            freq_ID = LFO_FREQ_ID_4;
            wave_ID = LFO_WAVE_ID_4;
            amt_ID = LFO_AMT_ID_4;
            value_ID = LFO_VAL_ID_4;
            break;
        default:
            std::cout << "fuck" << std::endl;
    }
    
}

void LFO::generateLFOSample()
{
// TODO SGJRGHIRDSGHSIRHGISRGHIRHG 
//    auto hold = params->getParameterAsValue(value_ID);
//    hold.setValue(generateSample(currentAngle));
}

void LFO::parameterUpdate(int Hz)
{
    
}
