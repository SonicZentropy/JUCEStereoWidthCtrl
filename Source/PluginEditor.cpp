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
#include "components/NotepadComponent/NotepadComponent.h"

using namespace juce;

//==============================================================================
StereoWidthCtrlAudioProcessorEditor::StereoWidthCtrlAudioProcessorEditor(StereoWidthCtrlAudioProcessor& ownerFilter)
	: AudioProcessorEditor(ownerFilter), processor(&ownerFilter)
{
	// #TODO: Set Default Look And Feel
	//Audio Processor reference
	StereoWidthCtrlAudioProcessor* audioProc = getProcessor();

	addAndMakeVisible(tabbedComponent = new TabbedComponent(TabbedButtonBar::TabsAtTop));
	tabbedComponent->setTabBarDepth(20);
	tabbedComponent->addTab(TRANS("Main"), Colours::black, new Component("Main"), true);
	tabbedComponent->addTab(TRANS("Notes"), Colours::lightgrey, new NotepadComponent("Notepad", "NOTEPAD CONTENTS"), true);
	tabbedComponent->setCurrentTabIndex(0);
		
	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(stereoWidthSldCtrl = new StereoWidthCtrlSlider("Width Factor Slider", audioProc->stereoWidthParam, "%"));
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
	
	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(gainSldCtrl = new GainCtrlSlider("Gain Knob", audioProc->audioGainParam, "dB", 12.0));
	gainSldCtrl->setRange(0.0, 1.0, 0.0);
	gainSldCtrl->setSkewFactor(0.5);
	gainSldCtrl->setSliderStyle(Slider::LinearVertical);
	gainSldCtrl->setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	gainSldCtrl->setColour(Slider::backgroundColourId, Colour(0x00868181));
	gainSldCtrl->setColour(Slider::trackColourId, Colour(0x7fffffff));
	gainSldCtrl->setColour(Slider::rotarySliderFillColourId, Colour(0x7fbcbcff));
	gainSldCtrl->setColour(Slider::rotarySliderOutlineColourId, Colour(0x66ffffff));
	gainSldCtrl->setColour(Slider::textBoxBackgroundColourId, Colour(0xffb2b2ff));
	gainSldCtrl->addListener(this);
	
	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(bypassBtnCtrl = new TextButton("Bypass Button"));
	bypassBtnCtrl->setButtonText(TRANS("Bypass"));
	bypassBtnCtrl->addListener(this);
	bypassBtnCtrl->setColour(TextButton::buttonColourId, Colour(0xffe2e2e2));

	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(widthLabel = new Label("Width Label", TRANS("Stereo Width Factor:")));
	widthLabel->setFont(Font(10.00f, Font::bold));
	widthLabel->setJustificationType(Justification::centred);
	widthLabel->setEditable(false, false, false);
	widthLabel->setColour(Label::textColourId, Colours::grey);
	widthLabel->setColour(TextEditor::textColourId, Colours::black);
	widthLabel->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(muteBtnCtrl = new TextButton("Mute Button"));
	muteBtnCtrl->setButtonText(TRANS("Mute"));
	muteBtnCtrl->addListener(this);
	muteBtnCtrl->setColour(TextButton::buttonColourId, Colour(0xffe2e2e2));

	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(lockGainBtnCtrl = new TextButton("Lock Gain"));
	lockGainBtnCtrl->setButtonText(TRANS("Lock Gain to 0db"));
	lockGainBtnCtrl->addListener(this);
	lockGainBtnCtrl->setColour(TextButton::buttonColourId, Colour(0xffe2e2e2));

	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(invertLeftBtnCtrl = new ToggleButton("Invert Left"));
	invertLeftBtnCtrl->setTooltip(TRANS("Phase invert Left Channel"));
	invertLeftBtnCtrl->setButtonText(String::empty);
	invertLeftBtnCtrl->addListener(this);

	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(invertRightBtnCtrl = new ToggleButton("Invert Right"));
	invertRightBtnCtrl->setTooltip(TRANS("Phase invert Right Channel"));
	invertRightBtnCtrl->setButtonText(String::empty);
	invertRightBtnCtrl->addListener(this);
	invertRightBtnCtrl->setColour(ToggleButton::textColourId, Colour(0xffb2b2ff));

	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(invertLabel = new Label("Invert Label",
		TRANS("Invert:\n"
			"L       R")));
	invertLabel->setFont(Font(10.00f, Font::bold));
	invertLabel->setJustificationType(Justification::centredBottom);
	invertLabel->setEditable(false, false, false);
	invertLabel->setColour(Label::textColourId, Colours::grey);
	invertLabel->setColour(TextEditor::textColourId, Colours::black);
	invertLabel->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(gainLabel = new Label("Gain Label",
		TRANS("Gain:")));
	gainLabel->setFont(Font(10.00f, Font::bold));
	gainLabel->setJustificationType(Justification::centredBottom);
	gainLabel->setEditable(false, false, false);
	gainLabel->setColour(Label::textColourId, Colours::grey);
	gainLabel->setColour(TextEditor::textColourId, Colours::black);
	gainLabel->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

	tabbedComponent->getTabContentComponent(0)->addAndMakeVisible(stereoPanSldCtrl = new AssociatedSlider("Panning"));
	stereoPanSldCtrl->setRange(-100, 100, 1);
	stereoPanSldCtrl->setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	stereoPanSldCtrl->setTextBoxStyle(Slider::TextBoxBelow, false, 50, 20);
	stereoPanSldCtrl->setColour(Slider::rotarySliderFillColourId, Colour(0x7f8080ff));
	stereoPanSldCtrl->setColour(Slider::rotarySliderOutlineColourId, Colour(0x66ffffff));
	stereoPanSldCtrl->setColour(Slider::textBoxBackgroundColourId, Colour(0xffb2b2ff));
	stereoPanSldCtrl->addListener(this);
	

	//Set default double click reset values

	gainSldCtrl->setDoubleClickReturnValue(true, gainSldCtrl->getAssociatedParameter()->getDefaultValue());
	stereoWidthSldCtrl->setDoubleClickReturnValue(true, stereoWidthSldCtrl->getAssociatedParameter()->getDefaultValue());
	stereoPanSldCtrl->setDoubleClickReturnValue(true, 0.5f);

	// GUI Size 
	setSize(250, 280);

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
	tabbedComponent = nullptr;

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
	
	tabbedComponent->setBounds(0, 0, getWidth(), getHeight());
	
	//MainTab
	stereoWidthSldCtrl->setBounds(53, 4, 69, 30);
	bypassBtnCtrl->setBounds(3, 145, 112, 16);
	widthLabel->setBounds(6, 5, 42, 24);
	muteBtnCtrl->setBounds(3, 124, 30, 16);
	gainSldCtrl->setBounds(64, 49, 50, 69);
	lockGainBtnCtrl->setBounds(33, 124, 82, 16);
	invertLeftBtnCtrl->setBounds(8, 48, 20, 20);
	invertRightBtnCtrl->setBounds(33, 48, 20, 20);
	invertLabel->setBounds(8, 30, 44, 20);
	gainLabel->setBounds(63, 32, 39, 14);
	stereoPanSldCtrl->setBounds(3, 74, 56, 44);
/*
	stereoWidthSldCtrl->setBounds(81, 11, 61, 18);
	widthLabel->setBounds(8, 8, 72, 24);
	bypassBtnCtrl->setBounds(14, 123, 112, 16);
	muteBtnCtrl->setBounds(14, 106, 30, 16);
	gainSldCtrl->setBounds(76, 36, 38, 69);
	lockGainBtnCtrl->setBounds(44,106,82,16);
	invertLeftBtnCtrl->setBounds(22, 46, 20, 16);
	invertRightBtnCtrl->setBounds(47, 46, 20, 16);
	invertLabel->setBounds(21, 28, 44, 20);
	stereoPanSldCtrl->setBounds(16, 61, 56, 44);*/
	//panLabel->setBounds(162, 72, 35, 24);
	//midOnlyBtnCtrl->setBounds(124, 80, 40, 24);
	
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
		} 
		else if (sliderThatWasMoved == gainSldCtrl)
		{   
			param->setValueNotifyingHost(static_cast<float>(gainSldCtrl->getValue()));
		}
		else if (sliderThatWasMoved == stereoPanSldCtrl)
		{
			getProcessor()->stereoPanParam->setValueNotifyingHost(stereoPanSldCtrl->getLinearNormalizedValue());
		}
	}
	catch (std::exception& e)
	{
		DBG("Casting >" + sliderThatWasMoved->getName() +"< to AssociatedSlider* failed: " + String(e.what()));
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