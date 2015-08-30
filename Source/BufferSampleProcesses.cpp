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
//#include "zen_utils/converters/DecibelConversions.h"
#include "zen_utils/Zen_Utils.h"
//#include <ctime>
//#include "boost/date_time/posix_time/posix_time.hpp"
//#include <boost/date_time/microsec_time_clock.hpp>

//using namespace boost::posix_time;

clock_t BufferSampleProcesses::inTime = clock();
bool BufferSampleProcesses::shouldPrint = false;

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
	float valueInDecibels = DecibelConversions::mapNormalizedValueToDecibels<float>(gainValue, 0.0, 1.0, 0.5, -96.0, 12.0, 0.0);	
	float rawGain = DecibelConversions::decibelsToGain<float>(valueInDecibels, -96.0f);
	
	*LeftSample = *LeftSample * rawGain;
	*RightSample = *RightSample * rawGain;

#ifdef DEBUG
	shouldPrint = ZenDebug::isPrintTimerThresholdReached();
	if (shouldPrint) DBG("Raw value being processed: " + String(gainValue));
	if (shouldPrint) DBG("Raw value converted to decibels to be processed: " + String(valueInDecibels));
	if (shouldPrint) DBG("Decibels converted to raw gain which will be used by each sample: " + String(rawGain));
	shouldPrint = false;
#endif
}