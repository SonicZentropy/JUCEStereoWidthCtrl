/* ==============================================================================
//  AssociatedButton.h
//  Part of the Zentropia JUCE Collection
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 8/21/2015
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the GNU license
//
//  Details: Contains a Button component and its associated Parameter
===============================================================================*/


#ifndef ASSOCIATED_BUTTON_H_INCLUDED
#define ASSOCIATED_BUTTON_H_INCLUDED
// TODO: Convert this to new superclass that only adds the param pointers

#include "../JuceLibraryCode/JuceHeader.h"
#include "AssociatedParameter.h"

class AssociatedButton : public Button, public AssociatedParameter
{
public:

	AssociatedButton();
	explicit AssociatedButton(const String& componentName);
	AssociatedButton(const String& componentName, AudioProcessorParameter* associatedParam);	
	AssociatedButton(const String& componentName, AudioProcessorParameter* associatedParam, const String& desiredUnitLabel);

	
	
//	String getTextFromValue(double value) override;
private:
	String unitLabel;
};
#endif  // ASSOCIATED_BUTTON_H_INCLUDED