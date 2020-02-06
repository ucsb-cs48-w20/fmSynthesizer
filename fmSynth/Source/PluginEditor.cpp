/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FmSynthAudioProcessorEditor::FmSynthAudioProcessorEditor (FmSynthAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    volumeSlider.setSliderStyle(Slider::Rotary);
    volumeSlider.setRange(0.0, 127.0, 1.0);
    volumeSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    volumeSlider.setPopupDisplayEnabled(true, false, this);
    volumeSlider.setTextValueSuffix(" Volume");
    volumeSlider.setValue(1.0);

    addAndMakeVisible(&volumeSlider);

    //add the listener to the slider
    volumeSlider.addListener(this);

    volumeSlider.setLookAndFeel(&myLook);
}

void FmSynthAudioProcessorEditor::sliderValueChanged(Slider* slider) {
    processor.noteOnVel = volumeSlider.getValue();
}
FmSynthAudioProcessorEditor::~FmSynthAudioProcessorEditor()
{
}

//==============================================================================
void FmSynthAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Knob time", getLocalBounds(), Justification::centred, 1);
}

void FmSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    auto border = 4;

    auto area = getLocalBounds();

    auto dialArea = area.removeFromTop(area.getHeight() / 2);
    volumeSlider.setBounds(dialArea.removeFromLeft(dialArea.getWidth() / 2).reduced(border));
}
