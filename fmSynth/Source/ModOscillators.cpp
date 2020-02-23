//
//  ModOscillators.cpp
//  fmSynth
//
//  Created by Jack Kilgore on 2/21/20.
//

#include "ModOscillators.h"

void ModOscVoice_0::setInitParams()
{
    rawMultiple = (int)(*params->getRawParameterValue(MOD_MULTIPLE_ID));    
    if(rawMultiple < 0)
       multipleOfCarrier = -1 * 1/(float)rawMultiple;
    else multipleOfCarrier = rawMultiple;
    detune = *params->getRawParameterValue(MOD_DETUNE_ID);
    
    amount = *params->getRawParameterValue(MOD_AMT_ID);
}

void ModOscVoice_0::setModParams()
{
    setLevel(amount);
    setAngleDelta(carrierFrequency * multipleOfCarrier + detune);
    delta = angleDelta/juce::MathConstants<float>::pi;
    
}

void ModOscVoice_0::parameterUpdate()
{
    int change;
    float changeF;
       
    change = (int)(*params->getRawParameterValue(MOD_WAVE_ID)) - waveID;
    if (change != 0)
        waveID = change + waveID;
    
    change = (int)(*params->getRawParameterValue(MOD_MULTIPLE_ID)) - rawMultiple;

    if (change != 0)
    {
        rawMultiple = change - rawMultiple;
        if(rawMultiple < 0)
            multipleOfCarrier = -1 * 1/(float)rawMultiple;
        else multipleOfCarrier = rawMultiple;
        setModParams();
    }
    
    changeF = (*params->getRawParameterValue(MOD_DETUNE_ID)) - detune;
    if (changeF != 0)
    {
        detune = *params->getRawParameterValue(MOD_DETUNE_ID);
        setModParams();
    }
    
    changeF = (*params->getRawParameterValue(MOD_AMT_ID)) - amount;
    if (changeF != 0)
    {
        detune = *params->getRawParameterValue(MOD_AMT_ID);
        setModParams();
    }
    
    

    

    
}
