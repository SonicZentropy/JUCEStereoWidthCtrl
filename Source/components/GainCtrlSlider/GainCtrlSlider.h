#ifndef GAINCTRLSLIDER_H_INCLUDED
#define GAINCTRLSLIDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "juce_core/maths/juce_NormalisableRange.h"
#include "../../zen_utils/components/AssociatedSlider.h"
#include "zen_utils/juce_zen_utils.h"

class GainCtrlSlider : public AssociatedSlider
{
public:
	GainCtrlSlider();
	explicit GainCtrlSlider(const String& componentName);
	GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam);
	GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel);
	GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel, const float& desiredMaxDBRange);
	
	~GainCtrlSlider();

	String getTextFromValue(double value) override;

	double getValueFromText(const String& text) override;

	float getMaximumDecibelsInRange() const { return maximumDecibelsInRange; }
	void setMaximumDecibelsInRange(float val) { maximumDecibelsInRange = val; }
/*
	void setGainFromDB(float gain);

	void setGain(float gain);

	float getGain(void) { return audioGain; };

	float convertValueToDecibels(float gain);

	float convertDecibelstoValue(float gainInDB);


	void processBufferSample(float* LeftSample, float* RightSample);*/

private:

	//ScopedPointer<NormalisableRange<float>> normRange;
	//NormalisableRange<float>* normRange;
	float maximumDecibelsInRange = 0;
	
	//ScopedPointer<GainCtrlSlider> pointRange;

};
#endif  // GAINCTRLSLIDER_H_INCLUDED