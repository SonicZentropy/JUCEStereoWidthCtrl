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
#include <cmath>

#ifndef M_PI_2  //Visual studio (maybe others) don't define this as part of the standard
#define M_PI_2 1.57079632679489661923
#endif

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
	//float leftRatio = 2.0f - (panRatio * 2);
	//float rightRatio = 0.0f + (panRatio * 2);
	//*leftSample *= leftRatio;
	//*rightSample *= rightRatio;

	//non-compensated
	//float leftRatio = 1.0f - (panRatio);
	//float rightRatio = 0.0f + (panRatio);

	//sqrt compensation - preserves perceived volume but pan is no longer linear
	//float leftRatio = sqrt(1.0f - panRatio);
	//float rightRatio = sqrt(panRatio);
	
	// #TODO: fix sinusoidal ratio to work properly in middle
	// also not linear but perceived as such
	float pan = panRatio * M_PI_2;
	*leftSample *= cos(pan);
	*rightSample *= sin(pan);
}