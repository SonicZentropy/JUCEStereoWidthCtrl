#include "GainCtrlSlider.h"

#include "../../zen_utils/converters/DecibelConversions.h"
#include <sstream>
#include <iomanip>



GainCtrlSlider::GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel, const float& desiredMaxDBRange)
	: AssociatedSlider(componentName, associatedParam, desiredUnitLabel), maximumDecibelsInRange(desiredMaxDBRange), minimumDecibelsInRange(-96.0f)
{
	setValue(associatedParam->getValue());
	this->setTextValueSuffix(desiredUnitLabel);	
}

/// <summary>Gets GUI text from a given value by converting the value into Decibels</summary>
/// <param name="value">Input value where 0 represents -inf dB and 1.0 represents max Decibels in specified range</param>
/// <returns>String representing the input value in decibelsFS + Unit label</returns>
String GainCtrlSlider::getTextFromValue(double value)
{
	float decibelsFromGain = static_cast<float>(DecibelConversions::mapNormalizedValueToDecibels<float>(static_cast<float>(value), 0.0, 1.0, 0.5, minimumDecibelsInRange, maximumDecibelsInRange, 0.0));
	if (decibelsFromGain <= -96.0f)
	{
		return String("-INF dB");
	}
	else
	{
		std::stringstream gainRound;
		gainRound.setf(std::ios::fixed, std::ios::floatfield);
		gainRound << std::setprecision(2) << static_cast<float>(decibelsFromGain);
		
		return String(String(gainRound.str()) + getTextValueSuffix());
	}
}

double GainCtrlSlider::getValueFromText(const String& text)
{	
	
	float rawValue = text.getFloatValue();
	float gainFromDecibels = DecibelConversions::mapDecibelsToProperNormalizedValue<float>(rawValue, 0.0, 1.0, 0.5, minimumDecibelsInRange, maximumDecibelsInRange, 0.0);
	
	return gainFromDecibels;
}

GainCtrlSlider::~GainCtrlSlider()
{
	
}
