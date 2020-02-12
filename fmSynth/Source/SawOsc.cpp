//
//  SawOsc.cpp
//  fmSynth
//

#include "SawOsc.hpp"

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
