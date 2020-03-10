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
    envelope.setSampleRate(getSampleRate());
    setADSRParameters(.5f, .2f, .5f, 5.0f);
    

    
    mModulator.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    
    mModulator_1.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    
    mCarrier.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    
    envelope.noteOn();
}

/**
 Render AUDIO for processing block.
 */
void FMVoice::renderNextBlock (AudioBuffer<float>& outputBuffer,
                      int startSample, int numSamples)
{
    ModBuffer.clear();
    mModulator.renderNextBlock(ModBuffer, startSample, numSamples);
    mModulator_1.renderNextBlock(ModBuffer, startSample, numSamples);
    mCarrier.renderNextBlock(ModBuffer, startSample, numSamples);
    envelope.applyEnvelopeToBuffer(ModBuffer, startSample, numSamples);
    for (int sample = 0; sample < numSamples; ++sample) {
        for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel) {
            outputBuffer.addSample(channel, startSample, ModBuffer.getSample(0, sample));
        }
        ++startSample;
    }
}


void FMVoice::stopNote (float velocity, bool allowTailOff)
{
    mModulator.stopNote(velocity, allowTailOff);
    mModulator_1.stopNote(velocity, allowTailOff);
    mCarrier.stopNote(velocity, allowTailOff);
    envelope.noteOff();
}

void FMVoice::setADSRParameters(float attack, float decay, float sustain, float release) {
    adsrParams.attack = attack;
    adsrParams.decay = decay;
    adsrParams.sustain = sustain;
    adsrParams.release = release;
    envelope.setParameters(adsrParams);
}
