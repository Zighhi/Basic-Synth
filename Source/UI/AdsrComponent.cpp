/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 13 Mar 2023 3:51:55pm
    Author:  Zighi

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent(juce::String name, juce::AudioProcessorValueTreeState& apvts, juce::String attackId, juce::String decayId, juce::String sustainId, juce::String releaseId)
{
    componentName = name;

    setSliderWithLabel(attackSlider, attackLabel, apvts, attackId, attackAttachment);
    setSliderWithLabel(decaySlider, decayLabel, apvts, decayId, decayAttachment);
    setSliderWithLabel(sustainSlider, sustainLabel, apvts, sustainId, sustainAttachment);
    setSliderWithLabel(releaseSlider, releaseLabel, apvts, releaseId, releaseAttachment); 

}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::paint (juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced(5);
    auto labelSpace = bounds.removeFromTop(25.0f);

    g.fillAll(juce::Colours::cadetblue);
    g.setColour(juce::Colours::white);
    g.setFont(20.0f);
    g.drawText(componentName, 45.f, 0.f, 200.f, 10.f, juce::Justification::centred);
    g.drawRoundedRectangle(5.f, 15.f, 280.f, 110.f, 5.0f, 2.0f);
}

void AdsrComponent::resized()
{
    const auto bounds = getLocalBounds().reduced(10);
    const auto padding = 5;
    const auto sliderWidth = bounds.getWidth() / 4 - padding;
    const auto sliderHeight = bounds.getHeight() - 85;
    const auto sliderStartX = 8;
    const auto sliderStartY = 25;
    const auto labelYOffset = 10;
    const auto labelHeight = 20;
    const auto labelStart = sliderStartY - labelYOffset;

    attackSlider.setBounds(sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    attackLabel.setBounds(attackSlider.getX(), labelStart, sliderWidth, labelHeight);

    decaySlider.setBounds(attackSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    decayLabel.setBounds(decaySlider.getX(), labelStart, sliderWidth, labelHeight);

    sustainSlider.setBounds(decaySlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    sustainLabel.setBounds(sustainSlider.getX(), labelStart, sliderWidth, labelHeight);

    releaseSlider.setBounds(sustainSlider.getRight() + padding, sliderStartY, sliderWidth, sliderHeight);
    releaseLabel.setBounds(releaseSlider.getX(), labelStart, sliderWidth, labelHeight);


}
using Attachment = juce::AudioProcessorValueTreeState::SliderAttachment;

void AdsrComponent::setSliderWithLabel(juce::Slider& slider, juce::Label& label, juce::AudioProcessorValueTreeState& apvts, juce::String paramId, std::unique_ptr<Attachment>& attachment)
{

    slider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    slider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 40, 20);
    slider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::white);
    addAndMakeVisible(slider);

    attachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, paramId, slider);

    label.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    label.setFont(15.0f);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);

}