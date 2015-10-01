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
#ifndef ZEN_FLOAT_PARAMETER_H_INCLUDED
#define ZEN_FLOAT_PARAMETER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class FloatParameter : public AudioProcessorParameter
{
	
public:

	FloatParameter(float defaultParameterValue, const String& paramName);
	~FloatParameter();

	virtual float getValue() const override;
	virtual void setValue(float newValue) override;
	virtual float getDefaultValue() const override;
	virtual String getName(int maximumStringLength) const override;
	virtual float getValueForText(const String& text) const override;
	virtual String getLabel() const override;
	// ReSharper disable once CppHidingFunction
	void setValueNotifyingHost(float newValue) override; 

	bool needsUIUpdate();
	void setLabel(const String& inLabel);
	

private:
	float defaultValue, value;
	bool requestUIUpdate = true;
	String name, unitLabel;
};

#endif   // ZEN_FLOAT_PARAMETER_H_INCLUDED