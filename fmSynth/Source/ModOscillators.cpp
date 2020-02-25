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
        rawMultiple = change - rawMultiple;
        if(rawMultiple < 0)
            multipleOfCarrier = -1 * 1/(float)rawMultiple;
        else multipleOfCarrier = rawMultiple;
        setAngleDelta(carrierFrequency * multipleOfCarrier + detune);
        delta = angleDelta/juce::MathConstants<float>::pi;
    }
    
    changeF = (*params->getRawParameterValue(MOD_DETUNE_ID)) - detune;
    if (changeF != 0)
    {
        detune = *params->getRawParameterValue(MOD_DETUNE_ID);
        setAngleDelta(carrierFrequency * multipleOfCarrier + detune);
        delta = angleDelta/juce::MathConstants<float>::pi;
    }
    
    changeF = (*params->getRawParameterValue(MOD_AMT_ID)) - amount;
    if (changeF != 0)
    {
        detune = *params->getRawParameterValue(MOD_AMT_ID);
        setAngleDelta(carrierFrequency * multipleOfCarrier + detune);
        delta = angleDelta/juce::MathConstants<float>::pi;
    }
}
