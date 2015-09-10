#ifndef GAINCTRLSLIDER_H_INCLUDED
#define GAINCTRLSLIDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../zen_utils/components/AssociatedSlider.h"


class GainCtrlSlider : public AssociatedSlider
{
public:

	GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam);
	GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel);
	GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel, const float& desiredMaxDBRange);
	
	~GainCtrlSlider();

	String getTextFromValue(double value) override;

	double getValueFromText(const String& text) override;

	float getMaximumDecibelsInRange() const { return maximumDecibelsInRange; }
	void setMaximumDecibelsInRange(float val) { maximumDecibelsInRange = val; }

private:

	float maximumDecibelsInRange = 0;
	
};
#endif  // GAINCTRLSLIDER_H_INCLUDED