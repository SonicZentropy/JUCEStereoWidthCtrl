/*
  ==============================================================================

    BufferSampleProcesses.h
    Created: 22 Aug 2015 6:45:51pm
    Author:  Zentropy

  ==============================================================================
*/

#ifndef BUFFER_SAMPLE_PROCESSES_H_INCLUDED
#define BUFFER_SAMPLE_PROCESSES_H_INCLUDED
#include <ctime>

class BufferSampleProcesses
{
public:

	static void processStereoWidth(float* LeftSample, float* RightSample, const float& widthValue);

	static void processGain(float* LeftSample, float* RightSample, const float& gainValue, clock_t* inTime);
private:
	
};
#endif  // BUFFER_SAMPLE_PROCESSES_H_INCLUDED
