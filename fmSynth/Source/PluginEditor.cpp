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
    setSize (700, 600);

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
    octaveKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(octaveKnob);
    octAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, OCTAVE_ID, octaveKnob));

    carrOctLabel.setFont(Font(16.0f));
    carrOctLabel.setText("Octave", dontSendNotification);
    carrOctLabel.setColour(Label::textColourId, Colours::white);
    carrOctLabel.setJustificationType(Justification::centred);
    carrOctLabel.attachToComponent(&octaveKnob, false);
    addAndMakeVisible(carrOctLabel);


    modMultipleKnob.setSliderStyle(Slider::Rotary);
    modMultipleKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(modMultipleKnob);
    modMultipleAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_MULTIPLE_ID, modMultipleKnob));


    modMultLabel.setFont(Font(16.0f));
    modMultLabel.setText("Octave", dontSendNotification);
    modMultLabel.setColour(Label::textColourId, Colours::white);
    modMultLabel.setJustificationType(Justification::centred);
    modMultLabel.attachToComponent(&modMultipleKnob, false);
    addAndMakeVisible(modMultLabel);
    
    modDetuneKnob.setSliderStyle(Slider::Rotary);
    modDetuneKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(modDetuneKnob);
    modDetuneAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_DETUNE_ID, modDetuneKnob));

    modDetLabel.setFont(Font(16.0f));
    modDetLabel.setText("Detune", dontSendNotification);
    modDetLabel.setColour(Label::textColourId, Colours::white);
    modDetLabel.setJustificationType(Justification::centred);
    modDetLabel.attachToComponent(&modDetuneKnob, false);
    addAndMakeVisible(modDetLabel);

    modAmtKnob.setSliderStyle(Slider::Rotary);
    modAmtKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(modAmtKnob);
    modAmtAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_AMT_ID, modAmtKnob));

    modAmtLabel.setFont(Font(16.0f));
    modAmtLabel.setText("Amplitude", dontSendNotification);
    modAmtLabel.setColour(Label::textColourId, Colours::white);
    modAmtLabel.setJustificationType(Justification::centred);
    modAmtLabel.attachToComponent(&modAmtKnob, false);
    addAndMakeVisible(modAmtLabel);

    carWaveSelect.addItem("Sine", 1);
    carWaveSelect.addItem("Square", 2);
    carWaveSelect.addItem("Saw", 3);
    carWaveSelect.addItem("Tri", 4);
    carWaveSelect.addItem("Noise", 5);
    addAndMakeVisible(carWaveSelect);
    carWaveAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(valueTreeState, CARRIER_WAVE_ID, carWaveSelect));

    modWaveSelect.addItem("Sine", 1);
    modWaveSelect.addItem("Square", 2);
    modWaveSelect.addItem("Saw", 3);
    modWaveSelect.addItem("Tri", 4);
    modWaveSelect.addItem("Noise", 5);
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
    octaveKnob.setBounds(275, 100, 100, 100);
    modMultipleKnob.setBounds(50, 100, 100, 100);
    modDetuneKnob.setBounds(50, 235, 100, 100);
    modAmtKnob.setBounds(50, 370, 100, 100);
    modWaveSelect.setBounds(50, 50, 100, 20);
    carWaveSelect.setBounds(280, 50, 100, 20);
}
