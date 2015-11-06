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
#define _USE_MATH_DEFINES
#include <math.h>

#ifndef M_PI_2  //Visual studio (maybe others) don't define this as part of the standard
#define M_PI_2 1.57079632679489661923
#endif

constexpr auto M_2PI = M_PI * 2;

clock_t BufferSampleProcesses::inTime = clock();
bool BufferSampleProcesses::shouldPrint = false;

void BufferSampleProcesses::processStereoWidth(float* leftSample, float* rightSample, const float& widthIn)
{
	float width = widthIn * 2;
	
	float balancedCoeff = 1 / std::max(1 + widthIn , 2.0f);
	
	float sumGain = balancedCoeff;  ///sumGain is gain coefficient for Mid
	float diffGain = width * balancedCoeff;  ///diffGain is gain coefficient for Side 

	float mid = sumGain * (*leftSample + *rightSample);
	float side = diffGain * (*rightSample - *leftSample);
	*leftSample = mid - side;
	*rightSample = mid + side;	
}

void BufferSampleProcesses::processGain(float* leftSample, float* rightSample, const float& gainValue)
{	
	*leftSample *= gainValue;
	*rightSample *= gainValue;
}

void BufferSampleProcesses::processInvertLeftChannel(float* leftSample)
{
	*leftSample *= -1;
}

void BufferSampleProcesses::processInvertRightChannel(float* rightSample)
{
	*rightSample *= -1;
}

void BufferSampleProcesses::processExtractMidSignal(float* leftSample, float* rightSample)
{
	float mid = *leftSample + *rightSample;
	*leftSample = mid;
	*rightSample = *leftSample;
}

void BufferSampleProcesses::processExtractSideSignal(float* leftSample, float* rightSample)
{
	float side = *leftSample - *rightSample;
	*leftSample = side;
	*rightSample = *leftSample;
}

void BufferSampleProcesses::processPanning(float* leftSample, float* rightSample, const float& panRatio)
{
	//can be optimized later, leaving for clarity. 6db compensated linear
	//float leftRatio = 1.0f - (panRatio);
	//float rightRatio = 0.0f + (panRatio);
	//*leftSample *= leftRatio;
	//*rightSample *= rightRatio;

	//non-compensated
	//float leftRatio = 1.0f - (panRatio);
	//float rightRatio = 0.0f + (panRatio);

	//sqrt compensation - preserves perceived volume but pan is no longer linear
	float leftRatio = sqrt(1.0f - panRatio);
	float rightRatio = sqrt(panRatio);
	*leftSample *= leftRatio;
	*rightSample *= rightRatio;
	
	// #TODO: fix sinusoidal ratio to work properly in middle
	// also not linear but perceived as such
	//float pan = panRatio * M_PI_2;
	//*leftSample *= cos(pan);
	//*rightSample *= sin(pan);

	/*
	float WaveTrack::GetChannelGain(int channel) const
	{
	float left = 1.0;
	float right = 1.0;

	#ifdef EXPERIMENTAL_OUTPUT_DISPLAY
	if(mVirtualStereo)
	channel = 3;
	#endif

	if (mPan < 0)
	right = (mPan + 1.0);
	else if (mPan > 0)
	left = 1.0 - mPan;

	if ((channel%2) == 0)
	return left*mGain;
	else
	return right*mGain;
	}
	*/

	//Elements of comp music
	//float x, y, thetaN, distn;
	//double pi = M_PI;

}