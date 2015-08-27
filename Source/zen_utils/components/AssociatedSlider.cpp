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

// No reason to ever use this constructor, technically
AssociatedSlider::AssociatedSlider()
{
	DBG("Should never call this constructor at all (AssociatedSlider)");
}

// No reason to ever use this constructor, technically
AssociatedSlider::AssociatedSlider(const String& componentName) : Slider(componentName)
{
	DBG("Should never call this constructor at all (AssociatedSlider)");
}

AssociatedSlider::AssociatedSlider(const String& componentName, AudioProcessorParameter* associatedParam)
: Slider(componentName), AssociatedParameter(associatedParam)
{
	
}

AssociatedSlider::AssociatedSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel) 
: Slider(componentName), AssociatedParameter(associatedParam), unitLabel(desiredUnitLabel)
{
}
