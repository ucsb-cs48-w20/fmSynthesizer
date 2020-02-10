<<<<<<< HEAD
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
<<<<<<< HEAD
class FmSynthAudioProcessorEditor  : public AudioProcessorEditor, private Slider::Listener
=======
class FmSynthAudioProcessorEditor  : public AudioProcessorEditor,
                                     private Slider::Listener
>>>>>>> 6c63939af4a695d4d1d8df3503ac15ca1888cc08
{
public:
    FmSynthAudioProcessorEditor (FmSynthAudioProcessor&);
    ~FmSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
<<<<<<< HEAD

    void sliderValueChanged (Slider* slider) override;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FmSynthAudioProcessor& processor;
    Slider midiVolume;
=======
    void FmSynthAudioProcessorEditor::sliderValueChanged(Slider* slider);


    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FmSynthAudioProcessor& processor;
    Slider cutoffSlider;
>>>>>>> 6c63939af4a695d4d1d8df3503ac15ca1888cc08
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FmSynthAudioProcessorEditor)
};
=======
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
class FmSynthAudioProcessorEditor  : public AudioProcessorEditor,
                                     private Slider::Listener
{
public:
    FmSynthAudioProcessorEditor (FmSynthAudioProcessor&);
    ~FmSynthAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:

    void sliderValueChanged (Slider* slider) override;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FmSynthAudioProcessor& processor;
    
    Slider gainSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FmSynthAudioProcessorEditor)
};
>>>>>>> bea4b0889bf5cdafda43e64deeab48c4e81c0d8a
