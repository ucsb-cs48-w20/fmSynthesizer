//
//  Utilities.cpp
//  fmSynth - All
//
//  Created by Jack Kilgore on 1/30/20.
//

#include "Utilities.hpp"

using namespace util;

/**** Line Class Implementation ****/

float Line::processAudio() {
    if (value != target) {
        value += increment;
        if ((increment < 0) ? (value < target) : (value > target)) value = target;
    }
    return value;
}

void Line::set(float v, float t, float s) {
    value = v;
    target = t;
    seconds = s;
    if (seconds <= 0) seconds = 1 / mSamplingRate;
    increment = (target - value) / (seconds * mSamplingRate);
}
