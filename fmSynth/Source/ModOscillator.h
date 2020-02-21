//
//  ModOscillator.h
//  fmSynth
//
//  Created by Jack Kilgore on 2/21/20.
//

#pragma one
#include "Oscillator.h"

struct ModOscillatorSound : public OscillatorSound
{

    ModOscillatorSound() {}

    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }

};

/**
 An OscillatorVoice with modulation capabilities in mind.
 */
class ModOscillatorVoice : public OscillatorVoice
{
public:

    ModOscillatorVoice() {
        params = NULL; carrier = false;
        twoPi = 2.0 * MathConstants<double>::pi;
    }
    ModOscillatorVoice(AudioProcessorValueTreeState* params) { this->params = params; carrier = false;
        twoPi = 2.0 * MathConstants<double>::pi;
    }

    bool canPlaySound(SynthesiserSound* sound) override
    {
       return dynamic_cast<ModOscillatorSound*> (sound) != nullptr;
    }

    // If set to true, the Oscillator instance assumes that its frequency is being modulated on a sample by sample basis by the buffer being passed into renderNextBlock.
    void setCarrier(bool carrier) {this->carrier = carrier;}

    float getLevel() const {return level;}
    void setLevel(float level) {this->level = level;}

    float getFrequency() const {return frequency;}
    void setFrequency(float frequency) {this->frequency = frequency;}

    void startNote(int midiNoteNumber, float velocity,
           SynthesiserSound* sound, int /*currentPitchWheelPosition*/) override;

    void stopNote(float /*velocity*/, bool allowTailOff) override;


    void renderNextBlock(AudioBuffer<float>& outputBuffer,
                        int startSample, int numSamples) override;
    
    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}
       

protected:
 
    //This can be set independent of the frequency parameter for modulation purposes.
    void setAngleDelta(float freq);
    void parameterUpdate();

private:
    float nextSample = 0.0, delta = 0.0,
        currentAngle = 0.0, previousAngle = 0.0, angleDelta = 0.0,
        frequency, level = 0.0, tailOff = 0.0, twoPi = 0.0;
    
    bool carrier;
    int currentOctave;
     AudioProcessorValueTreeState* params;
};
