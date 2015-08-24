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
#include "zen_utils/juce_zen_utils.h"
//#include "AssociatedSlider.h"
//#include <exception>

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
	explicit StereoWidthCtrlAudioProcessorEditor(StereoWidthCtrlAudioProcessor& ownerFilter);
	~StereoWidthCtrlAudioProcessorEditor();

	//==============================================================================

	void timerCallback() override;

	StereoWidthCtrlAudioProcessor* getProcessor() const
	{
		return static_cast<StereoWidthCtrlAudioProcessor*>(getAudioProcessor());
	}

	void paint(Graphics& g) override;
	void resized() override;
	void sliderValueChanged(Slider* sliderThatWasMoved) override;
	void associatedSliderValueChanged(AssociatedSlider* sliderThatWasMoved);
	void buttonClicked(Button* buttonThatWasClicked) override;


private:

	//AudioProcessorParameter* getParameterFromComponent(const Component*) const;
	// //AudioProcessorParameter* getParameterFromComponent(const Slider*) const;

	//==============================================================================
 	ScopedPointer<StereoWidthCtrlSlider> stereoWidthSldCtrl;
 	ScopedPointer<TextButton> bypassBtnCtrl;
 	ScopedPointer<Label> widthLabel;
 	ScopedPointer<TextButton> muteBtnCtrl;
 	ScopedPointer<AssociatedSlider> gainSldCtrl;
 	ScopedPointer<TextButton> lockGainBtnCtrl;
 	ScopedPointer<ToggleButton> invertLeftBtnCtrl;
 	ScopedPointer<ToggleButton> invertRightBtnCtrl;
 	ScopedPointer<Label> invertLabel;


	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StereoWidthCtrlAudioProcessorEditor)
};

#endif //JUCE_STEREO_WIDTH_PLUGIN_EDITOR

