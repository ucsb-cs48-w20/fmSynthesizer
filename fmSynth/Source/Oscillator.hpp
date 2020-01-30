//
//  Oscillator.hpp
//  fmSynth - All
//
//  Created by Jack Kilgore on 1/30/20.
//

#ifndef Oscillator_hpp
#define Oscillator_hpp

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


#endif /* Oscillator_hpp */
