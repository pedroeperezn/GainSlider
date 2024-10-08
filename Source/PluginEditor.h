/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainSliderAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    GainSliderAudioProcessorEditor (GainSliderAudioProcessor&);
    ~GainSliderAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    // Audio provessor
    GainSliderAudioProcessor& audioProcessor;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    juce::Slider gainSlider;
    // Responsible of linking the tree state with the current slider value.
    juce::AudioProcessorValueTreeState::SliderAttachment sliderTreeAttachment;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainSliderAudioProcessorEditor)
};
