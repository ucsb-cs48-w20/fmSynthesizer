<<<<<<< HEAD
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FmSynthAudioProcessor::FmSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

FmSynthAudioProcessor::~FmSynthAudioProcessor()
{
}

//==============================================================================
const String FmSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FmSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FmSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FmSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FmSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FmSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FmSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FmSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String FmSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void FmSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void FmSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    this->sampleRate = sampleRate;
}

void FmSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FmSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void FmSynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
//     ScopedNoDenormals noDenormals;
//     auto totalNumInputChannels  = getTotalNumInputChannels();
//     auto totalNumOutputChannels = getTotalNumOutputChannels();

//     // In case we have more outputs than inputs, this code clears any output
//     // channels that didn't contain input data, (because these aren't
//     // guaranteed to be empty - they may contain garbage).
//     // This is here to avoid people getting screaming feedback
//     // when they first compile a plugin, but obviously you don't need to keep
//     // this code if your algorithm always overwrites all the output channels.
//     for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
//         buffer.clear (i, 0, buffer.getNumSamples());

//     // This is the place where you'd normally do the guts of your plugin's
//     // audio processing...
//     // Make sure to reset the state if your inner loop is processing
//     // the samples and the outer loop is handling the channels.
//     // Alternatively, you can process the samples with the channels
//     // interleaved by keeping the same state.
//     for (int channel = 0; channel < totalNumInputChannels; ++channel)
//     {
//         auto* channelData = buffer.getWritePointer (channel);

//         // ..do something to the data...
//     }
 buffer.clear();
 
    MidiBuffer processedMidi;
    int time;
    MidiMessage m;
 
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
    {
        if (m.isNoteOn())
        {
            uint8 newVel = (uint8)noteOnVel;
            m = MidiMessage::noteOn(m.getChannel(), m.getNoteNumber(), newVel);
        }
        else if (m.isNoteOff())
        {
        }
        else if (m.isAftertouch())
        {
        }
        else if (m.isPitchWheel())
        {
        }
 
        processedMidi.addEvent (m, time);
    }
 
    midiMessages.swapWith (processedMidi);
}

//==============================================================================
bool FmSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* FmSynthAudioProcessor::createEditor()
{
    return new FmSynthAudioProcessorEditor (*this);
}

//==============================================================================
void FmSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FmSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FmSynthAudioProcessor();
=======
/*
  ==============================================================================
    This file was auto-generated!
    It contains the basic framework code for a JUCE plugin processor.
  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FmSynthAudioProcessor::FmSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

FmSynthAudioProcessor::~FmSynthAudioProcessor()
{
}

//==============================================================================
const String FmSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FmSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FmSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FmSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FmSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FmSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FmSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FmSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String FmSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void FmSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void FmSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    sine.initialize(sampleRate,440,512);
}

void FmSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FmSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void FmSynthAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    
    buffer.clear();
    
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    for(auto i = totalNumInputChannels; i < totalNumOutputChannels; i++ )
        buffer.clear(i, 0, buffer.getNumSamples());
    
    for(int channel = 0; channel < totalNumOutputChannels; channel++)
    {
        auto* channelData = buffer.getWritePointer(channel);
        
       
        
        for(auto sample = 0; sample < buffer.getNumSamples(); ++sample)
        {
            *channelData++ = sine.processAudio() * gain;
//            *channelData++ = (random.nextFloat() * 2.0f - 1.0f) * gain;
        }
    }
        

    MidiBuffer processedMidi;
    int time;
    MidiMessage m;
    for(MidiBuffer::Iterator i (midiMessages); i.getNextEvent(m,time);)
    {
        if(m.isNoteOn()) {
            uint8 newVel = (uint8)noteOnVel;
            m = MidiMessage::noteOn(m.getChannel(),m.getNoteNumber(),newVel);
        }
        else if (m.isNoteOff()) {
            
        }
        else if (m.isAftertouch()) {
            
        }
        else if (m.isPitchWheel()) {
            
        }
        else {
            
        }
        
        processedMidi.addEvent(m, time);
    }
    
    midiMessages.swapWith (processedMidi);
    
}

//==============================================================================
bool FmSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* FmSynthAudioProcessor::createEditor()
{
    return new FmSynthAudioProcessorEditor (*this);
}

//==============================================================================
void FmSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FmSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FmSynthAudioProcessor();
>>>>>>> bea4b0889bf5cdafda43e64deeab48c4e81c0d8a
}
