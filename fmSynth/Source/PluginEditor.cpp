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

    setSize (700, 400);

    cutoffSlider.setSliderStyle(Slider::LinearBarVertical);
    cutoffSlider.setRange(0.1, 1000.0, 1.0);
    cutoffSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    cutoffSlider.setPopupDisplayEnabled(true, false, this);
    cutoffSlider.setValue(1.0);
    addAndMakeVisible(cutoffSlider);
    cutoffSlider.addListener(this); // If preferred, statements like these can be replaced with callbacks like how carWaveSelect is done

    volumeSlider.setSliderStyle(Slider::LinearBarVertical);
    volumeSlider.setRange(0.1, 1000.0, 1.0);
    volumeSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    volumeSlider.setPopupDisplayEnabled(true, false, this);
    volumeSlider.setValue(1.0);
    addAndMakeVisible(volumeSlider);
    volumeSlider.addListener(this);

    octaveKnob.setSliderStyle(Slider::Rotary);
    octaveKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 90, 25);
    octaveKnob.setRange(2, 18, 2);
    octaveKnob.setValue(10);
    addAndMakeVisible(octaveKnob);
    octaveKnob.addListener(this);

    cmRatioKnob.setSliderStyle(Slider::Rotary);
    cmRatioKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 90, 25);
    cmRatioKnob.setRange(0, 1, 0.01);
    cmRatioKnob.setValue(0.5);
    addAndMakeVisible(cmRatioKnob);
    cmRatioKnob.addListener(this);

    modAmtKnob.setSliderStyle(Slider::Rotary);
    modAmtKnob.setTextBoxStyle(Slider::TextBoxBelow, true, 90, 25);
    modAmtKnob.setRange(0, 1, 0.01);
    modAmtKnob.setValue(0.5);
    addAndMakeVisible(modAmtKnob);
    modAmtKnob.addListener(this);

    addAndMakeVisible(carWaveSelect);
    carWaveSelect.addItem("Sine", 1);
    carWaveSelect.addItem("Square", 2);
    carWaveSelect.addItem("Saw", 3);
    carWaveSelect.onChange = [this] { WaveSelectChanged(); };
    carWaveSelect.setSelectedId(1);

    addAndMakeVisible(modWaveSelect);
    modWaveSelect.addItem("Sine", 1);
    modWaveSelect.addItem("Square", 2);
    modWaveSelect.addItem("Saw", 3);
    modWaveSelect.setSelectedId(1);

}

FmSynthAudioProcessorEditor::~FmSynthAudioProcessorEditor()
{
}

void FmSynthAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
}

void FmSynthAudioProcessorEditor::WaveSelectChanged() {
    processor.synth.clearVoices();
    processor.synth.clearSounds();
    switch (carWaveSelect.getSelectedId()) {
    case 1: processor.synth.addVoice<SineVoice, SineSound>(12); break;
    case 2: processor.synth.addVoice<SquareVoice, SquareSound>(12); break;
    case 3: processor.synth.addVoice<SawVoice, SawSound>(12); break;
    }
}

//==============================================================================
void FmSynthAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (18.0f);

    g.drawFittedText("Filter Cutoff", 480, 20, getWidth(), 30, Justification::left, 1);
    g.drawFittedText("Volume", 600, 20, getWidth(), 30, Justification::left, 1);
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
    const int border = 20;
    const int dialWidth = getWidth() / 1.7 - border;
    const int dialHeight = getHeight() / 1.7 - border - 100;

    cutoffSlider.setBounds(520, 50, 20, 300);
    volumeSlider.setBounds(620, 50, 20, 300);
    octaveKnob.setBounds(140, 130, dialWidth, dialHeight);
    cmRatioKnob.setBounds(-100, 130, dialWidth, dialHeight);
    modAmtKnob.setBounds(-80, 260, dialWidth-30, dialHeight-30);
    modWaveSelect.setBounds(50, 50, 100, 20);
    carWaveSelect.setBounds(280, 50, 100, 20);
}
