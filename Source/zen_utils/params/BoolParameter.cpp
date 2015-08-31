/* ==============================================================================
//  BoolParameter.cpp
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/08/18
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Derived AudioProcessorParameter for Bool values.  Pure
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

#include "BoolParameter.h"

BoolParameter::BoolParameter()
{
	//value = false;
	//defaultValue = false;
}
	BoolParameter::BoolParameter(bool defaultParameterValue, const String& paramName)
		: defaultValue(defaultParameterValue),
		value(defaultParameterValue),
		name(paramName),
		unitLabel("")
	{
	}

	BoolParameter::BoolParameter(float defaultParameterValue, const String& paramName)
		: name(paramName),
		unitLabel("")
	{
		setValueFromFloat(defaultParameterValue);
		setDefaultValue(defaultParameterValue);
	}

	BoolParameter::BoolParameter(bool defaultParameterValue, const String& paramName, const String& desiredUnitsLabel)
		: defaultValue(defaultParameterValue),
		value(defaultParameterValue),
		name(paramName),
		unitLabel(desiredUnitsLabel)
	{
	}

	BoolParameter::BoolParameter(float defaultParameterValue, const String& paramName, const String& desiredUnitsLabel)
		: name(paramName),
		unitLabel(desiredUnitsLabel)
	{
		setValueFromFloat(defaultParameterValue);
		setDefaultValue(defaultParameterValue);
	}

	float BoolParameter::convertBooleanToFloat(const bool& inBool) const
	{
		if (inBool == false) return 0.0f;
		else return 1.0f;
	}

	bool BoolParameter::convertFloatToBoolean(const float& inFloat) const
	{
		if (inFloat == 0.0f) return false;
		else return true;
	}

	BoolParameter::~BoolParameter()
	{
		
	}

	bool BoolParameter::getBooleanValue() const
	{
		return value;
	}

	float BoolParameter::getValue() const
	{
		return convertBooleanToFloat(value);
		//return value;
	}

	void BoolParameter::setValue(float newValue)
	{
		setValueFromFloat(newValue);

	}
	
	void BoolParameter::setValue(bool newValue)
	{
		value = newValue;
	}

	void BoolParameter::setValueFromFloat(const float& inFloat)
	{
		value = convertFloatToBoolean(inFloat);
	}
	
	void BoolParameter::setDefaultValue(float inFloat)
	{
		defaultValue = convertFloatToBoolean(inFloat);
	}
	
	float BoolParameter::getDefaultValue() const
	{
		return convertBooleanToFloat(defaultValue);
	}

	void BoolParameter::setDefaultValue(bool inBool)
	{
		defaultValue = inBool;
	}

	String BoolParameter::getName(int maximumStringLength) const
	{
		return name;
	}

	String BoolParameter::getLabel() const
	{
		return unitLabel;
	}

	void BoolParameter::setLabel(const String& inLabel)
	{
		unitLabel = inLabel;
	}

	float BoolParameter::getValueForText(const String& text) const
	{
		return text.getFloatValue();
	}

