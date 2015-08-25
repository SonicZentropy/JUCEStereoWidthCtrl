/* ==============================================================================
//  AssociatedButton.cpp
//  Part of the Zentropia JUCE Collection
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 8/21/2015
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the GNU license
//
//  Details: Contains a Button component and its associated Parameter
===============================================================================*/


#include "AssociatedButton.h"

AssociatedButton::AssociatedButton() : Button("GLITCHASSOCIATEDBUTTONCONSTRUCTOR")
{
	DBG("SHOULD NEVER CALL THIS AssociatedButton CONSTRUCTOR");
}

// #TODO: Move this out of gain-specific and convert to generic derived Button that contains normalization methods
// No reason to ever use this constructor, technically
AssociatedButton::AssociatedButton(const String& componentName) : Button(componentName)
{
	DBG("You done goofed, should never call this constructor at all (AssociatedButton)");
}

AssociatedButton::AssociatedButton(const String& componentName, AudioProcessorParameter* associatedParam)
: Button(componentName), AssociatedParameter(associatedParam)
{
	
}

AssociatedButton::AssociatedButton(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel) 
: Button(componentName), AssociatedParameter(associatedParam), unitLabel(desiredUnitLabel)
{
}

// Override Button::getTextFromValue to force value to -inf display
// #TODO: Move this getTextFromValue out of AssociatedButton
/*String AssociatedButton::getTextFromValue(double value)
{

	if (value <= -95.0f) return String("-inf");
	if (getNumDecimalPlacesToDisplay() > 0)
		return String(value, getNumDecimalPlacesToDisplay()) + " " + getTextValueSuffix();

	return String(roundToInt(value)) + " " + getTextValueSuffix();
}*/