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
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
StereoWidthCtrlAudioProcessorEditor::StereoWidthCtrlAudioProcessorEditor (StereoWidthCtrlAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (WidthCtrlSld = new Slider ("Width Factor Slider"));
    WidthCtrlSld->setTooltip (TRANS("Stereo Width"));
    WidthCtrlSld->setRange (0, 2, 0.05);
    WidthCtrlSld->setSliderStyle (Slider::LinearHorizontal);
    WidthCtrlSld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    WidthCtrlSld->addListener (this);

    addAndMakeVisible (BypassBtn = new TextButton ("Bypass Button"));
    BypassBtn->setButtonText (TRANS("Bypass"));
    BypassBtn->addListener (this);
    BypassBtn->setColour (TextButton::buttonColourId, Colour (0xffe2e2e2));

    addAndMakeVisible (widthLabel = new Label ("Width Label",
                                               TRANS("Stereo Width Factor:")));
    widthLabel->setFont (Font (15.00f, Font::plain));
    widthLabel->setJustificationType (Justification::centredLeft);
    widthLabel->setEditable (false, false, false);
    widthLabel->setColour (Label::textColourId, Colours::grey);
    widthLabel->setColour (TextEditor::textColourId, Colours::black);
    widthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (muteBtn = new TextButton ("Mute Button"));
    muteBtn->setButtonText (TRANS("Mute"));
    muteBtn->addListener (this);
    muteBtn->setColour (TextButton::buttonColourId, Colour (0xffe2e2e2));

    addAndMakeVisible (gainKnob = new GainSlider ("Gain Knob"));
    gainKnob->setRange (-96, 12, 0.1);
    gainKnob->setSliderStyle (Slider::LinearVertical);
    gainKnob->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    gainKnob->setColour (Slider::backgroundColourId, Colour (0x00868181));
    gainKnob->setColour (Slider::trackColourId, Colour (0x7fffffff));
    gainKnob->setColour (Slider::rotarySliderFillColourId, Colour (0x7fbcbcff));
    gainKnob->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    gainKnob->addListener (this);

    addAndMakeVisible (lockGain = new TextButton ("Lock Gain"));
    lockGain->setButtonText (TRANS("Lock Gain to 0db"));
    lockGain->addListener (this);
    lockGain->setColour (TextButton::buttonColourId, Colour (0xffe2e2e2));

    addAndMakeVisible (invertLeft = new ToggleButton ("Invert Left"));
    invertLeft->setTooltip (TRANS("Phase invert Left Channel"));
    invertLeft->setButtonText (String::empty);
    invertLeft->addListener (this);

    addAndMakeVisible (invertRight = new ToggleButton ("Invert Right"));
    invertRight->setTooltip (TRANS("Phase invert Right Channel"));
    invertRight->setButtonText (String::empty);
    invertRight->addListener (this);
    invertRight->setColour (ToggleButton::textColourId, Colours::black);

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
	gainKnob->setDoubleClickReturnValue(true, 0.0f);
	WidthCtrlSld->setDoubleClickReturnValue(true, 1.0f);
    //[/UserPreSize]

    setSize (375, 500);


    //[Constructor] You can add your own custom stuff here..
	getProcessor()->RequestUIUpdate(); //UI Update must be performed every time a new editor is constructed
	startTimer(200); // Start timer poll with 200ms rate
	BypassBtn->setClickingTogglesState(true);
	muteBtn->setClickingTogglesState(true);
	lockGain->setClickingTogglesState(true);
	invertLeft->setClickingTogglesState(true);
	invertRight->setClickingTogglesState(true);
    //[/Constructor]
}

StereoWidthCtrlAudioProcessorEditor::~StereoWidthCtrlAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    WidthCtrlSld = nullptr;
    BypassBtn = nullptr;
    widthLabel = nullptr;
    muteBtn = nullptr;
    gainKnob = nullptr;
    lockGain = nullptr;
    invertLeft = nullptr;
    invertRight = nullptr;
    invertLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void StereoWidthCtrlAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void StereoWidthCtrlAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    WidthCtrlSld->setBounds (16, 40, 352, 24);
    BypassBtn->setBounds (8, 296, 360, 24);
    widthLabel->setBounds (8, 8, 150, 24);
    muteBtn->setBounds (16, 256, 150, 24);
    gainKnob->setBounds (200, 72, 150, 104);
    lockGain->setBounds (208, 184, 150, 24);
    invertLeft->setBounds (33, 118, 25, 20);
    invertRight->setBounds (71, 118, 25, 20);
    invertLabel->setBounds (12, 80, 100, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void StereoWidthCtrlAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	StereoWidthCtrlAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == WidthCtrlSld)
    {
        //[UserSliderCode_WidthCtrlSld] -- add your slider handling code here..
		DBG("Changing Width SliderValue from: " + String(StereoWidthCtrlAudioProcessor::StereoWidth) + " to: " + static_cast<String>(WidthCtrlSld->getValue()));
		ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::StereoWidth, static_cast<float>(WidthCtrlSld->getValue() / 2.0f));
        //[/UserSliderCode_WidthCtrlSld]
    }
    else if (sliderThatWasMoved == gainKnob)
    {
        //[UserSliderCode_gainKnob] -- add your slider handling code here..
		DBG("Gain slider value changing from: " + String(StereoWidthCtrlAudioProcessor::AudioGain) + " to: " + static_cast<String>(gainKnob->getValue()));
		ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::AudioGain, Decibels::decibelsToGain(static_cast<float>(gainKnob->getValue())));
        //[/UserSliderCode_gainKnob]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void StereoWidthCtrlAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	StereoWidthCtrlAudioProcessor* ourProcessor = getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == BypassBtn)
    {
        //[UserButtonCode_BypassBtn] -- add your button handler code here..
		DBG("Changing buttonClicked");
		ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::MasterBypass, static_cast<float>(BypassBtn->getToggleState()));
		DBG("Button->getToggleState = " + String(BypassBtn->getToggleState()) + " and ourProc Bypass = " + String(ourProcessor->getParameter(StereoWidthCtrlAudioProcessor::MasterBypass)));
        //[/UserButtonCode_BypassBtn]
    }
    else if (buttonThatWasClicked == muteBtn)
    {
        //[UserButtonCode_muteBtn] -- add your button handler code here..
		DBG("Changing muteButton");
		ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::MuteAudio, static_cast<float>(muteBtn->getToggleState()));
        //[/UserButtonCode_muteBtn]
    }
    else if (buttonThatWasClicked == lockGain)
    {
        //[UserButtonCode_lockGain] -- add your button handler code here..
		DBG("Changing Lock Gain");
		ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::LockGain, static_cast<float>(lockGain->getToggleState()));
		if (lockGain->getToggleState())
		{
			gainKnob->setRange(-96, 0, 0.1);
			gainKnob->setValue(std::min(0.0f, static_cast<float>(gainKnob->getValue())));
			gainKnob->repaint();
			ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::AudioGain, Decibels::decibelsToGain(static_cast<float>(gainKnob->getValue())));
			ourProcessor->RequestUIUpdate();
		}
		else
		{
			gainKnob->setRange(-96, 12, 0.1);
			gainKnob->repaint();
			ourProcessor->RequestUIUpdate();
		}
        //[/UserButtonCode_lockGain]
    }
	/// Phase Inversion routines
    else if (buttonThatWasClicked == invertLeft)
    {
        //[UserButtonCode_invertLeft] -- add your button handler code here..
		DBG("Before Inverting Left is : " + String(StereoWidthCtrlAudioProcessor::InvertLeft));
		ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::InvertLeft, static_cast<float>(invertLeft->getToggleStateValue().getValue()));
		DBG("Inverted is: " + String(StereoWidthCtrlAudioProcessor::InvertLeft) + " From toggle : " + String( static_cast<float>(invertLeft->getToggleStateValue().getValue() ) ) );
        //[/UserButtonCode_invertLeft]
    }
    else if (buttonThatWasClicked == invertRight)
    {
        //[UserButtonCode_invertRight] -- add your button handler code here..
		DBG("Before Inverting Right is : " + String(StereoWidthCtrlAudioProcessor::InvertRight));
		ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::InvertRight, static_cast<float>(invertRight->getToggleStateValue().getValue()));
		DBG("Inverted is: " + String(StereoWidthCtrlAudioProcessor::InvertRight) + " From toggle : " + String(static_cast<float>(invertRight->getToggleStateValue().getValue())));
        //[/UserButtonCode_invertRight]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void StereoWidthCtrlAudioProcessorEditor::timerCallback()
{
	StereoWidthCtrlAudioProcessor* ourProcessor = getProcessor();
	//exchange data between UI Elements and the Plugin (ourProcessor)
	if (ourProcessor->needsUIUpdate())
	{
		BypassBtn->setToggleState(1.0f == ourProcessor->getParameter(StereoWidthCtrlAudioProcessor::MasterBypass),
			sendNotificationAsync);
		WidthCtrlSld->setValue(ourProcessor->getParameter(StereoWidthCtrlAudioProcessor::StereoWidth), sendNotificationAsync);
		muteBtn->setToggleState(1.0f == ourProcessor->getParameter(StereoWidthCtrlAudioProcessor::MuteAudio), sendNotificationAsync);
		gainKnob->setValue(Decibels::gainToDecibels(ourProcessor->getParameter(StereoWidthCtrlAudioProcessor::AudioGain)), sendNotificationAsync);
		ourProcessor->ClearUIUpdateFlag();
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StereoWidthCtrlAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="StereoWidthCtrlAudioProcessor&amp; ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="4"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="375" initialHeight="500">
  <BACKGROUND backgroundColour="ff000000"/>
  <SLIDER name="Width Factor Slider" id="8506fc7967803b22" memberName="WidthCtrlSld"
          virtualName="" explicitFocusOrder="0" pos="16 40 352 24" tooltip="Stereo Width"
          min="0" max="2" int="0.050000000000000003" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Bypass Button" id="7af29ac990473e08" memberName="BypassBtn"
              virtualName="" explicitFocusOrder="0" pos="8 296 360 24" bgColOff="ffe2e2e2"
              buttonText="Bypass" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Width Label" id="d43333b7c7118250" memberName="widthLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 150 24" textCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="Stereo Width Factor:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Mute Button" id="914591cf8043a819" memberName="muteBtn"
              virtualName="" explicitFocusOrder="0" pos="16 256 150 24" bgColOff="ffe2e2e2"
              buttonText="Mute" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="Gain Knob" id="dd791eb940d88513" memberName="gainKnob"
          virtualName="GainSlider" explicitFocusOrder="0" pos="200 72 150 104"
          bkgcol="868181" trackcol="7fffffff" rotarysliderfill="7fbcbcff"
          rotaryslideroutline="66ffffff" min="-96" max="12" int="0.10000000000000001"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Lock Gain" id="1dcd400b4d4f873f" memberName="lockGain"
              virtualName="" explicitFocusOrder="0" pos="208 184 150 24" bgColOff="ffe2e2e2"
              buttonText="Lock Gain to 0db" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Invert Left" id="4fd996f19d4c1c9a" memberName="invertLeft"
                virtualName="" explicitFocusOrder="0" pos="33 118 25 20" tooltip="Phase invert Left Channel"
                buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="Invert Right" id="e82b7317ef02b75f" memberName="invertRight"
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
//[/EndFile]
