/*
  ==============================================================================

    StereoWidthCtrl.cpp
    Created: 12 Aug 2015 1:38:56am
    Author:  Zentropy

  ==============================================================================
*/

#include "StereoWidthCtrl.h"

StereoWidthCtrl::StereoWidthCtrl()
{
	setWidth(1.0f);
}

StereoWidthCtrl::~StereoWidthCtrl()
{
	
}

void StereoWidthCtrl::setWidth(float width)
{
	stereoWidthValue = width * 2;
	float temp;
	if (1.0f + width > 2.0f)
	{
		temp = 1.0f / (1.0f + stereoWidthValue);
	}
	else temp = 1.0f / 2.0f;
	diffGain = stereoWidthValue * temp;  ///diffGain is gain coefficient for Side 
	sumGain = temp;  ///sumGain is gain coefficient for Mid
}

void StereoWidthCtrl::ClockProcess(float* LeftSample, float* RightSample)
{
	float mid = sumGain * (*LeftSample + *RightSample);
	float side = diffGain * (*RightSample - *LeftSample);
	*LeftSample = mid - side;
	*RightSample = mid + side;
}



