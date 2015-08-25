/*
  ==============================================================================

    StereoWidthCtrl.h
    Created: 12 Aug 2015 1:39:08am
    Author:  Zentropy
	Volume-Normalized Stereo Width Control - DSP from Michael Gruhn
	'width' is stretch factor of stereo field:
	width < 1: decrease stereo width
	width = 1: no change
	width > 1: increase width
	width = 0: MONO conversion

  ==============================================================================
*/

#ifndef STEREOWIDTHCTRL_H_INCLUDED
#define STEREOWIDTHCTRL_H_INCLUDED

//#TODO: Fix VS version stuff
//#if defined (_MSC_VER) && _MSC_VER > 1600
//#define _ALLOW_KEYWORD_MACROS 1 // (to stop VC2012 complaining)
//#endif

//#undef noexcept
//#define noexcept throw()

#include "juce_core/maths/juce_NormalisableRange.h"
//#include "../../JUCEMain/modules/juce_core/maths/juce_NormalisableRange.h"
#include "../../zen_utils/components/AssociatedSlider.h"



class StereoWidthCtrlSlider : public AssociatedSlider
{
public:
	//StereoWidthCtrl();
	StereoWidthCtrlSlider();
	explicit StereoWidthCtrlSlider(const String& componentName);
	StereoWidthCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam);
	StereoWidthCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel);
	~StereoWidthCtrlSlider();

	String getTextFromValue(double value) override;

	//Parms
//	void setWidth(const float& width);

	
private:
	float stereoWidthValue, sumGain, diffGain;
	NormalisableRange<float> normRange;


};

#endif  // STEREOWIDTHCTRL_H_INCLUDED
