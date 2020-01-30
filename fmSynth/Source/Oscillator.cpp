//
//  Oscillator.cpp
//  fmSynth - All
//
//  Created by Jack Kilgore on 1/30/20.
//

#include "Oscillator.hpp"

#include <math.h>

//============================= Sine Implementation =============================

Sine::Sine()
{
    mTableSize = 512;
    mSampleRate = 48000;
    mFrequency = 440;
    mIndex = 0;
}

void Sine::initialize(float sampleRate, float frequency, int tableSize)
{
    mSampleRate = sampleRate;
    mFrequency = frequency;
    mTableSize = tableSize;
    
    for(int index = 0; index < mTableSize; ++index)
    {
        mTable.push_back(sinf(2 * M_PI * (float)index/mTableSize));
    }
    
    mIncrement = mFrequency * mTableSize / mSampleRate;
}

void Sine::setFrequency(float frequency)
{
    mFrequency = frequency;
    mIncrement = mFrequency * mTableSize / mSampleRate;
}

float Sine::processAudio()
{
    //Increment table look up index.
    mIndex += mIncrement;
    
    //Wrappers
    if(mIndex >= mTableSize) mIndex -= mTableSize;
    if(mIndex < 0) mIndex += mTableSize;
    
    return mTable.at((int)mIndex);
}

