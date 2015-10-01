/*==============================================================================
//  PanSlider.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/10/01
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Panning control component.
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
===============================================================================*/

#ifndef PANSLIDER_H_INCLUDED
#define PANSLIDER_H_INCLUDED
#include "JuceHeader.h"
#include "../../zen_utils/components/AssociatedSlider.h"


class PanSlider : public AssociatedSlider
{
public:
	virtual String getTextFromValue(double value) override;

	//	PanSlider();
	PanSlider(const String& componentName, AudioProcessorParameter* associatedParam);
	PanSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel);
	~PanSlider();

private:

};

#endif // PANSLIDER_H_INCLUDED
