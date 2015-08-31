/*
  ==============================================================================

    StereoWidthCtrlSlider.cpp
    Created: 12 Aug 2015 1:38:56am
    Author:  Zentropy

  ==============================================================================
*/

#pragma warning(disable:4702) // Get rid of warnings about unreachable code from the throws

#include "StereoWidthCtrlSlider.h"

StereoWidthCtrlSlider::StereoWidthCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam)
	: AssociatedSlider(componentName, associatedParam)
{
	setValue(associatedParam->getValue());
}

StereoWidthCtrlSlider::StereoWidthCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel)
	: AssociatedSlider(componentName, associatedParam, desiredUnitLabel)
{
	this->setTextValueSuffix(desiredUnitLabel);
}



StereoWidthCtrlSlider::~StereoWidthCtrlSlider()
{
	
}

String StereoWidthCtrlSlider::getTextFromValue(double value)
{
	
	return String( String(value * 200.0f) + this->getTextValueSuffix());
}

double StereoWidthCtrlSlider::getValueFromText(const String& text)
{
	double parsedValue = text.getDoubleValue();
	parsedValue /= 200.0f;
	return parsedValue;
}
