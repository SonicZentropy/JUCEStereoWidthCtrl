/* ==============================================================================
//  BufferSampleProcesses.h
//  Part of the Zentropia JUCE Collection
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/09/01
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the GNU license
//
//  Details: All Static Methods for discrete sample processing live here
//	and are generally called from PluginEditor.cpp
================================================================================*/

#ifndef BUFFER_SAMPLE_PROCESSES_H_INCLUDED
#define BUFFER_SAMPLE_PROCESSES_H_INCLUDED
#include <ctime>

class BufferSampleProcesses
{
public:

	static void processStereoWidth(float* leftSample, float* rightSample, const float& widthValue);

	static void processGain(float* leftSample, float* rightSample, const float& gainValue);


	static void processInvertLeftChannel(float* leftSample);
	static void processInvertRightChannel(float* rightSample);

	static void processExtractMidSignal(float* leftSample, float* rightSample);
	static void processExtractSideSignal(float* leftSample, float* rightSample);

	static void processPanning(float* leftSample, float* rightSample, const float& panRatio);
private:
	static clock_t inTime;
	static bool shouldPrint;
};
#endif  // BUFFER_SAMPLE_PROCESSES_H_INCLUDED
