/*==============================================================================
//  PanSlider.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/10/01
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Panning control component.
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#include "PanSlider.h"

PanSlider::PanSlider(const String& componentName, AudioProcessorParameter* associatedParam)
	:AssociatedSlider(componentName, associatedParam)
{}

PanSlider::PanSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel)
	:AssociatedSlider(componentName, associatedParam, desiredUnitLabel)
{}



PanSlider::~PanSlider()
{}


String PanSlider::getTextFromValue(double value)
{
	String temp = String(abs(value));
	if (value < 0) temp += "L";
	if (value > 0) temp += "R";
	return temp;
}



