/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainSliderAudioProcessorEditor::GainSliderAudioProcessorEditor (GainSliderAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    // Adding slider to the slider attachment. (tree state, parameter ID, slider)
    sliderTreeAttachment(audioProcessor.treeState, "gain", gainSlider)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 100);
    
    //Settup gain slide
    gainSlider.setSliderStyle(juce::Slider::LinearBar);
    gainSlider.setRange(-48, 0.0f, 0.01f);
    gainSlider.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    gainSlider.setPopupDisplayEnabled(true, false, this);
    gainSlider.setTextValueSuffix(" Gain");
    
    // Add gain slider
    addAndMakeVisible(&gainSlider);
}

GainSliderAudioProcessorEditor::~GainSliderAudioProcessorEditor()
{
}

//==============================================================================
void GainSliderAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::white);
    g.setColour (juce::Colours::black);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Gain Plug-In", 0, 0, getWidth(), 30, juce::Justification::centred, 1);
}

void GainSliderAudioProcessorEditor::resized()
{
    gainSlider.setBounds (20, 30, getWidth() - 40, 25);
}


