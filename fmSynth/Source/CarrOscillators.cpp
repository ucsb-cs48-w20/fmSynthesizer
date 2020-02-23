//
//  CarrOscillators.cpp
//  fmSynth
//
//  Created by Jack Kilgore on 2/22/20.
//

#include "CarrOscillators.h"



void CarrOscVoice_0::setInitParams() {
//    waveID = (int)(*params->getRawParameterValue(CARRIER_WAVE_ID));
    currentOctave = (int)(*params->getRawParameterValue(OCTAVE_ID));
}

void CarrOscVoice_0::parameterUpdate()
{
    int change;
    
    change = (int)(*params->getRawParameterValue(CARRIER_WAVE_ID)) - waveID;
    if (change != 0)
        waveID = change + waveID;
    
    // check octave
    change = (int)(*params->getRawParameterValue(OCTAVE_ID)) - currentOctave;
    if (change != 0)
    {
        float adjustment = (float)pow(2, change);
        delta *= adjustment;
        angleDelta *= adjustment;
        currentOctave = change + currentOctave;
    }

}
