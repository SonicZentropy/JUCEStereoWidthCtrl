#ifndef ZEN_BOOL_PARAMETER_H_INCLUDED
#define ZEN_BOOL_PARAMETER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class BoolParameter : public AudioProcessorParameter
{
	
public:

	BoolParameter();
	BoolParameter(bool defaultParameterValue, const String& paramName);
	BoolParameter(float defaultParameterValue, const String& paramName);
	BoolParameter(bool defaultParameterValue, const String& paramName, const String& desiredUnitsLabel);
	BoolParameter(float defaultParameterValue, const String& paramName, const String& desiredUnitsLabel);
	~BoolParameter();

	bool convertFloatToBoolean(const float& inFloat) const;
	float convertBooleanToFloat(const bool& inBool) const;

	virtual float getValue() const override;
	bool getBooleanValue() const;	
	virtual void setValue(float newValue) override;
	void setValue(bool newValue);
	void setValueFromFloat(const float& inFloat);
	virtual float getDefaultValue() const override;
	void setDefaultValue(float inValue);
	void setDefaultValue(bool inValue);
				
	virtual String getName(int maximumStringLength) const override;

	void setLabel(const String& inLabel);
	virtual String getLabel() const override;
	virtual float getValueForText(const String& text) const override;
	// ReSharper disable once CppHidingFunction
	void setValueNotifyingHost(float newValue); //Juce's AudioProcessorParameter method is hidden on purpose, don't want to make it virutal in case of updates to Juce causing me to fail to re-set it to virtual

	bool needsUIUpdate();

private:
	bool defaultValue, value;
	bool requestUIUpdate = true;
	String name, unitLabel;
};

#endif   // ZEN_BOOL_PARAMETER_H_INCLUDED