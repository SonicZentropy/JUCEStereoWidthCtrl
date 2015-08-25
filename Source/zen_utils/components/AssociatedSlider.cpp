/* ==============================================================================
//  AssociatedSlider.cpp
//  Part of the Zentropia JUCE Collection
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 8/21/2015
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the GNU license
//
//  Details: Contains a Slider component and its associated Parameter
===============================================================================*/


#include "AssociatedSlider.h"

AssociatedSlider::AssociatedSlider()
{
	DBG("SHOULD NEVER CALL THIS AssociatedSlider.cpp CONSTRUCTOR");
}

// TODO: Move this out of gain-specific and convert to generic derived Slider that contains normalization methods
// No reason to ever use this constructor, technically
AssociatedSlider::AssociatedSlider(const String& componentName) : Slider(componentName)
{
	DBG("You done goofed, should never call this constructor at all (AssociatedSlider)");
}

AssociatedSlider::AssociatedSlider(const String& componentName, AudioProcessorParameter* associatedParam)
: Slider(componentName), AssociatedParameter(associatedParam)
{
	
}

AssociatedSlider::AssociatedSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel) 
: Slider(componentName), AssociatedParameter(associatedParam), unitLabel(desiredUnitLabel)
{
}

// Override Slider::getTextFromValue to force value to -inf display
// TODO: Move this getTextFromValue out of AssociatedSlider into GainSlider
/*String AssociatedSlider::getTextFromValue(double value)
{

	if (value <= -95.0f) return String("-inf");
	if (getNumDecimalPlacesToDisplay() > 0)
		return String(value, getNumDecimalPlacesToDisplay()) + " " + getTextValueSuffix();

	return String(roundToInt(value)) + " " + getTextValueSuffix();
}*/