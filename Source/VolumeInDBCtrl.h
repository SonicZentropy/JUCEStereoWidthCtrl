#ifndef VOLUMEINDB_H_INCLUDED

#define VOLUMEINDB_H_INCLUDED






#include "../JuceLibraryCode/JuceHeader.h"


class VolumeInDBCtrl
{
public:
	VolumeInDBCtrl();
	~VolumeInDBCtrl();

	void setGainFromDB(float gain);

	void setGain(float gain);

	float getGain(void) { return audioGain; };

	float convertValueToDecibels(float gain);

	float convertDecibelstoValue(float gainInDB);


	void ClockProcess(float* LeftSample, float* RightSample);

private:


	float audioGain, gainInDB;


};
#endif  // VOLUMEINDB_H_INCLUDED