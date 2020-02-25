/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FmSynthAudioProcessorEditor::FmSynthAudioProcessorEditor (FmSynthAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState(vts)
{
    setSize (700, 500);

    cutoffSlider.setSliderStyle(Slider::LinearBarVertical);
    cutoffSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    cutoffSlider.setPopupDisplayEnabled(true, false, this);
    addAndMakeVisible(cutoffSlider);
    cutoffAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, FILTER_CUTOFF_ID, cutoffSlider));

    gainSlider.setSliderStyle(Slider::LinearBarVertical);
    gainSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    gainSlider.setPopupDisplayEnabled(true, false, this);
    addAndMakeVisible(gainSlider);
    gainAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, GAIN_ID, gainSlider));

    octaveKnob.setSliderStyle(Slider::Rotary);
    octaveKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 90, 25);
    addAndMakeVisible(octaveKnob);
    octAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, OCTAVE_ID, octaveKnob));

    modMultipleKnob.setSliderStyle(Slider::Rotary);
    modMultipleKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 90, 25);
    addAndMakeVisible(modMultipleKnob);
    modMultipleAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_MULTIPLE_ID, modMultipleKnob));
    
    modDetuneKnob.setSliderStyle(Slider::Rotary);
    modDetuneKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 90, 25);
    addAndMakeVisible(modDetuneKnob);
    modMultipleAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_DETUNE_ID, modDetuneKnob));

    modAmtKnob.setSliderStyle(Slider::Rotary);
    modAmtKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 90, 25);
    addAndMakeVisible(modAmtKnob);
    modAmtAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_AMT_ID, modAmtKnob));

    carWaveSelect.addItem("Sine", 1);
    carWaveSelect.addItem("Square", 2);
    carWaveSelect.addItem("Saw", 3);
    addAndMakeVisible(carWaveSelect);
    carWaveAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(valueTreeState, CARRIER_WAVE_ID, carWaveSelect));

    modWaveSelect.addItem("Sine", 1);
    modWaveSelect.addItem("Square", 2);
    modWaveSelect.addItem("Saw", 3);
    addAndMakeVisible(modWaveSelect);
    modWaveAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(valueTreeState, MOD_WAVE_ID, modWaveSelect));
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
    g.setFont (18.0f);

    g.drawFittedText("Filter Cutoff", 480, 20, getWidth(), 30, Justification::left, 1);
    g.drawFittedText("Gain", 610, 20, getWidth(), 30, Justification::left, 1);
    g.drawFittedText("Modulator", 60, 20, getWidth(), 30, Justification::left, 1);
    g.drawFittedText("Carrier", 305, 20, getWidth(), 30, Justification::left, 1);

    g.setColour(Colours::grey);

    Line<float> line1(Point<float>(220, 0), Point<float>(220, 400));
    g.drawLine(line1, 2.0f);

    Line<float> line2(Point<float>(440, 0), Point<float>(440, 400));
    g.drawLine(line2, 2.0f);
}

void FmSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    cutoffSlider.setBounds(520, 50, 20, 300);
    gainSlider.setBounds(620, 50, 20, 300);
    octaveKnob.setBounds(275, 130, 120, 120);
    modMultipleKnob.setBounds(50, 70, 120, 120);
    modDetuneKnob.setBounds(50, 210, 120, 120);
    modAmtKnob.setBounds(50, 330, 120, 120);
    modWaveSelect.setBounds(50, 50, 100, 20);
    carWaveSelect.setBounds(280, 50, 100, 20);
}
