#include "Oscillator.h"

//=====OscillatorVoice Implementation==========
void Oscillator::renderNextBlock(AudioBuffer<float>& outputBuffer, int  startSample, int numSamples)
{
    switch(mWave) {
            
        case SAW:
            mSaw.renderNextBlock(outputBuffer,startSample, numSamples);
            break;
        case SQUARE:
            mSquare.renderNextBlock(outputBuffer,startSample, numSamples);
            break;
        case SINE:
        default:
            mSine.renderNextBlock(outputBuffer,startSample, numSamples);
    }
}

void Oscillator::startNote(int midiNoteNumber, float velocity,
                           SynthesiserSound* sound, int currentPitchWheelPosition)
{
    switch(mWave) {
            
        case SAW:
            mSaw.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
            break;
            
        case SQUARE:
            mSquare.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
            break;
            
        case SINE:
        default:
            mSine.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    }
    
}
