/*
  ==============================================================================

    Oscillator.h
    Created: 2 Feb 2020 9:59:53pm
    Author:  Torrance Cui

  ==============================================================================
*/


#ifndef Oscillator_h
#define Oscillator_h

#include <vector>

class Sine
{
public:
    Sine();
    
    void initialize(float sampleRate = 48000, float frequency = 440, int tableSize = 512);
    
    void setFrequency(float frequency);
    
    float processAudio();
    
private:
    float mFrequency;
    float mPhase;
    float mSampleRate;
    float mIncrement;
    float mIndex;
    std::vector<float> mTable;
    int mTableSize;
    
};


#endif /* Oscillator_h */