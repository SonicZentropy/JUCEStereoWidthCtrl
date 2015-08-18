/*
  ==============================================================================

    gainSlider.cpp
    Created: 14 Aug 2015 4:48:22am
    Author:  Zentropy

  ==============================================================================
*/

#include "gainSlider.h"


GainSlider::GainSlider(const String& componentName) : Slider(componentName)
{
	setTextValueSuffix("dB");
}

// Override Slider::getTextFromValue to force value to -inf display
String GainSlider::getTextFromValue(double value)
{

	if (value <= -95.0f) return String("-inf");
	if (getNumDecimalPlacesToDisplay() > 0)
		return String(value, getNumDecimalPlacesToDisplay()) + " " + getTextValueSuffix();

	return String(roundToInt(value)) + " " + getTextValueSuffix();
}