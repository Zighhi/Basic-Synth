/*
  ==============================================================================

    AdsrData.h
    Created: 13 Mar 2023 3:21:42pm
    Author:  Zighi

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class AdsrData : public juce::ADSR
{
public:

    void updateADSR(const float attack, const float decay, const float sustain, const float release);

private:

    juce::ADSR::Parameters adsrParams;
};