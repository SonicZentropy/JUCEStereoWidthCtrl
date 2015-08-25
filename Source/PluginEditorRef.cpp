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

//[Headers] You can add your own extra header files here...
#if 0
// THIS IS A REFERENCE CLASS ONLY FOR REFERENCING INTROJUCER-GENERATED GUI CODE, IT SHOULD NEVER BE ACTIVELY INCLUDED OR COMPILED
//[/Headers]

#include "PluginEditorRef.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
using namespace juce;
// THIS IS A REFERENCE CLASS ONLY FOR REFERENCING INTROJUCER-GENERATED GUI CODE, IT SHOULD NEVER BE ACTIVELY INCLUDED OR COMPILED
//[/MiscUserDefs]

//==============================================================================
StereoWidthCtrlAudioProcessorEditorRef::StereoWidthCtrlAudioProcessorEditorRef (StereoWidthCtrlAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
	
    //[/Constructor_pre]

    addAndMakeVisible (stereoWidthSldCtrl = new Slider ("Width Factor Slider"));
    stereoWidthSldCtrl->setTooltip (TRANS("Stereo Width"));
    stereoWidthSldCtrl->setRange (0, 2, 0.05);
    stereoWidthSldCtrl->setSliderStyle (Slider::LinearHorizontal);
    stereoWidthSldCtrl->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    stereoWidthSldCtrl->addListener (this);

    addAndMakeVisible (bypassBtnCtrl = new TextButton ("Bypass Button"));
    bypassBtnCtrl->setButtonText (TRANS("Bypass"));
    bypassBtnCtrl->addListener (this);
    bypassBtnCtrl->setColour (TextButton::buttonColourId, Colour (0xffe2e2e2));

    addAndMakeVisible (widthLabel = new Label ("Width Label",
                                               TRANS("Stereo Width Factor:")));
    widthLabel->setFont (Font (15.00f, Font::plain));
    widthLabel->setJustificationType (Justification::centredLeft);
    widthLabel->setEditable (false, false, false);
    widthLabel->setColour (Label::textColourId, Colours::grey);
    widthLabel->setColour (TextEditor::textColourId, Colours::black);
    widthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (muteBtnCtrl = new TextButton ("Mute Button"));
    muteBtnCtrl->setButtonText (TRANS("Mute"));
    muteBtnCtrl->addListener (this);
    muteBtnCtrl->setColour (TextButton::buttonColourId, Colour (0xffe2e2e2));

    addAndMakeVisible (gainSldCtrl = new GainSlider ("Gain Knob"));
    gainSldCtrl->setRange (-96, 12, 0.1);
    gainSldCtrl->setSliderStyle (Slider::LinearVertical);
    gainSldCtrl->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    gainSldCtrl->setColour (Slider::backgroundColourId, Colour (0x00868181));
    gainSldCtrl->setColour (Slider::trackColourId, Colour (0x7fffffff));
    gainSldCtrl->setColour (Slider::rotarySliderFillColourId, Colour (0x7fbcbcff));
    gainSldCtrl->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    gainSldCtrl->addListener (this);

    addAndMakeVisible (lockGainBtnCtrl = new TextButton ("Lock Gain"));
    lockGainBtnCtrl->setButtonText (TRANS("Lock Gain to 0db"));
    lockGainBtnCtrl->addListener (this);
    lockGainBtnCtrl->setColour (TextButton::buttonColourId, Colour (0xffe2e2e2));

    addAndMakeVisible (invertLeftBtnCtrl = new ToggleButton ("Invert Left"));
    invertLeftBtnCtrl->setTooltip (TRANS("Phase invert Left Channel"));
    invertLeftBtnCtrl->setButtonText (String::empty);
    invertLeftBtnCtrl->addListener (this);

    addAndMakeVisible (invertRightBtnCtrl = new ToggleButton ("Invert Right"));
    invertRightBtnCtrl->setTooltip (TRANS("Phase invert Right Channel"));
    invertRightBtnCtrl->setButtonText (String::empty);
    invertRightBtnCtrl->addListener (this);
    invertRightBtnCtrl->setColour (ToggleButton::textColourId, Colours::black);

    addAndMakeVisible (invertLabel = new Label ("Invert Label",
                                                TRANS("Invert Phase\n"
                                                "L       R")));
    invertLabel->setFont (Font (15.00f, Font::plain));
    invertLabel->setJustificationType (Justification::centredBottom);
    invertLabel->setEditable (false, false, false);
    invertLabel->setColour (Label::textColourId, Colours::grey);
    invertLabel->setColour (TextEditor::textColourId, Colours::black);
    invertLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]


	gainSldCtrl->setDoubleClickReturnValue(true, 0.0f);
	stereoWidthSldCtrl->setDoubleClickReturnValue(true, 1.0f);
    //[/UserPreSize]

    setSize (375, 500);


    //[Constructor] You can add your own custom stuff here..
	getProcessor()->RequestUIUpdate(); //UI Update must be performed every time a new editor is constructed
	startTimer(200); // Start timer poll with 200ms rate
	bypassBtnCtrl->setClickingTogglesState(true);
	muteBtnCtrl->setClickingTogglesState(true);
	lockGainBtnCtrl->setClickingTogglesState(true);
	invertLeftBtnCtrl->setClickingTogglesState(true);
	invertRightBtnCtrl->setClickingTogglesState(true);
	gainSldCtrl->setAssociatedParameter(getProcessor()->audioGainParam);
	DBG("Just set associated Parameter: " + String(getProcessor()->audioGainParam->getName(20)));
    //[/Constructor]
}

StereoWidthCtrlAudioProcessorEditorRef::~StereoWidthCtrlAudioProcessorEditorRef()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    stereoWidthSldCtrl = nullptr;
    bypassBtnCtrl = nullptr;
    widthLabel = nullptr;
    muteBtnCtrl = nullptr;
    gainSldCtrl = nullptr;
    lockGainBtnCtrl = nullptr;
    invertLeftBtnCtrl = nullptr;
    invertRightBtnCtrl = nullptr;
    invertLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void StereoWidthCtrlAudioProcessorEditorRef::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void StereoWidthCtrlAudioProcessorEditorRef::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    stereoWidthSldCtrl->setBounds (16, 40, 352, 24);
    bypassBtnCtrl->setBounds (8, 234, 360, 24);
    widthLabel->setBounds (8, 8, 150, 24);
    muteBtnCtrl->setBounds (16, 194, 150, 24);
    gainSldCtrl->setBounds (200, 72, 150, 104);
    lockGainBtnCtrl->setBounds (208, 184, 150, 24);
    invertLeftBtnCtrl->setBounds (33, 118, 25, 20);
    invertRightBtnCtrl->setBounds (71, 118, 25, 20);
    invertLabel->setBounds (12, 80, 100, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void StereoWidthCtrlAudioProcessorEditorRef::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == stereoWidthSldCtrl)
    {
        //[UserSliderCode_stereoWidthSldCtrl] -- add your slider handling code here..
		if (AudioProcessorParameter* param = getParameterFromComponent(sliderThatWasMoved))
		{
			DBG("Changing Width SliderValue from: " + String(param->getValue()) + " to: " + static_cast<String>(stereoWidthSldCtrl->getValue() / 2.0f));
			param->setValueNotifyingHost(static_cast<float>(stereoWidthSldCtrl->getValue() / 2.0f));
		}
        //[/UserSliderCode_stereoWidthSldCtrl]
    }
    else if (sliderThatWasMoved == gainSldCtrl)
    {
        //[UserSliderCode_gainSldCtrl] -- add your slider handling code here..

		if (AudioProcessorParameter* param = static_cast<GainSlider*>(sliderThatWasMoved)->getAssociatedParameter())
		{
			DBG("Gain slider value changing from: " + String(param->getValue()) + " to: " + static_cast<String>(sliderThatWasMoved->getValue()));
			//CONVERT FROM DB TO VALUE
			float valueDenormal = static_cast<float>(sliderThatWasMoved->getValue());
			float valueNorm = Decibels::decibelsToGain(valueDenormal, -96.0f);
			param->setValueNotifyingHost( valueNorm );
			DBG("audioGainParam is now: " + static_cast<String>(param->getValue()));
		}
        //[/UserSliderCode_gainSldCtrl]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void StereoWidthCtrlAudioProcessorEditorRef::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == bypassBtnCtrl)
    {
        //[UserButtonCode_bypassBtnCtrl] -- add your button handler code here..
		if (AudioProcessorParameter* param = getParameterFromComponent(buttonThatWasClicked))
		{
			DBG("Changing buttonClicked");
			param->setValue(static_cast<float>(bypassBtnCtrl->getToggleState()));
			DBG("Button->getToggleState = " + String(bypassBtnCtrl->getToggleState()) + " and ourProc Bypass = " + String(param->getValue()));
		}
        //[/UserButtonCode_bypassBtnCtrl]
    }
    else if (buttonThatWasClicked == muteBtnCtrl)
    {
        //[UserButtonCode_muteBtnCtrl] -- add your button handler code here..
		if (AudioProcessorParameter* param = getParameterFromComponent(buttonThatWasClicked))
		{
			DBG("Changing muteButton");
			param->setValue(static_cast<float>(muteBtnCtrl->getToggleState()));
		}
        //[/UserButtonCode_muteBtnCtrl]
    }
    else if (buttonThatWasClicked == lockGainBtnCtrl)
    {
        //[UserButtonCode_lockGainBtnCtrl] -- add your button handler code here..
		if (AudioProcessorParameter* param = getParameterFromComponent(buttonThatWasClicked))
		{
			DBG("Changing Lock Gain");
			param->setValue(static_cast<float>(lockGainBtnCtrl->getToggleState()));
			if (lockGainBtnCtrl->getToggleState())
			{
				gainSldCtrl->setRange(-96, 0, 0.1);
				gainSldCtrl->setValue(std::min(0.0f, static_cast<float>(gainSldCtrl->getValue())));
				gainSldCtrl->repaint();
				param->setValue(Decibels::decibelsToGain(static_cast<float>(gainSldCtrl->getValue())));
				//StereoWidthCtrlAudioProcessor* ourProcessor = getProcessor();

				getProcessor()->RequestUIUpdate();
			}
			else
			{
				gainSldCtrl->setRange(-96, 12, 0.1);
				gainSldCtrl->repaint();
				getProcessor()->RequestUIUpdate();
			}
		}
        //[/UserButtonCode_lockGainBtnCtrl]
    }
    else if (buttonThatWasClicked == invertLeftBtnCtrl)
    {
        //[UserButtonCode_invertLeftBtnCtrl] -- add your button handler code here..
		if (AudioProcessorParameter* param = getParameterFromComponent(buttonThatWasClicked))
		{
			DBG("Before Inverting Left is : " + String(StereoWidthCtrlAudioProcessor::InvertLeft));
			param->setValue( static_cast<float>(invertLeftBtnCtrl->getToggleStateValue().getValue()));
			DBG("Inverted is: " + String(param->getValue()) + " From toggle : " + String(static_cast<float>(invertLeftBtnCtrl->getToggleStateValue().getValue())));
		}
        //[/UserButtonCode_invertLeftBtnCtrl]
    }
    else if (buttonThatWasClicked == invertRightBtnCtrl)
    {
        //[UserButtonCode_invertRightBtnCtrl] -- add your button handler code here..
		if (AudioProcessorParameter* param = getParameterFromComponent(buttonThatWasClicked))
		{
			DBG("Before Inverting Right is : " + String(StereoWidthCtrlAudioProcessor::InvertRight));
			param->setValue( static_cast<float>(invertRightBtnCtrl->getToggleStateValue().getValue()));

			DBG("Inverted is: " + String(param->getValue()) + " From toggle : " + String(static_cast<float>(invertRightBtnCtrl->getToggleStateValue().getValue())));
		}
        //[/UserButtonCode_invertRightBtnCtrl]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void StereoWidthCtrlAudioProcessorEditorRef::timerCallback()
{
	StereoWidthCtrlAudioProcessor* ourProcessor = getProcessor();
	//exchange data between UI Elements and the Plugin (ourProcessor)
	if (ourProcessor->needsUIUpdate())
	{
		muteBtnCtrl->setToggleState(1.0f == ourProcessor->muteAudioParam->getValue(), sendNotification);
		DBG("Past muteBtn");
		bypassBtnCtrl->setToggleState(1.0f == ourProcessor->masterBypassParam->getValue(), sendNotification);
		DBG("Past bypassBtn");
		DBG("Changing Width SliderValue from proc: " + String(ourProcessor->stereoWidthParam->getValue()) + " to WidthSld/2: " + static_cast<String>(stereoWidthSldCtrl->getValue() / 2.0f));
		stereoWidthSldCtrl->setValue(ourProcessor->stereoWidthParam->getValue() * 2.0f, sendNotification);

		DBG("Changing gainSldCtrl Value: " + String(gainSldCtrl->getValue()) + " to audioGainParam: " + String(ourProcessor->audioGainParam->getValue()) );
		gainSldCtrl->setValue(Decibels::gainToDecibels(ourProcessor->audioGainParam->getValue()), sendNotification);
		DBG("gainSldCtrl value set (converted gain to Decibels) : " + String(gainSldCtrl->getValue()));
		ourProcessor->ClearUIUpdateFlag();
	}
}

AudioProcessorParameter* StereoWidthCtrlAudioProcessorEditorRef::getParameterFromComponent(const Component* comp) const
{
	if (comp == gainSldCtrl)
	{
		DBG("Returning gainSldCtrl");
		return getProcessor()->audioGainParam;
	}
	//throw exception
	//throw std::invalid_argument("Unrecognized Component");

	return nullptr;
}

// AudioProcessorParameter* StereoWidthCtrlAudioProcessorEditor::getParameterFromComponent(const Slider* slider) const
// {
// 	if (slider == gainSldCtrl)
// 	{
// 		return getProcessor()->audioGainParam;
// 	}
// 	return nullptr;
// }

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StereoWidthCtrlAudioProcessorEditorRef"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="StereoWidthCtrlAudioProcessor&amp; ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="4"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="375" initialHeight="500">
  <BACKGROUND backgroundColour="ff000000"/>
  <SLIDER name="Width Factor Slider" id="8506fc7967803b22" memberName="stereoWidthSldCtrl"
          virtualName="" explicitFocusOrder="0" pos="16 40 352 24" tooltip="Stereo Width"
          min="0" max="2" int="0.050000000000000003" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Bypass Button" id="7af29ac990473e08" memberName="bypassBtnCtrl"
              virtualName="" explicitFocusOrder="0" pos="8 234 360 24" bgColOff="ffe2e2e2"
              buttonText="Bypass" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Width Label" id="d43333b7c7118250" memberName="widthLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 150 24" textCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="Stereo Width Factor:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Mute Button" id="914591cf8043a819" memberName="muteBtnCtrl"
              virtualName="" explicitFocusOrder="0" pos="16 194 150 24" bgColOff="ffe2e2e2"
              buttonText="Mute" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="Gain Knob" id="dd791eb940d88513" memberName="gainSldCtrl"
          virtualName="GainSlider" explicitFocusOrder="0" pos="200 72 150 104"
          bkgcol="868181" trackcol="7fffffff" rotarysliderfill="7fbcbcff"
          rotaryslideroutline="66ffffff" min="-96" max="12" int="0.10000000000000001"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Lock Gain" id="1dcd400b4d4f873f" memberName="lockGainBtnCtrl"
              virtualName="" explicitFocusOrder="0" pos="208 184 150 24" bgColOff="ffe2e2e2"
              buttonText="Lock Gain to 0db" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Invert Left" id="4fd996f19d4c1c9a" memberName="invertLeftBtnCtrl"
                virtualName="" explicitFocusOrder="0" pos="33 118 25 20" tooltip="Phase invert Left Channel"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="Invert Right" id="e82b7317ef02b75f" memberName="invertRightBtnCtrl"
                virtualName="" explicitFocusOrder="0" pos="71 118 25 20" tooltip="Phase invert Right Channel"
                txtcol="ff000000" buttonText="" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <LABEL name="Invert Label" id="cc1a383f50c89523" memberName="invertLabel"
         virtualName="" explicitFocusOrder="0" pos="12 80 100 32" textCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="Invert Phase&#10;L       R"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="20"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
#endif
//[/EndFile]
