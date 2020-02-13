/*
  ==============================================================================

    SawOsc.cpp
    Created: 10 Feb 2020 9:47:20pm
    Author:  Torrance Cui

  ==============================================================================
*/

#include "SawOsc.h"

//=====SawVoice Implementation==========

void SawVoice::startNote (int midiNoteNumber, float velocity,
                SynthesiserSound* sound, int /*currentPitchWheelPosition*/)
{
  //stub
}

void SawVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
  //stub
}

void SawVoice::renderNextBlock (AudioBuffer<float>& outputBuffer,
                      int startSample, int numSamples)
{
   // stub
}
