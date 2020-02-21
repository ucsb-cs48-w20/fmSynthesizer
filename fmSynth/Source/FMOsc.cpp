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
    mTest.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    mModTest.startNote(midiNoteNumber, velocity, sound, currentPitchWheelPosition);
    mModTest.setFrequency(MidiMessage::getMidiNoteInHertz (midiNoteNumber) * 2);
    mModTest.setLevel(0);
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
        
    mModTest.renderNextBlock(outputBuffer, startSample, numSamples);
    
    
    if (angleDelta != 0.0)
        {
            if (tailOff > 0.0) // [7]
            {
                while (--numSamples >= 0)
                {
                    
                    
                    TESTSAMPLKE = outputBuffer.getSample(0, startSample);
                    
                    setAngleDelta((mTest.getFrequency() + outputBuffer.getSample(0, startSample)));
            
                    
                    
                    auto currentSample = (float) (std::sin (currentAngle) * level * tailOff);
                    
                    for (auto i = outputBuffer.getNumChannels(); --i >= 0;) {
                        outputBuffer.clear(i, startSample, 1);
                        outputBuffer.addSample (i, startSample, currentSample);
                    }
                       
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
                     TESTSAMPLKE = outputBuffer.getSample(0, startSample);
                    
                    setAngleDelta((mTest.getFrequency() + outputBuffer.getSample(0, startSample)));
                    
                    auto currentSample = (float) (std::sin (currentAngle) * level);

                    for (auto i = outputBuffer.getNumChannels(); --i >= 0;) {
                        outputBuffer.clear(i, startSample, 1);
                        outputBuffer.addSample (i, startSample, currentSample);
                    }

                    
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
    mModTest.stopNote(velocity, allowTailOff);
    mTest.stopNote(velocity, allowTailOff);
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

    
 


