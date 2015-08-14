/*
  ==============================================================================

    VolumeInDB.h
    Created: 13 Aug 2015 5:57:08am
    Author:  Zentropy

  ==============================================================================
*/

#ifndef VOLUMEINDB_H_INCLUDED
#define VOLUMEINDB_H_INCLUDED





#endif  // VOLUMEINDB_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

class VolumeInDB
{
public:
	VolumeInDB();
	~VolumeInDB();

	//Parms
	void setGain(float gain);
	float getWidth(void) { return audioGain; };
	

	// Use
	void ClockProcess(float* LeftSample, float* RightSample);

private:
	float audioGain;
};
