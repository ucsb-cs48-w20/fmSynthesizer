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
    cutoffSlider.addListener(this);

    volumeSlider.setSliderStyle(Slider::LinearBarVertical);
    volumeSlider.setRange(0.1, 1000.0, 1.0);
    volumeSlider.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
    volumeSlider.setPopupDisplayEnabled(true, false, this);
    volumeSlider.setValue(1.0);

    addAndMakeVisible(volumeSlider);
    volumeSlider.addListener(this);

    dial1.setSliderStyle(Slider::Rotary);
    dial1.setTextBoxStyle(Slider::TextBoxBelow, true, 90, 25);

    addAndMakeVisible(dial1);
    dial1.addListener(this);

    addAndMakeVisible(carWaveSelect);

    carWaveSelect.addItem("Sine", 1);
    carWaveSelect.addItem("Square", 2);
    carWaveSelect.addItem("Saw", 3);

    carWaveSelect.onChange = [this] { WaveSelectChanged(); };
    //waveSelect.setSelectedId(1);

    addAndMakeVisible(modWaveSelect);

    modWaveSelect.addItem("Sine", 1);
    modWaveSelect.addItem("Square", 2);
    modWaveSelect.addItem("Saw", 3);

}

FmSynthAudioProcessorEditor::~FmSynthAudioProcessorEditor()
{
}

void FmSynthAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
}

void FmSynthAudioProcessorEditor::WaveSelectChanged() {
    switch (carWaveSelect.getSelectedId()) {
    case 1: processor.synth.addVoice<SineVoice, SineSound>(12); break;
    case 2: processor.synth.addVoice<SquareVoice, SquareSound>(12); break;
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
    g.drawFittedText("Modulator", 50, 20, getWidth(), 30, Justification::left, 1);
    g.drawFittedText("Carrier", 300, 20, getWidth(), 30, Justification::left, 1);
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
    dial1.setBounds(border, 250, dialWidth, dialHeight);
    modWaveSelect.setBounds(50, 70, 100, 20);
    carWaveSelect.setBounds(200, 70, 100, 20);
}
