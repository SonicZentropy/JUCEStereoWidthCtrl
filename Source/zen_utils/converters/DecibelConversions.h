/* ==============================================================================
//  DecibelConversions.h
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


#ifndef DECIBEL_CONVERSIONS_H_INCLUDED
#define DECIBEL_CONVERSIONS_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
This class contains methods for converting decibel values.
*/
class DecibelConversions
{
public:
	//==============================================================================
	/** Converts a dBFS value to its equivalent gain level.

	A gain of 1.0 = 0 dB, and lower gains map onto negative decibel values. Any
	decibel value lower than minusInfinityDb will return a gain of 0.
	*/
//	template <typename Type>
//	static Type decibelsToGain(const Type decibels,	const Type minusInfinityDb = (Type)defaultMinusInfinitydB);

	template <typename Type>
	static Type decibelsToGain(const Type decibels,
		const Type minusInfinityDb = (Type)defaultMinusInfinitydB)
	{
		return decibels > minusInfinityDb ? std::pow((Type) 10.0, decibels * (Type) 0.05)
			: Type();
	}

	/** Converts a gain level into a dBFS value.

	A gain of 1.0 = 0 dB, and lower gains map onto negative decibel values.
	If the gain is 0 (or negative), then the method will return the value
	provided as minusInfinityDb.
	*/
//	template <typename Type>
	//static Type gainToDecibels(const Type gain,const Type minusInfinityDb = (Type)defaultMinusInfinitydB);
	template <typename Type>
	static Type gainToDecibels(const Type gain,
		const Type minusInfinityDb = (Type)defaultMinusInfinitydB)
	{
		return gain > Type() ? jmax(minusInfinityDb, (Type)std::log10(gain) * (Type) 20.0)
			: minusInfinityDb;
	}

	/// <summary>Converts input Decibel contained within specified range to a normalized 0-1 value</summary>
	/// <param name="decibels">Input decibels between -96 and maximumDecibels</param>
	/// <param name="maximumDecibels">The maximum decibel representation for the range</param>
	/// <param name="minusInfinityDb">Lowest decibel representation, defaults to -96</param>
	/// <returns>Normalized (0-1) gain value</returns>
	template <typename Type>
	static Type DecibelConversions::decibelRangeToGain(const Type decibels, const Type maximumDecibels, const Type minusInfinityDb)
	{
		return decibels > minusInfinityDb ? std::pow((Type) 10.0, (decibels - maximumDecibels) * (Type) 0.05)
			: Type();
	}

	/// <summary>Converts a normalized (0.0-1.0) gain value to decibels in a given range</summary>
	/// <param name="gain">Input Gain value normalized between 0 and 1</param>
	/// <param name="maximumDecibels">Maximum Decibel value desired for range</param>
	/// <param name="minusInfinityDb">Minimum Decibel value, below which -INF is returned</param>
	/// <returns>Decibel representation of the input value, between -96 and maximumDecibels</returns>
	template <typename Type>
	static Type DecibelConversions::gainToDecibelRange(const Type gain, const Type maximumDecibels, const Type minusInfinityDb)
	{
		return gain > Type() ? jmax(minusInfinityDb, ((Type)std::log10(gain) * (Type) 20.0) + (Type)maximumDecibels)
			: minusInfinityDb;
	}

	/// <summary>Takes a normalized gain value representing an arbitrary Decibel range and converts it to a raw decibel gain value where 1.0 = 0dB</summary>
	/// <param name="normGainValue">Value between 0 and 1.0 that represents a converted decibel from arbitrary range</param>
	/// <param name="maximumDecibels">The maximum decibel value of the arbitrary range</param>
	/// <param name="minusInfinityDb">Any decibel value below this is returned as a 0</param>
	/// <returns>A de-normalized Gain value that can be used to process audio samples</returns>
	template <typename Type>
	static Type DecibelConversions::decibelRangeGainToRawDecibelGain(const Type normGainValue, const Type maximumDecibels, const Type minusInfinityDb)
	{
		//return gain > Type() ? jmax(minusInfinityDb, ((Type)std::log10(gain) * (Type) 20.0) + (Type)maximumDecibels)
		//	: minusInfinityDb;
		float decibels = DecibelConversions::gainToDecibelRange<Type>((Type)normGainValue, (Type)maximumDecibels, (Type)minusInfinityDb);
		return DecibelConversions::decibelsToGain<Type>(decibels, -96.0);
		//return (Type) 10.0;

	}
	
	/** Converts a decibel reading to a string, with the 'dB' suffix.
	If the decibel value is lower than minusInfinityDb, the return value will
	be "-INF dB".
	*/
	template <typename Type>
	static String toString(const Type decibels,
		const int decimalPlaces = 1,
		const Type minusInfinityDb = (Type)defaultMinusInfinitydB);


private:
	//==============================================================================
	enum
	{
		defaultMinusInfinitydB = -96
	};


	DecibelConversions(); // This class can't be instantiated, it's just a holder for static methods..
	JUCE_DECLARE_NON_COPYABLE(DecibelConversions)
};


#endif   DECIBEL_CONVERSIONS_H_INCLUDED
