/* ==============================================================================
//  PluginEditor.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/08/20
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: GUI Editor Header
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#ifndef JUCE_STEREO_WIDTH_PLUGIN_EDITOR
#define JUCE_STEREO_WIDTH_PLUGIN_EDITOR

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "gainSlider.h"
#include <exception>
//#include "zen_utils/juce_zen_utils.h"


//==============================================================================

/// <summary> GUI Editor Handler </summary>
/// <seealso cref="T:AudioProcessorEditor"/>
/// <seealso cref="T:Timer"/>
/// <seealso cref="T:SliderListener"/>
/// <seealso cref="T:ButtonListener"/>
class StereoWidthCtrlAudioProcessorEditor : public AudioProcessorEditor,
											public Timer,
											public SliderListener,
											public ButtonListener
{
public:
	//==============================================================================
	StereoWidthCtrlAudioProcessorEditor(StereoWidthCtrlAudioProcessor& ownerFilter);
	~StereoWidthCtrlAudioProcessorEditor();

	//==============================================================================

	void timerCallback() override;

	StereoWidthCtrlAudioProcessor* getProcessor() const
	{
		return static_cast<StereoWidthCtrlAudioProcessor*>(getAudioProcessor());
	}

	void paint(Graphics& g);
	void resized();
	void sliderValueChanged(Slider* sliderThatWasMoved);
	void buttonClicked(Button* buttonThatWasClicked);


private:

	AudioProcessorParameter* getParameterFromComponent(const Component*) const;
	//AudioProcessorParameter* getParameterFromComponent(const Slider*) const;

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


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StereoWidthCtrlAudioProcessorEditor)
};

#endif //JUCE_STEREO_WIDTH_PLUGIN_EDITOR

