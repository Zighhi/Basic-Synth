/*
  ==============================================================================

    OscComponent.cpp
    Created: 13 Mar 2023 3:51:42pm
    Author:  Zighi

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId)
{
    juce::StringArray choices{ "Sine", "Saw", "Square","Triangle" };
    oscWaveSelector.addItemList(choices, 1);
    addAndMakeVisible(oscWaveSelector);


    oscWaveSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorId, oscWaveSelector);

    waveSelectorLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    waveSelectorLabel.setFont(20.0f);
    waveSelectorLabel.setJustificationType(juce::Justification::left);
    addAndMakeVisible(waveSelectorLabel);


}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
   

    g.fillAll(juce::Colours::cadetblue);
    g.setColour(juce::Colours::white);
    g.setFont(20.0f);
    g.drawText("Oscillator", 11.f, 0.f,100.f,10.f, juce::Justification::centred);
    g.drawRoundedRectangle(5.f,15.f,113.f,110.f, 5.0f, 2.0f);
}

void OscComponent::resized()
{
  
    oscWaveSelector.setBounds(15,70,90,30);
    waveSelectorLabel.setBounds(15,35,90,20);

}
using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;

void OscComponent::setSliderWithLabel(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& attachment)
{
    slider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(slider);

    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramId, slider);

    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setFont(150.0f);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}