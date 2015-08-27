/* ==============================================================================
//  DecibelConversions.cpp
//  Part of the Zentropia JUCE Collection
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/08/25
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the GNU license
//
//  Details: Used to convert Decibels in a given range to/from 0.0-1.0 normalized values
================================================================================*/

//#include "DecibelConversions.h"
/*

template <typename Type>
Type DecibelConversions::decibelsToGain(const Type decibels, const Type minusInfinityDb /*= (Type)defaultMinusInfinitydB#2##1#)
{
	return decibels > minusInfinityDb ? std::pow((Type) 10.0, decibels * (Type) 0.05)
		: Type();
}

template <typename Type>
Type DecibelConversions::gainToDecibels(const Type gain, const Type minusInfinityDb /*= (Type)defaultMinusInfinitydB#2##1#)
{
	return gain > Type() ? jmax(minusInfinityDb, (Type)std::log10(gain) * (Type) 20.0)
		: minusInfinityDb;
}


template <typename Type>
Type DecibelConversions::decibelRangeToGain(const Type decibels, const Type maximumDecibels, const Type minusInfinityDb )
{
	return decibels > minusInfinityDb ? std::pow((Type) 10.0, (decibels - maximumDecibels) * (Type) 0.05) 
		: Type();
}

template <typename Type>
Type DecibelConversions::gainToDecibelRange(const Type gain, const Type maximumDecibels, const Type minusInfinityDb)
{
	return gain > Type() ? jmax(minusInfinityDb, ( (Type)std::log10(gain) * (Type) 20.0 ) + (Type) maximumDecibels )
		: minusInfinityDb;
}

template <typename Type>
Type DecibelConversions::decibelRangeGainToRawDecibelGain(const Type normGainValue, const Type maximumDecibels, const Type minusInfinityDb)
{
	//return gain > Type() ? jmax(minusInfinityDb, ((Type)std::log10(gain) * (Type) 20.0) + (Type)maximumDecibels)
	//	: minusInfinityDb;
	//float decibels = DecibelConversions::gainToDecibelRange<Type>((Type)normGainValue, (Type)maximumDecibels, (Type)minusInfinityDb);
	//return DecibelConversions::decibelsToGain<Type>(decibels, -96.0);
	return (Type) 10.0;

}
*/
/*
template <typename Type>
String DecibelConversions::toString(const Type decibels, const int decimalPlaces, const Type minusInfinityDb /*= (Type)defaultMinusInfinitydB#1#)
{
	String s;

	if (decibels <= minusInfinityDb)
	{
		s = "-INF dB";
	} else
	{
		if (decibels >= Type())
			s << '+';

		s << String(decibels, decimalPlaces) << " dB";
	}

	return s;
}
*/
