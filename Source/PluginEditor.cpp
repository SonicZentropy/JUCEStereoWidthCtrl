/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0 

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/
#include "PluginEditor.h"
#include <exception>

using namespace juce;

//==============================================================================
StereoWidthCtrlAudioProcessorEditor::StereoWidthCtrlAudioProcessorEditor(StereoWidthCtrlAudioProcessor& ownerFilter)
	: AudioProcessorEditor(ownerFilter), processor(&ownerFilter)
{
	//Audio Processor reference
	StereoWidthCtrlAudioProcessor* audioProc = getProcessor();
		
	addAndMakeVisible(stereoWidthSldCtrl = new StereoWidthCtrlSlider("Width Factor Slider", audioProc->stereoWidthParam, "%"));
	stereoWidthSldCtrl->setTooltip(TRANS("Stereo Width"));
	stereoWidthSldCtrl->setRange(0, 1, 0.005);
	stereoWidthSldCtrl->setSliderStyle(Slider::Rotary);
	stereoWidthSldCtrl->setTextBoxStyle(Slider::TextBoxLeft, false, 50, 20);
	stereoWidthSldCtrl->setColour(Slider::backgroundColourId, Colours::blue);
	stereoWidthSldCtrl->setColour(Slider::thumbColourId, Colours::black);
	stereoWidthSldCtrl->setColour(Slider::trackColourId, Colours::black);
	stereoWidthSldCtrl->setColour(Slider::rotarySliderFillColourId, Colours::black);
	stereoWidthSldCtrl->setColour(Slider::rotarySliderOutlineColourId, Colours::black);
	stereoWidthSldCtrl->setColour(Slider::textBoxBackgroundColourId, Colour(0xffb2b2ff));
	stereoWidthSldCtrl->setColour(Slider::textBoxHighlightColourId, Colour(0x40ffffff));
	stereoWidthSldCtrl->addListener(this);
	
	addAndMakeVisible(gainSldCtrl = new GainCtrlSlider("Gain Knob", audioProc->audioGainParam, "dB", 12.0));
	gainSldCtrl->setRange(0.0, 1.0, 0.0);
	gainSldCtrl->setSkewFactor(0.4f);
	gainSldCtrl->setSliderStyle(Slider::LinearVertical);
	gainSldCtrl->setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	gainSldCtrl->setColour(Slider::backgroundColourId, Colour(0x00868181));
	gainSldCtrl->setColour(Slider::trackColourId, Colour(0x7fffffff));
	gainSldCtrl->setColour(Slider::rotarySliderFillColourId, Colour(0x7fbcbcff));
	gainSldCtrl->setColour(Slider::rotarySliderOutlineColourId, Colour(0x66ffffff));
	gainSldCtrl->setColour(Slider::textBoxBackgroundColourId, Colour(0xffb2b2ff));
	gainSldCtrl->addListener(this);
	
	addAndMakeVisible(bypassBtnCtrl = new TextButton("Bypass Button"));
	bypassBtnCtrl->setButtonText(TRANS("Bypass"));
	bypassBtnCtrl->addListener(this);
	bypassBtnCtrl->setColour(TextButton::buttonColourId, Colour(0xffe2e2e2));

	addAndMakeVisible(widthLabel = new Label("Width Label", TRANS("S. Width:")));
	widthLabel->setFont(Font(10.00f, Font::bold));
	widthLabel->setJustificationType(Justification::centred);
	widthLabel->setEditable(false, false, false);
	widthLabel->setColour(Label::textColourId, Colours::grey);
	widthLabel->setColour(TextEditor::textColourId, Colours::black);
	widthLabel->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	addAndMakeVisible(muteBtnCtrl = new TextButton("Mute Button"));
	muteBtnCtrl->setButtonText(TRANS("Mute"));
	muteBtnCtrl->addListener(this);
	muteBtnCtrl->setColour(TextButton::buttonColourId, Colour(0xffe2e2e2));

	addAndMakeVisible(lockGainBtnCtrl = new TextButton("Lock Gain"));
	lockGainBtnCtrl->setButtonText(TRANS("Lock Gain to 0db"));
	lockGainBtnCtrl->addListener(this);
	lockGainBtnCtrl->setColour(TextButton::buttonColourId, Colour(0xffe2e2e2));

	addAndMakeVisible(invertLeftBtnCtrl = new ToggleButton("Invert Left"));
	invertLeftBtnCtrl->setTooltip(TRANS("Phase invert Left Channel"));
	invertLeftBtnCtrl->setButtonText(String::empty);
	invertLeftBtnCtrl->addListener(this);

	addAndMakeVisible(invertRightBtnCtrl = new ToggleButton("Invert Right"));
	invertRightBtnCtrl->setTooltip(TRANS("Phase invert Right Channel"));
	invertRightBtnCtrl->setButtonText(String::empty);
	invertRightBtnCtrl->addListener(this);
	invertRightBtnCtrl->setColour(ToggleButton::textColourId, Colour(0xffb2b2ff));

	addAndMakeVisible(invertLabel = new Label("Invert Label",
		TRANS("Invert:\n"
			"L       R")));
	invertLabel->setFont(Font(10.00f, Font::bold));
	invertLabel->setJustificationType(Justification::centredBottom);
	invertLabel->setEditable(false, false, false);
	invertLabel->setColour(Label::textColourId, Colours::grey);
	invertLabel->setColour(TextEditor::textColourId, Colours::black);
	invertLabel->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	addAndMakeVisible(gainLabel = new Label("Gain Label",
		"Gain:"));
	gainLabel->setFont(Font(10.00f, Font::bold));
	gainLabel->setJustificationType(Justification::centredBottom);
	gainLabel->setEditable(false, false, false);
	gainLabel->setColour(Label::textColourId, Colours::grey);
	gainLabel->setColour(TextEditor::textColourId, Colours::black);
	gainLabel->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	addAndMakeVisible(stereoPanSldCtrl = new PanSlider("Pan", audioProc->stereoPanParam));
	stereoPanSldCtrl->setRange(-100, 100, 1);
	stereoPanSldCtrl->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	stereoPanSldCtrl->setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	stereoPanSldCtrl->setColour(Slider::rotarySliderFillColourId, Colour(0x7f8080ff));
	stereoPanSldCtrl->setColour(Slider::rotarySliderOutlineColourId, Colour(0x66ffffff));
	stereoPanSldCtrl->setColour(Slider::textBoxBackgroundColourId, Colour(0xffb2b2ff));
	stereoPanSldCtrl->setValue(0.0f, dontSendNotification);
	stereoPanSldCtrl->addListener(this);
	

	//Set default double click reset values

	gainSldCtrl->setDoubleClickReturnValue(true, gainSldCtrl->getAssociatedParameter()->getDefaultValue());
	stereoWidthSldCtrl->setDoubleClickReturnValue(true, stereoWidthSldCtrl->getAssociatedParameter()->getDefaultValue());
	stereoPanSldCtrl->setDoubleClickReturnValue(true, 0.0f);

	// GUI Size 
	setSize(118, 164);

	getProcessor()->RequestUIUpdate(); //UI Update must be performed every time a new editor is constructed
	startTimer(20); // Start timer poll with 20ms 

	bypassBtnCtrl->setClickingTogglesState(true);
	muteBtnCtrl->setClickingTogglesState(true);
	lockGainBtnCtrl->setClickingTogglesState(true);
	invertLeftBtnCtrl->setClickingTogglesState(true);
	invertRightBtnCtrl->setClickingTogglesState(true);
	gainSldCtrl->setAssociatedParameter(getProcessor()->audioGainParam); //WRONG
	

}

///
StereoWidthCtrlAudioProcessorEditor::~StereoWidthCtrlAudioProcessorEditor()
{
	stereoWidthSldCtrl = nullptr;
	bypassBtnCtrl = nullptr;
	widthLabel = nullptr;
	muteBtnCtrl = nullptr;
	gainSldCtrl = nullptr;
	lockGainBtnCtrl = nullptr;
	invertLeftBtnCtrl = nullptr;
	invertRightBtnCtrl = nullptr;
	invertLabel = nullptr;
	gainLabel = nullptr;
	stereoPanSldCtrl = nullptr;	
}

//==============================================================================
void StereoWidthCtrlAudioProcessorEditor::paint(Graphics& g)
{
	g.fillAll(Colours::black);
}

void StereoWidthCtrlAudioProcessorEditor::resized()
{
	//MainTab
	stereoWidthSldCtrl->setBounds(53, 0, 69, 30);
	bypassBtnCtrl->setBounds(3, 145, 112, 16);
	widthLabel->setBounds(6, 0, 42, 24);
	muteBtnCtrl->setBounds(3, 124, 30, 16);
	gainSldCtrl->setBounds(64, 49, 50, 69);
	lockGainBtnCtrl->setBounds(33, 124, 82, 16);
	invertLeftBtnCtrl->setBounds(8, 48, 24, 20);
	invertRightBtnCtrl->setBounds(33, 48, 24, 20);
	invertLabel->setBounds(8, 30, 44, 20);
	gainLabel->setBounds(63, 32, 39, 14);
	stereoPanSldCtrl->setBounds(3, 74, 56, 44);	
}

/// <summary> Called by JUCE when slider is moved.  Casts slider as Associated and passes to associatedSliderValueChanged</summary>
/// <param name="sliderThatWasMoved"> The slider that was moved.</param>
void StereoWidthCtrlAudioProcessorEditor::sliderValueChanged(Slider* sliderThatWasMoved)
{
	AudioProcessorParameter* param = static_cast<AssociatedSlider*>(sliderThatWasMoved)->getAssociatedParameter();
	if (sliderThatWasMoved == stereoWidthSldCtrl)
	{
		param->setValueNotifyingHost(static_cast<float>(stereoWidthSldCtrl->getValue()));
	} 
	else if (sliderThatWasMoved == gainSldCtrl)
	{   
		param->setValueNotifyingHost(static_cast<float>(gainSldCtrl->getValue()));
	}
	else if (sliderThatWasMoved == stereoPanSldCtrl)
	{
		param->setValueNotifyingHost(stereoPanSldCtrl->getLinearNormalizedValue());			
	}
}



void StereoWidthCtrlAudioProcessorEditor::buttonClicked(Button* buttonThatWasClicked)
{
	StereoWidthCtrlAudioProcessor* audioProc = getProcessor();

	if (buttonThatWasClicked == bypassBtnCtrl)
	{
		DBG("Bypass clicked");
	 	if (AudioProcessorParameter* param = audioProc->masterBypassParam)
	 	{
	 		param->setValueNotifyingHost(bypassBtnCtrl->getToggleState());
	 	}
	}
	else if (buttonThatWasClicked == muteBtnCtrl)
	{
		DBG("Mute button clicked");
		if (AudioProcessorParameter* param = audioProc->muteAudioParam)
		{
			param->setValueNotifyingHost(muteBtnCtrl->getToggleState());
		}
	}
	else if (buttonThatWasClicked == lockGainBtnCtrl)
	{		
	 	if (AudioProcessorParameter* lockParam = audioProc->lockGainParam)
	 	{
			lockParam->setValueNotifyingHost(buttonThatWasClicked->getToggleState());
	 	}
	}
	else if (buttonThatWasClicked == invertLeftBtnCtrl)
	{
		if (AudioProcessorParameter* param = audioProc->invertLeftParam)
		{
			param->setValueNotifyingHost(static_cast<float>(invertLeftBtnCtrl->getToggleStateValue().getValue()));
		}
	} else if (buttonThatWasClicked == invertRightBtnCtrl)
	{
		if (AudioProcessorParameter* param = audioProc->invertRightParam)
		{
			param->setValueNotifyingHost(static_cast<float>(invertRightBtnCtrl->getToggleStateValue().getValue()));
		}
	} 

}

/// <summary>This method is called automatically every 200ms to update GUI if required</summary>
void StereoWidthCtrlAudioProcessorEditor::timerCallback()
{
	StereoWidthCtrlAudioProcessor* ourProcessor = getProcessor();
	//exchange data between UI Elements and the Plugin (ourProcessor)

	if (ourProcessor->muteAudioParam->needsUIUpdate())
		muteBtnCtrl->setToggleState(0.0f != ourProcessor->muteAudioParam->getValue(), dontSendNotification);
	if (ourProcessor->masterBypassParam->needsUIUpdate())
		bypassBtnCtrl->setToggleState(0.0f != ourProcessor->masterBypassParam->getValue(), dontSendNotification);
	if (ourProcessor->lockGainParam->needsUIUpdate()) 
		lockGainBtnCtrl->setToggleState(0.0f != ourProcessor->lockGainParam->getValue(), dontSendNotification);
	if (ourProcessor->invertLeftParam->needsUIUpdate()) 
		invertLeftBtnCtrl->setToggleState(0.0f != ourProcessor->invertLeftParam->getValue(), dontSendNotification);
	if (ourProcessor->invertRightParam->needsUIUpdate()) 
		invertRightBtnCtrl->setToggleState(0.0f != ourProcessor->invertRightParam->getValue(), dontSendNotification);

		
	if (ourProcessor->stereoWidthParam->needsUIUpdate())	
		stereoWidthSldCtrl->setValue(ourProcessor->stereoWidthParam->getValue(), dontSendNotification);		
	if (ourProcessor->audioGainParam->needsUIUpdate()) 
		gainSldCtrl->setValue(ourProcessor->audioGainParam->getValue(), dontSendNotification);
	if (ourProcessor->stereoPanParam->needsUIUpdate())
		stereoPanSldCtrl->setValueFromLinearNormalized(ourProcessor->stereoPanParam->getValue(), dontSendNotification);
		
	//ourProcessor->ClearUIUpdateFlag(); //Shouldn't be needed anymore since it's effectively not doing anything	
}
//END==============================================================================