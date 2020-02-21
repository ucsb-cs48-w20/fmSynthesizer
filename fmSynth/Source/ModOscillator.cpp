//
//  ModOscillator.cpp
//  fmSynth
//
//  Created by Jack Kilgore on 2/21/20.
//

#include "ModOscillator.h"

void ModOscillatorVoice::setAngleDelta(float freq)
{
    auto cyclesPerSample = freq / getSampleRate();
    angleDelta = cyclesPerSample * twoPi;
    
}

/**
 This is where we set up all the parameters needed when a note is pressed.
 */
void ModOscillatorVoice::startNote(int midiNoteNumber, float velocity,
    SynthesiserSound* sound, int /*currentPitchWheelPosition*/)
{
    previousAngle = 0.0;
    nextSample = 0.0;
    currentAngle = 0.0;
    level = velocity * 0.15;
    tailOff = 0.0;

    currentOctave = (int)(*params->getRawParameterValue(OCTAVE_ID)); // 1, 2 ,3, or 4
    auto octave = (float)pow(2, currentOctave-2);

    auto cyclesPerSecond = octave * MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    auto cyclesPerSample = cyclesPerSecond / getSampleRate();
    
    angleDelta = cyclesPerSample * twoPi;
    delta = cyclesPerSample * 2.0;
}

/**
 Little decay envelope, SEE MIDI Synth tutorial.
 */
void ModOscillatorVoice::stopNote(float /*velocity*/, bool allowTailOff)
{
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


/**
 Render AUDIO for processing block.
 */
void ModOscillatorVoice::renderNextBlock(AudioBuffer<float>& outputBuffer,
    int startSample, int numSamples)
{
    if (angleDelta != 0.0)
    {
//        parameterUpdate();
        if (tailOff > 0.0) // [7]
        {
            while (--numSamples >= 0)
            {
                if(carrier)
                    setAngleDelta(getFrequency() + outputBuffer.getSample(0, startSample));
                
                auto currentSample = (float)(generateSample(currentAngle) * level * tailOff);

                for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample(i, startSample, currentSample);

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
                if(carrier)
                    setAngleDelta(getFrequency() + outputBuffer.getSample(0, startSample));
                
                auto currentSample = (float)(generateSample(currentAngle) * level);

                for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample(i, startSample, currentSample);

                currentAngle += angleDelta;
                angleCap();
                ++startSample;
            }
        }
    }
}

void ModOscillatorVoice::parameterUpdate()
{
    OscillatorVoice::parameterUpdate();

    // TODO : check frequency from Modulator here (do we do this before or after octave???)
}
