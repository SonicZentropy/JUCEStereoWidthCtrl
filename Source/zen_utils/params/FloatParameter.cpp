/* ==============================================================================
//  FloatParameter.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/08/18
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Derived AudioProcessorParameter for Float values.  Pure
//  virtual methods that must be overridden:
//   destructor
//   getValue
//   setValue
//   getDefaultValue
//   getName
//   getLabel (units string, example "Hz" or "%")
//   getValueForText (parse a String and return appropriate value for it)
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/
#pragma warning (disable : 4100 )

#include "FloatParameter.h"

FloatParameter::FloatParameter(float defaultParameterValue, const String& paramName)
	: defaultValue(defaultParameterValue),
	value(defaultParameterValue),
	name(paramName)
{
}

FloatParameter::~FloatParameter()
{
		
}

float FloatParameter::getValue() const
{
	DBG("Entered method: FloatParameter:getValue()");
	return value;
}

void FloatParameter::setValue(float newValue)
{
	DBG("Entered method: FloatParameter:setValue(newValue) with value: " + String(newValue));
	value = newValue;
}

float FloatParameter::getDefaultValue() const
{
	return defaultValue;
}

String FloatParameter::getName(int maximumStringLength) const
{
	return name;
}

String FloatParameter::getLabel() const
{
	return unitLabel;
}

float FloatParameter::getValueForText(const String& text) const
{
	return text.getFloatValue();
}

void FloatParameter::setLabel(const String& inLabel)
{
	unitLabel = inLabel;
}

