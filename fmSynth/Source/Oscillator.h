#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "SawOsc.h"
#include "SineOsc.h"
#include "SquareOsc.h"

//// EXPERIMENTAL FILES BLEH

enum Waveform {SAW, SQUARE, SINE};

class Oscillator {
public:
    
    void setWaveform(Waveform wave = SINE) {mWave = wave;}
    
    void startNote(int midiNoteNumber, float velocity,
                   SynthesiserSound* sound, int currentPitchWheelPosition);
    
    void stopNote(float /*velocity*/, bool allowTailOff);

    void pitchWheelMoved(int)  {}
    void controllerMoved(int, int)  {}

    void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples) ;
    
private:
    SineVoice mSine;
    SawVoice mSaw;
    SquareVoice mSquare;
    Waveform mWave;
};
