/*
  ==============================================================================

    OscData.cpp
    Created: 13 Mar 2023 3:21:29pm
    Author:  Zighi

  ==============================================================================
*/

#include "OscData.h"

void OscData::prepareToPlay(juce::dsp::ProcessSpec& spec)
{
    prepare(spec);
}

void OscData::setWaveType(const int choice)
{
    switch (choice)
    {
    case 0:
        initialise([](float x) { return std::sin(x); });
        break;

    case 1:
        initialise([](float x) { return x / juce::MathConstants<float>::pi; });
        break;

    case 2:
        initialise([](float x) { return x < 0.0f ? -1.0f : 1.0f; });
        break;
    case 3:
        initialise([](float x) { return x >= 0.0f ? 0.8f * x - 0.75f : -0.8f * x - 0.75f; });
        break;
    default:
        jassertfalse;
        break;
    }
}



void OscData::setWaveFrequency(const int midiNoteNumber)
{

    setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    lastMidiNote = midiNoteNumber;

}

void OscData::getNextAudioBlock(juce::dsp::AudioBlock<float>& block)
{

    process(juce::dsp::ProcessContextReplacing<float>(block));

}


