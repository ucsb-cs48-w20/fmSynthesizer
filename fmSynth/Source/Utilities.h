/*
  ==============================================================================

    Utilities.h
    Created: 2 Feb 2020 10:01:09pm
    Author:  Torrance Cui

  ==============================================================================
*/

#ifndef Utilities_h
#define Utilities_h

namespace util
{

class Line {
 public:

/**
 * @brief Default constructor.
 */
    Line() {mSamplingRate = 48000; }

    /**
     * @brief Line constructor.
     *
     * @param[in] The sample rate needed for operator()
     */
    Line(float samplingRate) : mSamplingRate(samplingRate) {}

    /**
     * @brief Generate Line in real-time.
     *
     * @return Amplitude value at a point in time.
     */
    float processAudio();


    /**
     * @brief Set paramaters of class.
     *
     * @param[in]: Starting value.
     * @param[in]: Target value.
     * @param[in]: The amount of time to go from the starting value to the target value.
     */
    void set(float v = 0, float t = 0, float s = 1);

    void setSamplingRate(float samplingRate) {mSamplingRate = samplingRate;}

    float getSamplingRate() const {return mSamplingRate;}

    /**
     * @brief Check if the Line function is complete.
     *
     * @param[in] Return true if reached target, false otherwise.
     */
    bool const done() { return value == target; }

 private:
    float value = 0, target = 0, seconds = 1 , increment = 0;
    float mSamplingRate;
};

} //end namespace util


#endif /* Utilities_h */
