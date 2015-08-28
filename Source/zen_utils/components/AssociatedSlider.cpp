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



AssociatedSlider::AssociatedSlider(const String& componentName, AudioProcessorParameter* associatedParam)
: Slider(componentName), associatedParameter(associatedParam)
{
	
}

AssociatedSlider::AssociatedSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel) 
: Slider(componentName), associatedParameter(associatedParam), unitLabel(desiredUnitLabel)
{
}

void AssociatedSlider::setGUIValueNotifyingHost(const float& newValue)
{
	jassert(associatedParameter->getProcessor() != nullptr && associatedParameter->getParameterIndex() >= 0);

	return associatedParameter->getProcessor()->setParameterNotifyingHost(associatedParameter->getParameterIndex(), newValue);
}