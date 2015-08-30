#ifndef ZEN_BOOL_PARAMETER_H_INCLUDED
#define ZEN_BOOL_PARAMETER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

namespace juce
{
	class BoolParameter : public AudioProcessorParameter
	{
	
	public:

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
		
		virtual float getDefaultValue() const override;
		void setDefaultValue(float inValue);
		void setDefaultValue(bool inValue);
				
		virtual String getName(int maximumStringLength) const override;

		void setLabel(const String& inLabel);
		virtual String getLabel() const override;
		virtual float getValueForText(const String& text) const override;

// 		virtual bool isMetaParameter() const override;
// 
// 		virtual int getNumSteps() const override;
// 
// 		virtual bool isAutomatable() const override;
// 		virtual bool isOrientationInverted() const override;
// 		virtual String getText(bool value, int) const override;

	private:
		bool defaultValue, value;
		String name, unitLabel;
	};

}
#endif   // ZEN_BOOL_PARAMETER_H_INCLUDED