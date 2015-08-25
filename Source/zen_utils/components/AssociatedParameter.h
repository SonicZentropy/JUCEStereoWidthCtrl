/* ==============================================================================
//  AssociatedParameter.cpp
//  Part of the Zentropia JUCE Collection
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/08/21
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the GNU license
//
//  Details: Class that creates reference to a parameter, utilized by Component Classes
================================================================================*/

#ifndef ASSOCIATED_PARAMETER_H_INCLUDED
#define ASSOCIATED_PARAMETER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class AssociatedParameter
{

public:
	AssociatedParameter();
	explicit AssociatedParameter(AudioProcessorParameter* associatedParam);
 	void setAssociatedParameter(AudioProcessorParameter* associatedParam);
 	AudioProcessorParameter* getAssociatedParameter() const;
	
private:
 	AudioProcessorParameter* associatedParameter;

};
#endif  // ASSOCIATED_PARAMETER_H_INCLUDED