/*
  ==============================================================================

    OscData.h
    Created: 13 Mar 2023 3:21:29pm
    Author:  Zighi

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class OscData : public juce::dsp::Oscillator<float>
{
public:
    void prepareToPlay(juce::dsp::ProcessSpec& spec);
    void setWaveType(const int choice);
    void setWaveFrequency(const int midiNoteNumber);
    void getNextAudioBlock(juce::dsp::AudioBlock<float>& block);

private:
    
    int lastMidiNote{ 0 };
};

