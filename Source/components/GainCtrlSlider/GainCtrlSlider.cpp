#include "GainCtrlSlider.h"
#include "../../zen_utils/juce_zen_utils.h"

#include "../../zen_utils/converters/DecibelConversions.h"
#include <sstream>
#include <iomanip>


GainCtrlSlider::GainCtrlSlider()
{
	DBG("SHOULD NEVER CALL THIS GainCtrlSlider.cpp CONSTRUCTOR");
	//normRange = new NormalisableRange<float>(-96.0f, 18.0f, 0.1f);
}

GainCtrlSlider::GainCtrlSlider(const String& componentName) 
	: AssociatedSlider(componentName)
{
	DBG("SHOULD NEVER CALL THIS GainCtrlSlider.cpp CONSTRUCTOR");
	//normRange = new NormalisableRange<float>(-96.0f, 18.0f, 0.1f);
}

GainCtrlSlider::GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam) 
	: AssociatedSlider(componentName, associatedParam)
{
	//normRange = new NormalisableRange<float>(-96.0f, 18.0f, 0.1f);
	setValue( associatedParam->getValue() );
	//setValue(Decibels::)
	
}

GainCtrlSlider::GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel)
	: AssociatedSlider(componentName, associatedParam, desiredUnitLabel)
{
	//DBG("18dB to Gain is : " + String(Decibels::decibelsToGain()));
	//
	//normRange = new NormalisableRange<float>(-96.0f, 18.0f, 0.1f);  ///FML This HAS to happen before setTextValueSuffix because setTextValueSuffix calls getText
	//float convertedRange = associatedParam->getValue();
	setValue( associatedParam->getValue());
	this->setTextValueSuffix(desiredUnitLabel);
}

GainCtrlSlider::GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel, const float& desiredMaxDBRange)
	: AssociatedSlider(componentName, associatedParam, desiredUnitLabel), maximumDecibelsInRange(desiredMaxDBRange)
{
	setValue(associatedParam->getValue());
	this->setTextValueSuffix(desiredUnitLabel);	
}

/// <summary>Gets GUI text from a given value by converting the value into Decibels</summary>
/// <param name="value">Input value where 0 represents -inf dB and 1.0 represents max Decibels in specified range</param>
/// <returns>String representing the input value in decibelsFS + Unit label</returns>
String GainCtrlSlider::getTextFromValue(double value)
{
	DBG("NormRange getValue: " + String(value));
	
	float gainInDecibels = DecibelConversions::gainToDecibelRange<float>(static_cast<float>(value), maximumDecibelsInRange, -96.0);
	if (gainInDecibels <= -96.0f)
	{
		return String("-INF dB");
	}
	else
	{
		std::stringstream gainRound;
		gainRound.setf(std::ios::fixed, std::ios::floatfield);
		gainRound << std::setprecision(2) << gainInDecibels;
	//	String test = gainRound.str();
		
		
		return String(String(gainRound.str()) + getTextValueSuffix());
	}
}

double GainCtrlSlider::getValueFromText(const String& text)
{	
	DBG("NormRange setValue: " + text);
	float rawValue = text.getFloatValue();
	float gainFromDecibels = DecibelConversions::decibelRangeToGain<float>(rawValue, maximumDecibelsInRange, -96.0);
	return gainFromDecibels;
}

GainCtrlSlider::~GainCtrlSlider()
{
	//normRange = nullptr;
	//delete normRange;
}

/*

void GainCtrlSlider::setGainFromDB(float gain)
{
//	convertToDecibels(gain);
	gainInDB = gain;
	audioGain = convertDecibelstoValue(gain);
	DBG("Setting Gain in GainCtrlSlider.cpp with DB = " + String(gain) + " and Value = " + String(audioGain));
}

void GainCtrlSlider::setGain(float gain)
{
	audioGain = gain;
}


float GainCtrlSlider::convertValueToDecibels(float gain)
{
	return static_cast<float>(Decibels::gainToDecibels(gain, 0.0f));
}

float GainCtrlSlider::convertDecibelstoValue(float gain)
{
	return static_cast<float>(Decibels::decibelsToGain(gain, -96.0f));
}

void GainCtrlSlider::processBufferSample(float* LeftSample, float* RightSample)
{
	//DBG("In Volume Clock Process gain is : " + String(audioGain));
	*LeftSample = *LeftSample * audioGain;
	*RightSample = *RightSample * audioGain;
}*/