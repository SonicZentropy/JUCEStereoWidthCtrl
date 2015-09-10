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

/// <summary>Decibel Conversion Utilities</summary>
/// <remarks>	Zentropy, 8/30/2015. </remarks>
class DecibelConversions
{
public:

	/// <summary>Converts a dBFS value to its equivalent raw (NON-normalized) gain level.</summary>
	/// <param name="decibels">		  Input value in decibels</param>
	/// <param name="minusInfinityDb">Value below which 0 is always returned, represents bottom of decibel range</param>
	/// <returns>A raw Gain value such that 0.0 gain = minusInfinityDb, 1.0 Gain = 0.0dB, and Gain > 1.0 is decibel increase</returns>
	template <typename Type>	
	static Type decibelsToGain(const Type decibels,	const Type minusInfinityDb = static_cast<Type>(defaultMinusInfinitydB) )
	{
		return decibels > minusInfinityDb ? std::pow(static_cast<Type>(10.0), decibels * static_cast<Type>(0.05) )  : Type();
	}



	/// <summary>A gain of 1.0 = 0 dB, and lower gains map onto negative decibel values.
	///	If the gain is 0 (or negative), then the method will return the value 
	/// provided as minusInfinityDb.</summary>
	/// <param name="gain">			  The gain.</param>
	/// <param name="minusInfinityDb">The minus infinity database.</param>
	/// <returns>A Type.</returns>
	template <typename Type>
	static Type gainToDecibels(const Type gain, const Type minusInfinityDb = static_cast<Type>(defaultMinusInfinitydB) )
	{
		return gain > Type() ? static_cast<Type>(std::log10(gain) * static_cast<Type>(20.0) ) : minusInfinityDb;
	}

	/// <summary>Converts input Decibel contained within specified range to a normalized 0-1 value</summary>
	/// <param name="decibels">Input decibels between -96 and maximumDecibels</param>
	/// <param name="maximumDecibels">The maximum decibel representation for the range</param>
	/// <param name="minusInfinityDb">Lowest decibel representation, defaults to -96</param>
	/// <returns>Normalized (0-1) gain value</returns>
	template <typename Type>
	static Type decibelRangeToGain(const Type decibels, const Type maximumDecibels, const Type minusInfinityDb)
	{
		return decibels > minusInfinityDb ? std::pow(static_cast<Type>(10.0, (decibels - maximumDecibels) * static_cast<Type>(0.05) ) ) : Type();
	}

	/// <summary>INCORRECTConverts a normalized (0.0-1.0) gain value to decibels in a given range</summary>
	/// <param name="gain">Input Gain value normalized between 0 and 1</param>
	/// <param name="maximumDecibels">Maximum Decibel value desired for range</param>
	/// <param name="minusInfinityDb">Minimum Decibel value, below which -INF is returned</param>
	/// <returns>Decibel representation of the input value, between -96 and maximumDecibels</returns>
	template <typename Type>
	static Type gainToDecibelRange(const Type gain, const Type maximumDecibels, const Type minusInfinityDb)
	{
		throw std::logic_error("This method (DecibelConversions::gainToDecibelRange()  is INCORRECT as currently written because: Does not actually use a range.");
		//return gain > Type() ? (static_cast<Type>(std::log10(gain) * static_cast<Type>(20.0) + static_cast<Type>(maximumDecibels) ) ) : minusInfinityDb;
	}

	
	/// <summary>Map an input decibel value in a chosen finite range to a normalized, linear scaled Gain value such that decibelUnityGain maps to given normalizedMidpoint (ex: 0.0dB maps to 0.5 normalized in host)</summary>
	/// <param name="x">				 The input decibel value to be mapped (Between decibelMinimum and decibelMaximum)</param>
	/// <param name="normalizedMin">	 Minimum possible value of the normalized range (Generally always 0.0 for VST)</param>
	/// <param name="normalizedMax">	 Maximum possible value of the normalized range (Generally always 1.0 for VSTs)</param>
	/// <param name="normalizedMidpoint">Value in the range you want to use as the correlated midpoint (Generally 0.5 for Decibels due to automation)</param>
	/// <param name="decibelMinimum">	 Minimum possible value for the desired decibal range (ex: -96)</param>
	/// <param name="decibelMaximum">	 Maximum possible value for the desired decibal range (ex: 12)</param>
	/// <param name="decibelUnityForMid">Decimal value you want mapped to normalizedMidpoint (Generally 0.0 for Unity Gain Mapped to 0.5 in the host)</param>
	/// <returns>Decibel input normalized to value between 0 and 1.0 for VST host use</returns>
	template <typename Type>
	static Type mapDecibelsToProperNormalizedValue(Type y, Type normalizedMin, Type normalizedMax, Type normalizedMidpoint, Type decibelMinimum, Type decibelMaximum, Type decibelUnityForMid)
	{
		Type x, x0, x1, y0, y1;
		if (y < 0)
		{
			x0 = normalizedMin;
			y0 = decibelMinimum;
			x1 = normalizedMidpoint;
			y1 = decibelUnityForMid;

		} else if (y >= 0)
		{
			x0 = normalizedMidpoint;
			y0 = decibelUnityForMid;
			x1 = normalizedMax;
			y1 = decibelMaximum;
		} else
		{
			std::cout << "SOMETHING TERRIBLE THIS WAY COMES" << std::endl;
			throw std::logic_error("NOPE");
		}
		if ((y1 - y0) == 0) return 0;  //prevent divide by 0
		x = (((y - y0) / (y1 - y0)) * (x1 - x0)) + x0;
		return x;
	}


	/// <summary>Map a normalized, linearly scaled input value between 0.0 and 1.0 to decibels in a given range (ex: -96 to 12)</summary>
	/// <param name="x">				 The input value (Between 0.0 and 1.0)</param>
	/// <param name="normalizedMin">	 Minimum possible value of the normalized range (Generally always 0.0 for VST)</param>
	/// <param name="normalizedMax">	 Maximum possible value of the normalized range (Generally always 1.0 for VSTs)</param>
	/// <param name="normalizedMidpoint">Value in the range you want to use as the correlated midpoint (Generally 0.5 for Decibels due to automation)</param>
	/// <param name="decibelMinimum">	 Minimum possible value for the desired decibal range (ex: -96)</param>
	/// <param name="decibelMaximum">	 Maximum possible value for the desired decibal range (ex: 12)</param>
	/// <param name="decibelUnityForMid">Decimal value you want mapped to normalizedMidpoint (Generally 0.0 for Unity Gain Mapped to 0.5 in the host)</param>
	/// <returns>Decibel value of the input normalized value</returns>
	template <typename Type>
	static Type mapNormalizedValueToDecibels(Type x, Type normalizedMin, Type normalizedMax, Type normalizedMidpoint, Type decibelMinimum, Type decibelMaximum, Type decibelUnityForMid)
	{
		Type y, x0, x1, y0, y1;
		// Given value between 0 and 1.0, map to decibels
		if (x <= normalizedMidpoint)
		{
			x0 = normalizedMin;
			y0 = decibelMinimum;
			x1 = normalizedMidpoint;
			y1 = decibelUnityForMid;

		} else if (x > normalizedMidpoint)
		{
			x0 = normalizedMidpoint;
			y0 = decibelUnityForMid;
			x1 = normalizedMax;
			y1 = decibelMaximum;

		} else
		{
			std::cout << "SOMETHING TERRIBLE THIS WAY COMES" << std::endl;
			return -1;
		}
		if ((x1 - x0) == 0) return 0; //prevent divide by zero
		y = ((y1 - y0)*((x - x0) / (x1 - x0))) + y0;
		return y;
	}

	

	/// <summary>Takes a normalized gain value representing an arbitrary Decibel range and converts it to a raw decibel gain value where 1.0 = 0dB</summary>
	/// <param name="normGainValue">Value between 0 and 1.0 that represents a converted decibel from arbitrary range</param>
	/// <param name="maximumDecibels">The maximum decibel value of the arbitrary range</param>
	/// <param name="minusInfinityDb">Any decibel value below this is returned as a 0</param>
	/// <returns>A de-normalized Gain value that can be used to process audio samples</returns>
	template <typename Type>
	static Type decibelRangeGainToRawDecibelGain(const Type normGainValue, const Type maximumDecibels, const Type minusInfinityDb)
	{
		
		Type valueInDecibels = DecibelConversions::mapNormalizedValueToDecibels<Type>(normGainValue, 0.0, 1.0, 0.5, minusInfinityDb, maximumDecibels, 0.0);
		return DecibelConversions::decibelsToGain<Type>(valueInDecibels, minusInfinityDb);
	}

private:
	//==============================================================================
	enum
	{
		defaultMinusInfinitydB = -96
	};

};


#endif   DECIBEL_CONVERSIONS_H_INCLUDED
