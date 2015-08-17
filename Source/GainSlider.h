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
	GainSlider(const String& componentName) : Slider(componentName) {};
	String getTextFromValue(double value) override;
};
#endif  // GAINSLIDER_H_INCLUDED