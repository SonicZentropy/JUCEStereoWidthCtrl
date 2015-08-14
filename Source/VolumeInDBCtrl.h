/*
  ==============================================================================

    VolumeInDBCtrl.h
    Created: 13 Aug 2015 5:57:08am
    Author:  Zentropy

  ==============================================================================
*/

#ifndef VOLUMEINDB_H_INCLUDED
#define VOLUMEINDB_H_INCLUDED





#endif  // VOLUMEINDB_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"


class VolumeInDBCtrl
{
public:
	VolumeInDBCtrl();
	~VolumeInDBCtrl();

	//Parms
	void setGainFromDB(float gain);
	void setGain(float gain);
	float getWidth(void) { return audioGain; };
	float convertValueToDecibels(float gain);
	float convertDecibelstoValue(float gainInDB);

	// Use
	void ClockProcess(float* LeftSample, float* RightSample);

private:
	float audioGain, gainInDB;
//	Decibels decibelsRep;
};
