/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class FmSynthAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    //FmSynthAudioProcessorEditor (FmSynthAudioProcessor&);
    FmSynthAudioProcessorEditor(FmSynthAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~FmSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FmSynthAudioProcessor& processor;
    AudioProcessorValueTreeState& valueTreeState;

    Slider gainSlider;
    Slider cutoffSlider;
    Slider octaveKnob;
    Slider modMultipleKnob;
    Slider modDetuneKnob;
    Slider modAmtKnob;

    Label textLabel;
    ComboBox modWaveSelect;
    ComboBox carWaveSelect;

    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> gainAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> cutoffAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> carWaveAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> octAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::ComboBoxAttachment> modWaveAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> modMultipleAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> modDetuneAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> modAmtAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FmSynthAudioProcessorEditor)
};
