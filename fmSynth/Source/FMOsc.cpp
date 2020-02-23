//
//  FMOsc.cpp
//  fmSynth
//
//  Created by Jack Kilgore on 2/19/20.
//

#include "FMOsc.h"
/**
 This is where we set up all the parameters needed when a note is pressed.
 */
void FMVoice::startNote (int midiNoteNumber, float velocity,
                SynthesiserSound* sound, int currentPitchWheelPosition)
{
    mCarrier.setInitParams();
    mCarrier.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    mCarrier.isCarrier(true);
    mCarrier.setModBuffer(&ModBuffer);
    
    mModulator.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    mModulator.setCarrFrequency(MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    mModulator.setInitParams();
    mModulator.setModParams();
}

/**
 Render AUDIO for processing block.
 */
void FMVoice::renderNextBlock (AudioBuffer<float>& outputBuffer,
                      int startSample, int numSamples)
{
    ModBuffer.clear();
    mModulator.renderNextBlock(ModBuffer, startSample, numSamples);    
    mCarrier.renderNextBlock(outputBuffer, startSample, numSamples);
}


void FMVoice::stopNote (float velocity, bool allowTailOff)
{
    mModulator.stopNote(velocity, allowTailOff);
    mCarrier.stopNote(velocity, allowTailOff);

}

    
 


