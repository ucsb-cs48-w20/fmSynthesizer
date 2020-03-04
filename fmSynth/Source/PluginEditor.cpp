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
    octaveKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(octaveKnob);
    octAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, OCTAVE_ID, octaveKnob));
    
//    carrOctLabel.setFont(Font(16.0f));
//    carrOctLabel.setText("Octave", dontSendNotification);
//    carrOctLabel.setColour(Label::textColourId, Colours::white);
//    carrOctLabel.setJustificationType(Justification::centred);
//    carrOctLabel.attachToComponent(&octaveKnob, false);
//    addAndMakeVisible(carrOctLabel);

    modMultipleKnob.setSliderStyle(Slider::Rotary);
    modMultipleKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(modMultipleKnob);
    modMultipleAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_MULTIPLE_ID, modMultipleKnob));
    
//    modMultLabel.setFont(Font(16.0f));
//    modMultLabel.setText("Octave", dontSendNotification);
//    modMultLabel.setColour(Label::textColourId, Colours::white);
//    modMultLabel.setJustificationType(Justification::centred);
//    modMultLabel.attachToComponent(&modMultipleKnob, false);
//    addAndMakeVisible(modMultLabel);
    
    modDetuneKnob.setSliderStyle(Slider::Rotary);
    modDetuneKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(modDetuneKnob);
    modDetuneAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_DETUNE_ID, modDetuneKnob));
    
//    modDetLabel.setFont(Font(16.0f));
//    modDetLabel.setText("Detune", dontSendNotification);
//    modDetLabel.setColour(Label::textColourId, Colours::white);
//    modDetLabel.setJustificationType(Justification::centred);
//    modDetLabel.attachToComponent(&modDetuneKnob, false);
//    addAndMakeVisible(modDetLabel);

    modAmtKnob.setSliderStyle(Slider::Rotary);
    modAmtKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(modAmtKnob);
    modAmtAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_AMT_ID, modAmtKnob));
    
//    modAmtLabel.setFont(Font(16.0f));
//    modAmtLabel.setText("Amplitude", dontSendNotification);
//    modAmtLabel.setColour(Label::textColourId, Colours::white);
//    modAmtLabel.setJustificationType(Justification::centred);
//    modAmtLabel.attachToComponent(&modAmtKnob, false);
//    addAndMakeVisible(modAmtLabel);

    
    mod1MultipleKnob.setSliderStyle(Slider::Rotary);
    mod1MultipleKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(mod1MultipleKnob);
    mod1MultipleAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_MULTIPLE_1_ID, mod1MultipleKnob));
    
    mod1DetuneKnob.setSliderStyle(Slider::Rotary);
    mod1DetuneKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(mod1DetuneKnob);
    mod1DetuneAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_DETUNE_1_ID, mod1DetuneKnob));

    mod1AmtKnob.setSliderStyle(Slider::Rotary);
    mod1AmtKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(mod1AmtKnob);
    mod1AmtAttachment.reset(new AudioProcessorValueTreeState::SliderAttachment(valueTreeState, MOD_AMT_1_ID, mod1AmtKnob));
    
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
    
    mod1WaveSelect.addItem("Sine", 1);
    mod1WaveSelect.addItem("Square", 2);
    mod1WaveSelect.addItem("Saw", 3);
    mod1WaveSelect.addItem("Tri", 4);
    mod1WaveSelect.addItem("Noise", 5);
    addAndMakeVisible(mod1WaveSelect);
    mod1WaveAttachment.reset(new AudioProcessorValueTreeState::ComboBoxAttachment(valueTreeState, MOD_WAVE_1_ID, mod1WaveSelect));
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
    g.drawFittedText("Modulators", 85, 2, getWidth(), 30, Justification::left, 1);
    
    g.drawFittedText("Carrier", 290, 2, getWidth(), 30, Justification::left, 1);
    
    g.setFont (12.0f);
    g.drawFittedText("1", 75, 25, getWidth(), 30, Justification::left, 1);
    g.drawFittedText("2", 195, 25,  getWidth(), 30, Justification::left, 1);
    
    g.drawFittedText("Octave", 120, 85, getWidth(), 30, Justification::left, 1);
    g.drawFittedText("Detune", 120, 220,  getWidth(), 30, Justification::left, 1);
    g.drawFittedText("Amplitude", 111, 355,  getWidth(), 30, Justification::left, 1);

    g.setColour(Colours::grey);

    Line<float> line1(Point<float>(255, 0), Point<float>(255, getHeight()));
    g.drawLine(line1, 2.0f);

    Line<float> line2(Point<float>(375, 0), Point<float>(375, getHeight()));
    g.drawLine(line2, 2.0f);
}

void FmSynthAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..


    int left, spacing;
    left = 25;
    spacing = 120;
    
    
    mod1MultipleKnob.setBounds(left, 100, 100, 100);
    mod1DetuneKnob.setBounds(left, 235, 100, 100);
    mod1AmtKnob.setBounds(left, 370, 100, 100);
    mod1WaveSelect.setBounds(left, 50, 100, 20);
    
    left+= spacing;
    
    modMultipleKnob.setBounds(left, 100, 100, 100);
    modDetuneKnob.setBounds(left, 235, 100, 100);
    modAmtKnob.setBounds   (left, 370, 100, 100);
    modWaveSelect.setBounds(left, 50, 100, 20);
    
    left+= spacing;
    
    
    octaveKnob.setBounds(left, 100, 100, 100);
    carWaveSelect.setBounds(left, 50, 100, 20);
    
    left+= spacing;
    left+= 25;

    cutoffSlider.setBounds(left, 50, 30, 300);
    
    left+= 75;
    
    gainSlider.setBounds(left, 50, 30, 300);
    
    
}
