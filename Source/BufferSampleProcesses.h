/*
  ==============================================================================

    BufferSampleProcesses.h
    Created: 22 Aug 2015 6:45:51pm
    Author:  Zentropy

  ==============================================================================
*/

#ifndef BUFFER_SAMPLE_PROCESSES_H_INCLUDED
#define BUFFER_SAMPLE_PROCESSES_H_INCLUDED


class BufferSampleProcesses
{
public:

	static void processStereoWidth(float* LeftSample, float* RightSample, const float& widthValue);

	static void processGain(float* LeftSample, float* RightSample, const float& gainValue);
private:
	
};
#endif  // BUFFER_SAMPLE_PROCESSES_H_INCLUDED
