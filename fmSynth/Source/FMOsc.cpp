#include "FMOsc.h"

/**
 This is where we set up all the parameters needed when a note is pressed.
 */
void FMVoice::startNote (int midiNoteNumber, float velocity,
                SynthesiserSound* sound, int currentPitchWheelPosition)
{
    mCarrier.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    
    mModulator.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    
}

/**
 Little decay envelope, SEE MIDI Synth tutorial.
 */
void FMVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
}

/**
 Render AUDIO for processing block.
 */
void FMVoice::renderNextBlock (AudioBuffer<float>& outputBuffer,
                      int startSample, int numSamples)
{

}
