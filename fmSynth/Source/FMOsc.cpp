//
//  FMOsc.cpp
//  fmSynth
//
//  Created by Jack Kilgore on 2/19/20.
//

#include "FMOsc.h"

void FMVoice::setAngleDelta(float freq)
{
    auto cyclesPerSample = freq / getSampleRate();
    angleDelta = cyclesPerSample * twoPi;
    
}


/**
 This is where we set up all the parameters needed when a note is pressed.
 */
void FMVoice::startNote (int midiNoteNumber, float velocity,
                SynthesiserSound* sound, int currentPitchWheelPosition)
{
//    mTest.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    mModulator.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    mModulator.setAngleDelta(2);
    mModulator.setLevel(200);
    
    mCarrier.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    mCarrier.setModBuffer(&ModBuffer);
    
    level = velocity * 0.15;
    tailOff = 0.0;
    twoPi = 2.0 * MathConstants<double>::pi;
    setAngleDelta(MidiMessage::getMidiNoteInHertz (midiNoteNumber));
    
}

/**
 Render AUDIO for processing block.
 */
void FMVoice::renderNextBlock (AudioBuffer<float>& outputBuffer,
                      int startSample, int numSamples)
{
        
    ModBuffer.clear();
    mModulator.renderNextBlock(ModBuffer, startSample, numSamples);
    
    
    if (angleDelta != 0.0)
        {
            if (tailOff > 0.0) // [7]
            {
                while (--numSamples >= 0)
                {
                    
                                
                    setAngleDelta(mCarrier.getFrequency() + ModBuffer.getSample(0, startSample) );

                    
                    auto currentSample = (float) (std::sin (currentAngle) * level * tailOff);
                    
                    for (auto i = outputBuffer.getNumChannels(); --i >= 0;) 
                        outputBuffer.addSample (i, startSample, currentSample);
                    
                       
                    currentAngle += angleDelta;
                    angleCap();
                    ++startSample;

                    tailOff *= 0.99; // [8]

                    if (tailOff <= 0.005)
                    {
                        clearCurrentNote(); // [9]

                        angleDelta = 0.0;
                        break;
                    }
                }
            }
            else
            {
                while (--numSamples >= 0) // [6]
                {
                    
                    setAngleDelta((mCarrier.getFrequency() + ModBuffer.getSample(0, startSample)));
                    
                    auto currentSample = (float) (std::sin (currentAngle) * level);

                    for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
                        outputBuffer.addSample (i, startSample, currentSample);
                    

                    
                    currentAngle += angleDelta;
                    angleCap();
                    ++startSample;
                }
            }
        }
}

void FMVoice::angleCap()
{
    if (currentAngle >= twoPi)
    {
        currentAngle -= twoPi;
    }
}

void FMVoice::stopNote (float velocity, bool allowTailOff)
{
    mModulator.stopNote(velocity, allowTailOff);
//    mCarrier.stopNote(velocity, allowTailOff);
    if (allowTailOff)
    {
        if (tailOff == 0.0)
            tailOff = 1.0;
    }
    else
    {
        clearCurrentNote();
        angleDelta = 0.0;
    }
}

    
 


