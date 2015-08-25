/*
  ==============================================================================

    BufferSampleProcesses.cpp
    Created: 22 Aug 2015 6:45:51pm
    Author:  Zentropy

  ==============================================================================
*/

#include "BufferSampleProcesses.h"
#include <algorithm>
#include "../JuceLibraryCode/JuceHeader.h"


void BufferSampleProcesses::processStereoWidth(float* LeftSample, float* RightSample, const float& widthIn)
{
	float width = widthIn * 2;
	
	float balancedCoeff = 1 / std::max(1 + widthIn , 2.0f);
	
	float sumGain = balancedCoeff;  ///sumGain is gain coefficient for Mid
	float diffGain = width * balancedCoeff;  ///diffGain is gain coefficient for Side 

	float mid = sumGain * (*LeftSample + *RightSample);
	float side = diffGain * (*RightSample - *LeftSample);
	*LeftSample = mid - side;
	*RightSample = mid + side;
	return;
}

void BufferSampleProcesses::processGain(float* LeftSample, float* RightSample, const float& gainValue)
{
	//DBG("In Volume Clock Process gain is : " + String(audioGain));
	*LeftSample = *LeftSample * gainValue;
	*RightSample = *RightSample * gainValue;
}