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

#ifndef __JUCE_HEADER_D4563669377CDB84__
#define __JUCE_HEADER_D4563669377CDB84__

//[Headers]     -- You can add your own extra header files here --
// THIS IS A REFERENCE CLASS ONLY FOR REFERENCING INTROJUCER-GENERATED GUI CODE, IT SHOULD NEVER BE ACTIVELY INCLUDED
#if 0

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "AssociatedSlider.h"
#include "zen_utils/juce_zen_utils.h"

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
// THIS IS A REFERENCE CLASS ONLY FOR REFERENCING INTROJUCER-GENERATED GUI CODE, IT SHOULD NEVER BE ACTIVELY INCLUDED
                                                                    //[/Comments]
*/
class StereoWidthCtrlAudioProcessorEditorRef  : public AudioProcessorEditor,
                                                public Timer,
                                                public SliderListener,
                                                public ButtonListener
{
public:
    //==============================================================================
    StereoWidthCtrlAudioProcessorEditorRef (StereoWidthCtrlAudioProcessor& ownerFilter);
    ~StereoWidthCtrlAudioProcessorEditorRef();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void timerCallback() override;
	StereoWidthCtrlAudioProcessor* getProcessor() const
	{
		return static_cast<StereoWidthCtrlAudioProcessor*>(getAudioProcessor());
	}

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	AudioProcessorParameter* getParameterFromComponent(const Component*) const;
	//AudioProcessorParameter* getParameterFromComponent(const Slider*) const;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> stereoWidthSldCtrl;
    ScopedPointer<TextButton> bypassBtnCtrl;
    ScopedPointer<Label> widthLabel;
    ScopedPointer<TextButton> muteBtnCtrl;
    ScopedPointer<GainSlider> gainSldCtrl;
    ScopedPointer<TextButton> lockGainBtnCtrl;
    ScopedPointer<ToggleButton> invertLeftBtnCtrl;
    ScopedPointer<ToggleButton> invertRightBtnCtrl;
    ScopedPointer<Label> invertLabel;
    ScopedPointer<Slider> testSlider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StereoWidthCtrlAudioProcessorEditorRef)
};

//[EndFile] You can add extra defines here...
#endif
//[/EndFile]

#endif   // __JUCE_HEADER_D4563669377CDB84__
