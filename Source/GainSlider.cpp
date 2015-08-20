/*
  ==============================================================================

    gainSlider.cpp
    Created: 14 Aug 2015 4:48:22am
    Author:  Zentropy

  ==============================================================================
*/

#include "gainSlider.h"

// #TODO: Move this out of gain-specific and convert to generic derived Slider that contains normalization methods
GainSlider::GainSlider(const String& componentName) : Slider(componentName)
{
	setTextValueSuffix("dB");
}

GainSlider::GainSlider(const String& componentName, AudioProcessorParameter* associatedParam) : Slider(componentName)
{
	setTextValueSuffix("dB");
	associatedParameter = associatedParam;
}

void GainSlider::setAssociatedParameter(AudioProcessorParameter* associatedParam)
{
	associatedParameter = associatedParam;
}

AudioProcessorParameter* GainSlider::getAssociatedParameter() const
{
	return associatedParameter;
}

// Override Slider::getTextFromValue to force value to -inf display
String GainSlider::getTextFromValue(double value)
{

	if (value <= -95.0f) return String("-inf");
	if (getNumDecimalPlacesToDisplay() > 0)
		return String(value, getNumDecimalPlacesToDisplay()) + " " + getTextValueSuffix();

	return String(roundToInt(value)) + " " + getTextValueSuffix();
}