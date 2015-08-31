/* ==============================================================================
//  ZenDebug.cpp
//  Part of the Zentropia JUCE Collection
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/08/30
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the GNU license
//
//  Details: Static Utility Class for Debug-related code
================================================================================*/

#include "ZenDebug.h"

clock_t ZenDebug::inTime = clock();

int ZenDebug::numSecondsBetweenDebugPrints = 1;

void ZenDebug::setSecondsBetweenDebugPrints(const int& inSeconds)
{
	numSecondsBetweenDebugPrints = inSeconds;
}

int ZenDebug::getSecondsBetweenDebugPrints()
{
	return numSecondsBetweenDebugPrints;
}

bool ZenDebug::isPrintTimerThresholdReached()
{
	
	if (((clock() - inTime) / CLOCKS_PER_SEC) > numSecondsBetweenDebugPrints)
	{
		inTime = clock();
		return true;
	}
	return false;
}