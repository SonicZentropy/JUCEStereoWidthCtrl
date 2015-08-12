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
    WidthCtrlSld->setRange (0, 5, 0.1);
    WidthCtrlSld->setSliderStyle (Slider::LinearHorizontal);
    WidthCtrlSld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    WidthCtrlSld->addListener (this);

    addAndMakeVisible (BypassBtn = new TextButton ("Bypass Button"));
    BypassBtn->setButtonText (TRANS("Bypass"));
    BypassBtn->addListener (this);

    addAndMakeVisible (widthLabel = new Label ("Width Label",
                                               TRANS("Stereo Width Factor:")));
    widthLabel->setFont (Font (15.00f, Font::plain));
    widthLabel->setJustificationType (Justification::centredLeft);
    widthLabel->setEditable (false, false, false);
    widthLabel->setColour (Label::textColourId, Colours::grey);
    widthLabel->setColour (TextEditor::textColourId, Colours::black);
    widthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	getProcessor()->RequestUIUpdate(); //UI Update must be performed every time a new editor is constructed
	startTimer(200); // Start timer poll with 200ms rate
	BypassBtn->setClickingTogglesState(true);
    //[/Constructor]
}

StereoWidthCtrlAudioProcessorEditor::~StereoWidthCtrlAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    WidthCtrlSld = nullptr;
    BypassBtn = nullptr;
    widthLabel = nullptr;


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
    BypassBtn->setBounds (8, 72, 360, 24);
    widthLabel->setBounds (8, 8, 150, 24);
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
		DBG("Changing SliderValue");
		ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::StereoWidth, (float)WidthCtrlSld->getValue());
        //[/UserSliderCode_WidthCtrlSld]
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
		ourProcessor->setParameter(StereoWidthCtrlAudioProcessor::MasterBypass, (float)BypassBtn->getToggleState());
        //[/UserButtonCode_BypassBtn]
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
		BypassBtn->setToggleState(1.0f == ourProcessor->getParameter(StereoWidthCtrlAudioProcessor::StereoWidth),
			dontSendNotification);
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
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff000000"/>
  <SLIDER name="Width Factor Slider" id="8506fc7967803b22" memberName="WidthCtrlSld"
          virtualName="" explicitFocusOrder="0" pos="16 40 352 24" min="0"
          max="5" int="0.10000000000000001" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Bypass Button" id="7af29ac990473e08" memberName="BypassBtn"
              virtualName="" explicitFocusOrder="0" pos="8 72 360 24" buttonText="Bypass"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="Width Label" id="d43333b7c7118250" memberName="widthLabel"
         virtualName="" explicitFocusOrder="0" pos="8 8 150 24" textCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="Stereo Width Factor:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
