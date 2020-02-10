<<<<<<< HEAD
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

<<<<<<< HEAD
        // these define the parameters of our slider object
    midiVolume.setSliderStyle (Slider::LinearBarVertical);
    midiVolume.setRange(0.0, 127.0, 1.0);
    midiVolume.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    midiVolume.setPopupDisplayEnabled (true, false, this);
    midiVolume.setTextValueSuffix (" Volume");
    midiVolume.setValue(1.0);
 
    // this function adds the slider to the editor
    addAndMakeVisible (&midiVolume);
    midiVolume.addListener(this);

}

void FmSynthAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    processor.noteOnVel = midiVolume.getValue();
=======
    cutoffSlider.setSliderStyle(Slider::LinearBarVertical);
    cutoffSlider.setRange(0.1, 1000.0, 1.0);
    cutoffSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    cutoffSlider.setPopupDisplayEnabled(true, false, this);
    cutoffSlider.setValue(1.0);

    addAndMakeVisible(cutoffSlider);
    cutoffSlider.addListener(this);
>>>>>>> 6c63939af4a695d4d1d8df3503ac15ca1888cc08
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
<<<<<<< HEAD
    g.drawFittedText ("Midi Volume",0,0, getWidth(),30, Justification::centred, 1);
=======

    g.drawFittedText("Cutoff Freq", 110, 20, getWidth(), 30, Justification::centred, 1);
>>>>>>> 6c63939af4a695d4d1d8df3503ac15ca1888cc08
}

void FmSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
<<<<<<< HEAD
    midiVolume.setBounds (40, 30, 20, getHeight() - 60);
=======
    cutoffSlider.setBounds(300, 50, 20, 100);
>>>>>>> 6c63939af4a695d4d1d8df3503ac15ca1888cc08
}
=======
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
    setSize (200, 200);
    
    //This defines the parameters of our slider object.
    gainSlider.setSliderStyle(Slider::LinearBarVertical);
    gainSlider.setRange(0.0f, 1.0f, 0.01f);
    gainSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    gainSlider.setPopupDisplayEnabled(true, false, this);
    gainSlider.setTextValueSuffix (" Volume");
    gainSlider.setValue(0.25);
    
    // this function adds the slider to the editor
    addAndMakeVisible (&gainSlider);
    
    //Add gainSlider listener.
    gainSlider.addListener(this);
    
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
    g.drawFittedText ("Volume Slider Test: SineWave", getLocalBounds(), Justification::centred, 1);
}

void FmSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    // sets the position and size of the slider with arguments (x, y, width, height)
    gainSlider.setBounds (40, 30, 20, getHeight() - 60);
}

void FmSynthAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    processor.gain = gainSlider.getValue();
}
>>>>>>> bea4b0889bf5cdafda43e64deeab48c4e81c0d8a
