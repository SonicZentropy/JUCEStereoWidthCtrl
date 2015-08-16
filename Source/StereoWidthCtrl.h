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

#ifndef noexcept
#define noexcept throw()
#endif



#endif  // STEREOWIDTHCTRL_H_INCLUDED
#include "../../JUCEMain/modules/juce_core/maths/juce_NormalisableRange.h"

class StereoWidthCtrl
{
public:
	StereoWidthCtrl();
	~StereoWidthCtrl();

	//Parms
	void setWidth(float width);
	float getWidth(void) { return stereoWidthValue; };

	// Use
	void ClockProcess(float* LeftSample, float* RightSample);

private:
	float stereoWidthValue, sumGain, diffGain;
	NormalisableRange<float> normRange;


};
