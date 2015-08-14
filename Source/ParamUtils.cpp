/*
  ==============================================================================

    ParamUtil.cpp
    Created: 14 Aug 2015 7:44:55am
    Author:  Zentropy

	Use the inverse functions in 'getParameter' and 'setParameterNotifyingHost'
	and the non-inverse in 'setParamer'. The warp functions, borrowed from JUCE's
	slider class allow you to set a value you wish to be represented by 0.5 - 
	useful for frequency control for example. The intStep functions allow integers
	to be represented and the Bool is self explanatory

  ==============================================================================
*/

#include "ParamUtil.h"

float warp(float x, float max, float min, float mid)
{
	float sf = warpCoefficients(max, min, mid);

	float y = exp(log(x) / sf);

	return min + (max - min) * y;;
}

float inverseWarp(float x, float max, float min, float mid)
{
	float sf = warpCoefficients(max, min, mid);

	float n = (x - min) / (max - min);

	return pow(n, sf);
}

float warpCoefficients(float max, float min, float mid)
{
	float  skewFactor = log(0.5f) / log((mid - min)
		/ (max - min));

	return skewFactor;
}

float linear(float x, float max, float min)
{
	return min + (max - min) * x;
}

float inverseLinear(float x, float max, float min)
{
	return (x - min) / (max - min);
}

int intStep(float x, int max, int min)
{
	return min + (int)((float)(max - min) * x + 0.5f);
}

float inverseIntStep(int x, int max, int min)
{
	return (float)(x - min) / (float)(max - min);
}

bool boolStep(float x)
{
	if (x < 0.5)
		return false;
	else
		return true;
}

float inverseBoolStep(bool x)
{
	if (x)
		return 1.0;
	else
		return 0.0;
}
