/*
  ==============================================================================

    SynthVoice.h
    Created: 13 Mar 2023 3:20:08pm
    Author:  Zighi

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "Data/OscData.h"
#include "Data/AdsrData.h"


class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override;

    OscData& getOscillator() { return osc; }
    AdsrData& getAdsr() { return adsr; }

private:
    juce::AudioBuffer<float> synthBuffer;
    OscData osc;
    AdsrData adsr;
    juce::dsp::Gain<float> gain;

    bool isPrepared{ false };
};