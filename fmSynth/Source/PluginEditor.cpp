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

    cutoffSlider.setSliderStyle(Slider::LinearBarVertical);
    cutoffSlider.setRange(0.1, 1000.0, 1.0);
    cutoffSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    cutoffSlider.setPopupDisplayEnabled(true, false, this);
    cutoffSlider.setValue(1.0);

    addAndMakeVisible(cutoffSlider);
    cutoffSlider.addListener(this);
}

FmSynthAudioProcessorEditor::~FmSynthAudioProcessorEditor()
{
}

void FmSynthAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    processor.filterCutoff = cutoffSlider.getValue();
}

//==============================================================================
void FmSynthAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);

    g.drawFittedText("Cutoff Freq", 110, 20, getWidth(), 30, Justification::centred, 1);
}

void FmSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    cutoffSlider.setBounds(300, 50, 20, 100);
}
