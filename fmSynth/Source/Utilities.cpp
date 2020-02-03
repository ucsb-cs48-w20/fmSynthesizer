/*
  ==============================================================================

    Utilities.cpp
    Created: 2 Feb 2020 10:01:09pm
    Author:  Torrance Cui

  ==============================================================================
*/

#include "Utilities.h"

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