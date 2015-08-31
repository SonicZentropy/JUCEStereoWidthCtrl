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
//	DBG("Entered method: FloatParameter:getValue()");
	return value;
}

void FloatParameter::setValue(float newValue)
{
	//DBG("Entered method: FloatParameter:setValue(newValue) with value: " + String(newValue));
	value = newValue;
	requestUIUpdate = true;
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

void FloatParameter::setValueNotifyingHost(float newValue)
{
	AudioProcessor* processor = getProcessor();
	// This method can't be used until the parameter has been attached to a processor!
	jassert(processor != nullptr && getParameterIndex() >= 0);
	processor->setParameterNotifyingHost(getParameterIndex(), newValue);
	requestUIUpdate = false;  //set this to false because change came from GUI
	return;
}

bool FloatParameter::needsUIUpdate()
{
	bool updateSet = requestUIUpdate;
	requestUIUpdate = false;
	return updateSet;
}

float FloatParameter::getValueForText(const String& text) const
{
	return text.getFloatValue();
}

void FloatParameter::setLabel(const String& inLabel)
{
	unitLabel = inLabel;
}

