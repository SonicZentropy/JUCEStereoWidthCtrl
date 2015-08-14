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

#include "VolumeInDBCtrl.h"

VolumeInDBCtrl::VolumeInDBCtrl()
{
	setGain(1.0f);
}

VolumeInDBCtrl::~VolumeInDBCtrl()
{
	
}

void VolumeInDBCtrl::setGainFromDB(float gain)
{
//	convertToDecibels(gain);
	gainInDB = gain;
	audioGain = convertDecibelstoValue(gain);
	DBG("Setting Gain in VolumeInDBCtrl.cpp with DB = " + String(gain) + " and Value = " + String(audioGain));
}

void VolumeInDBCtrl::setGain(float gain)
{
	audioGain = gain;
}

float VolumeInDBCtrl::convertValueToDecibels(float gain)
{
	return static_cast<float>(Decibels::gainToDecibels(gain, 0.0f));
}

float VolumeInDBCtrl::convertDecibelstoValue(float gain)
{
	return static_cast<float>(Decibels::decibelsToGain(gain, -96.0f));
}


void VolumeInDBCtrl::ClockProcess(float* LeftSample, float* RightSample)
{
	//DBG("In Volume Clock Process gain is : " + String(audioGain));
	*LeftSample = *LeftSample * audioGain;
	*RightSample = *RightSample * audioGain;
}