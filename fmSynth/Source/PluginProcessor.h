/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PolySynth.h"
#include "Oscillator.h"

// ID and Name for the synth parameter
#define GAIN_ID             "GAIN"
#define GAIN_NAME           "Gain"

#define FILTER_CUTOFF_ID    "CUTOFF"
#define FILTER_CUTOFF_NAME  "Cutoff"

#define CARRIER_WAVE_ID     "CARRIERWAVE"
#define CARRIER_WAVE_NAME   "Wave Type"

#define OCTAVE_ID   "OCT"
#define OCTAVE_NAME "Octave"

#define MOD_WAVE_ID         "MODWAVE"
#define MOD_WAVE_NAME       "Wave Type"

#define MOD_FREQ_ID         "MODFREQ"
#define MOD_FREQ_NAME       "Frequency"

#define MOD_AMT_ID          "MODAMT"
#define MOD_AMT_NAME        "Amount"

//==============================================================================
/**
*/
class FmSynthAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    FmSynthAudioProcessor();
    ~FmSynthAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    PolySynth synth;
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FmSynthAudioProcessor)
    
    float gain;
    double filterCutoff;

    Random random;
    MidiKeyboardState keyboardState;
    OscillatorVoice* tempVoice;
    IIRFilter filterL, filterR;

    AudioProcessorValueTreeState valTreeState;
    AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
};
