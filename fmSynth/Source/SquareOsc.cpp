//
//  SquareOsc.hpp
//  fmSynth
//
#include "SquareOsc.hpp"

//=====SquareVoice Implementation==========

void SquareVoice::startNote (int midiNoteNumber, float velocity,
                SynthesiserSound* sound, int /*currentPitchWheelPosition*/)
{
  //stub
}

void SquareVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
  //stub
}

void SquareVoice::renderNextBlock (AudioBuffer<float>& outputBuffer,
                      int startSample, int numSamples)
{
   // stub
}
