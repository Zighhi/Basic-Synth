/*
  ==============================================================================

    SynthSound.h
    Created: 13 Mar 2023 3:20:33pm
    Author:  Zighi

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
public:
    bool appliesToNote(int midiNoteNumber) override { return true; }
    bool appliesToChannel(int midiChannel) override { return true; }



};