/*
  ==============================================================================

    VolumeInDB.cpp
    Created: 13 Aug 2015 5:57:08am
    Author:  Zentropy
	Changes transmission gain of incoming audio based on decibels.
	Gain = 20 x log (Voltage out/Voltage in) or
	Gain = 10 x log (Power Out / Power In) -> Normally used in Audio applications

  ==============================================================================
*/

#include "VolumeInDB.h"

VolumeInDB::VolumeInDB()
{
	setGain(1.0f);
}

VolumeInDB::~VolumeInDB()
{
	
}

void VolumeInDB::setGain(float gain)
{
	DBG("Setting Gain in VolumeInDB.cpp");
	audioGain = gain;
}

void VolumeInDB::ClockProcess(float* LeftSample, float* RightSample)
{
	*LeftSample = *LeftSample * audioGain;
	*RightSample = *RightSample * audioGain;
}