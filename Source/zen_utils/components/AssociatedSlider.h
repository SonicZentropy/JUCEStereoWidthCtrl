/* ==============================================================================
//  AssociatedSlider.h
//  Part of the Zentropia JUCE Collection
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 8/21/2015
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the GNU license
//
//  Details: Contains a Slider component and its associated Parameter
===============================================================================*/


#ifndef ASSOCIATED_SLIDER_H_INCLUDED
#define ASSOCIATED_SLIDER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class AssociatedSlider : public Slider
{
public:

	AssociatedSlider(const String& componentName, AudioProcessorParameter* associatedParam);	
	AssociatedSlider(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel);

	AudioProcessorParameter* getAssociatedParameter() { return associatedParameter; };
	
	void setAssociatedParameter(AudioProcessorParameter* assocParam) { associatedParameter = assocParam; };	
	void setGUIValueNotifyingHost(const float& newValue);
	
private:
	AudioProcessorParameter* associatedParameter;
	String unitLabel;
};
#endif  // ASSOCIATED_SLIDER_H_INCLUDED