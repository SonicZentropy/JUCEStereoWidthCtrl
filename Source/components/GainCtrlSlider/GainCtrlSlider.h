#ifndef GAINCTRLSLIDER_H_INCLUDED
#define GAINCTRLSLIDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../zen_utils/components/AssociatedSlider.h"


class GainCtrlSlider : public AssociatedSlider
{
public:

	GainCtrlSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel="dB", const float& desiredMaxDBRange=12.0f);
	
	~GainCtrlSlider();

	String getTextFromValue(double value) override;

	double getValueFromText(const String& text) override;

	float getMaximumDecibelsInRange() const { return maximumDecibelsInRange; }
	//void setMaximumDecibelsInRange(float val) { maximumDecibelsInRange = val; }

private:

	const float maximumDecibelsInRange;
	const float minimumDecibelsInRange;
	
};
#endif  // GAINCTRLSLIDER_H_INCLUDED