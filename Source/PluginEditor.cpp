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
	stereoWidthSldCtrl->setSliderStyle(Slider::LinearHorizontal);
	stereoWidthSldCtrl->setTextBoxStyle(Slider::TextBoxLeft, false, 80, 20);
	stereoWidthSldCtrl->addListener(this);
	
	addAndMakeVisible(gainSldCtrl = new GainCtrlSlider("Gain Knob", audioProc->audioGainParam, "dB", 12.0));
	gainSldCtrl->setRange(0.0, 1.0, 0.0);
	// #TODO: Fix skew factor
	gainSldCtrl->setSkewFactor(0.5);
	gainSldCtrl->setSliderStyle(Slider::LinearVertical);
	gainSldCtrl->setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	gainSldCtrl->setColour(Slider::backgroundColourId, Colour(0x00868181));
	gainSldCtrl->setColour(Slider::trackColourId, Colour(0x7fffffff));
	gainSldCtrl->setColour(Slider::rotarySliderFillColourId, Colour(0x7fbcbcff));
	gainSldCtrl->setColour(Slider::rotarySliderOutlineColourId, Colour(0x66ffffff));
	gainSldCtrl->addListener(this);
	

	addAndMakeVisible(bypassBtnCtrl = new TextButton("Bypass Button"));
	bypassBtnCtrl->setButtonText(TRANS("Bypass"));
	bypassBtnCtrl->addListener(this);
	bypassBtnCtrl->setColour(TextButton::buttonColourId, Colour(0xffe2e2e2));

	addAndMakeVisible(widthLabel = new Label("Width Label", TRANS("Stereo Width Factor:")));
	widthLabel->setFont(Font(15.00f, Font::plain));
	widthLabel->setJustificationType(Justification::centredLeft);
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
	invertRightBtnCtrl->setColour(ToggleButton::textColourId, Colours::black);

	addAndMakeVisible(invertLabel = new Label("Invert Label",
											TRANS("Invert Phase\n"
												"L       R")));
	invertLabel->setFont(Font(15.00f, Font::plain));
	invertLabel->setJustificationType(Justification::centredBottom);
	invertLabel->setEditable(false, false, false);
	invertLabel->setColour(Label::textColourId, Colours::grey);
	invertLabel->setColour(TextEditor::textColourId, Colours::black);
	invertLabel->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	//Set default double click reset values
	gainSldCtrl->setDoubleClickReturnValue(true, gainSldCtrl->getAssociatedParameter()->getDefaultValue());
	stereoWidthSldCtrl->setDoubleClickReturnValue(true, stereoWidthSldCtrl->getAssociatedParameter()->getDefaultValue());

	// GUI Size 
	setSize(375, 500);

	getProcessor()->RequestUIUpdate(); //UI Update must be performed every time a new editor is constructed
	startTimer(20); // Start timer poll with 20ms rate
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
}

//==============================================================================
void StereoWidthCtrlAudioProcessorEditor::paint(Graphics& g)
{
	g.fillAll(Colours::black);
}

void StereoWidthCtrlAudioProcessorEditor::resized()
{
	stereoWidthSldCtrl->setBounds(16, 40, 352, 24);
	bypassBtnCtrl->setBounds(8, 234, 360, 24);
	widthLabel->setBounds(8, 8, 150, 24);
	muteBtnCtrl->setBounds(16, 194, 150, 24);
	gainSldCtrl->setBounds(200, 72, 150, 104);
	lockGainBtnCtrl->setBounds(208, 184, 150, 24);
	invertLeftBtnCtrl->setBounds(33, 118, 25, 20);
	invertRightBtnCtrl->setBounds(71, 118, 25, 20);
	invertLabel->setBounds(12, 80, 100, 32);
}

/// <summary> Called by JUCE when slider is moved.  Casts slider as Associated and passes to associatedSliderValueChanged</summary>
/// <param name="sliderThatWasMoved"> The slider that was moved.</param>
void StereoWidthCtrlAudioProcessorEditor::sliderValueChanged(Slider* sliderThatWasMoved)
{
	try
	{
		AudioProcessorParameter* param = static_cast<AssociatedSlider*>(sliderThatWasMoved)->getAssociatedParameter();
		if (sliderThatWasMoved == stereoWidthSldCtrl)
		{
			param->setValueNotifyingHost(static_cast<float>(stereoWidthSldCtrl->getValue()));
		} else if (sliderThatWasMoved == gainSldCtrl)
		{
			try
			{   
				param->setValueNotifyingHost(static_cast<float>(gainSldCtrl->getValue()));
			}
			catch (...)
			{
				DBG("Access Violation Exception Caught In PluginEditor.cpp::sliderValueChanged ");
			}
		}
	}
	catch (std::exception& e)
	{
		DBG("Casting >" + sliderThatWasMoved->getName() +"< to AssociatedSlider* failed: " + String(e.what()));
	}
}



void StereoWidthCtrlAudioProcessorEditor::buttonClicked(Button* buttonThatWasClicked)
{
	//DBG("Entered method: StereoWidthCtrlAudioProcessorEditor:buttonClicked(buttonThatWasClicked)");
	//DBG("Button Clicked: " + String(buttonThatWasClicked->getName()));
	//DBG("Compare: " + buttonThatWasClicked->getName() + " to " + lockGainBtnCtrl->getName());

	StereoWidthCtrlAudioProcessor* audioProc = getProcessor();

	if (buttonThatWasClicked == bypassBtnCtrl)
	{
		DBG("Bypass clicked");
	 	if (AudioProcessorParameter* param = audioProc->masterBypassParam)
	 	{
//	 		DBG("Changing buttonClicked");
	 		param->setValueNotifyingHost(bypassBtnCtrl->getToggleState());
//	 		DBG("Button->getToggleState = " + String(bypassBtnCtrl->getToggleState()) + " and ourProc Bypass = " + String(param->getValue()));
	 	}
	}
	else if (buttonThatWasClicked == muteBtnCtrl)
	{
		DBG("Mute button clicked");
		if (AudioProcessorParameter* param = audioProc->muteAudioParam)
		{
	//		DBG("Changing muteButton param From: " + String(param->getValue()) + " To: " + String(muteBtnCtrl->getToggleState()));
			param->setValueNotifyingHost(muteBtnCtrl->getToggleState());
	//		DBG("Changed muteButton param To: " + String(param->getValue()));
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
	 	}
	 	else if (buttonThatWasClicked == invertRightBtnCtrl)
	 	{
	 		if (AudioProcessorParameter* param = audioProc->invertRightParam )
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
		
	//ourProcessor->ClearUIUpdateFlag(); //Shouldn't be needed anymore since it's effectively not doing anything	
}
//END==============================================================================