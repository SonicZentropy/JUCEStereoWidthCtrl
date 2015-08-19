/*
  ==============================================================================

    gainSlider.h
    Created: 14 Aug 2015 4:48:22am
    Author:  Zentropy

  ==============================================================================
*/

#ifndef GAINSLIDER_H_INCLUDED
#define GAINSLIDER_H_INCLUDED






#include "../JuceLibraryCode/JuceHeader.h"

class GainSlider : public Slider
{
public:
	explicit GainSlider(const String& componentName);
	GainSlider(const String& componentName, AudioProcessorParameter* associatedParam);
	void setAssociatedParameter(AudioProcessorParameter* associatedParam);
	AudioProcessorParameter* getAssociatedParameter();
	String getTextFromValue(double value) override;
private:
	AudioProcessorParameter* associatedParameter;
};
#endif  // GAINSLIDER_H_INCLUDED