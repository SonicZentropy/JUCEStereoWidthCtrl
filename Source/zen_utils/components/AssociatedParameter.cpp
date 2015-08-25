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

#include "AssociatedParameter.h"

// #TODO: Move this out of gain-specific and convert to generic derived Slider that contains normalization methods
// No reason to ever use this constructor, technically
AssociatedParameter::AssociatedParameter()
{
	DBG("No parameter assigned to Associated Parameter");
}

AssociatedParameter::AssociatedParameter(AudioProcessorParameter* associatedParam) : associatedParameter(associatedParam)
{

}

void AssociatedParameter::setAssociatedParameter(AudioProcessorParameter* associatedParam)
{
	associatedParameter = associatedParam;
}

AudioProcessorParameter* AssociatedParameter::getAssociatedParameter() const
{
	return associatedParameter;
}