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
#include "stdafx.h"
#include <algorithm>
#include <iostream>

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
		return gain > Type() ? (Type)std::log10(gain) * (Type) 20.0
			: minusInfinityDb;
	}

	/// <summary>Converts input Decibel contained within specified range to a normalized 0-1 value</summary>
	/// <param name="decibels">Input decibels between -96 and maximumDecibels</param>
	/// <param name="maximumDecibels">The maximum decibel representation for the range</param>
	/// <param name="minusInfinityDb">Lowest decibel representation, defaults to -96</param>
	/// <returns>Normalized (0-1) gain value</returns>
	template <typename Type>
	static Type decibelRangeToGain(const Type decibels, const Type maximumDecibels, const Type minusInfinityDb)
	{
		return decibels > minusInfinityDb ? std::pow((Type) 10.0, (decibels - maximumDecibels) * (Type) 0.05)
			: Type();
	}


	static long double warp(long double x, long double max, long double min, long double mid)
	{
		long double sf = warpCoefficients(max, min, mid);

		long double y = exp(log10(x) / sf);
		return min + (max - min) * y;
	}

	/// <summary>
	/// Use in 'getParameter' and 'setParameterNotifyingHost'
	/// </summary>
	/// <param name="x">The x.</param>
	/// <param name="max">The maximum.</param>
	/// <param name="min">The minimum.</param>
	/// <param name="mid">The mid.</param>
	/// <returns>long double.</returns>
	static long double inverseWarp(long double x, long double max, long double min, long double mid)
	{
		long double sf = warpCoefficients(max, min, mid);

		long double n = (x - min) / (max - min);

		return pow(n, sf);
	}

	/// <summary>
	/// Returns skew coeff
	/// </summary>
	/// <param name="max">The maximum.</param>
	/// <param name="min">The minimum.</param>
	/// <param name="mid">The mid.</param>
	/// <returns>long double.</returns>
	static long double warpCoefficients(long double max, long double min, long double mid)
	{
		long double  skewFactor = log10(0.5f) / log10((mid - min)
			/ (max - min));

		return skewFactor;
	}

	static long double decibelScaleInverseWarpToGain(const long double decibels, const long double maximumDecibels, const long double warpMax, const long double warpMin, const long double warpMid)
	{
		long double x = std::pow(10.0L, (decibels - maximumDecibels) * 0.05L);
		x = decibelRangeToGain(decibels, maximumDecibels, -96.0L);
		//long double x = std::pow(10.0, decibels * 0.05);
		long double warped = inverseWarp(x, warpMax, warpMin, warpMid);

		return warped;
	}

	static long double decibelScaleWarpToGain(const long double decibels, const long double maximumDecibels, const long double warpMax, const long double warpMin, const long double warpMid)
	{
		long double x = std::pow(10.0L, (decibels - maximumDecibels) * 0.05L);
		x = decibelRangeToGain(decibels, maximumDecibels, -96.0L);
		//long double x = std::pow(10.0, decibels * 0.05);
		long double warped = warp(x, warpMax, warpMin, warpMid);

		return warped;
	}

	/*static long double mapNormalizedValueToDecibels(const long double x)
	{
	// Given value between 0 and 1.0, map to decibels
	if (x <= 0.5)
	{
	long double y;

	y = x / 0.5;
	y *= 96;
	y -= 96;
	return y;
	}
	else if (x > 0.5)
	{
	long double y = (x - 0.5);
	y /= 0.5;
	y *= 12;
	return y;
	}
	else
	{
	std::cout << "SOMETHING TERRIBLE THIS WAY COMES" << std::endl;
	return -1;
	}
	}*/

	/// <summary>Map an input value between 0.0 and 1.0 to decibels in a given range (ex: -96 to 12)</summary>
	/// <param name="x">				 The input value (Between 0.0 and 1.0)</param>
	/// <param name="normalizedMin">	 Minimum possible value of the normalized range (Generally always 0.0 for VST)</param>
	/// <param name="normalizedMax">	 Maximum possible value of the normalized range (Generally always 1.0 for VSTs)</param>
	/// <param name="normalizedMidpoint">Value in the range you want to use as the correlated midpoint (Generally 0.5 for Decibels due to automation)</param>
	/// <param name="decibelMinimum">	 Minimum possible value for the desired decibal range (ex: -96)</param>
	/// <param name="decibelMaximum">	 Maximum possible value for the desired decibal range (ex: 12)</param>
	/// <param name="decibelUnityForMid">Decimal value you want mapped to normalizedMidpoint (Generally 0.0 for Unity Gain Mapped to 0.5 in the host)</param>
	/// <returns>Decibel value of the input normalized value</returns>
	static long double mapNormalizedValueToDecibels(const long double x, const long double normalizedMin, const long double normalizedMax, const long double normalizedMidpoint, const long double decibelMinimum, const long double decibelMaximum, const long double decibelUnityForMid)
	{
		long double y, x0, x1, y0, y1;
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

	/// <summary>Map an input decibel value in a chosen finite range to a normalized Gain value such that decibelUnityGain maps to given normalizedMidpoint (ex: 0.0dB maps to 0.5 normalized in host)</summary>
	/// <param name="x">				 The input decibel value to be mapped (Between decibelMinimum and decibelMaximum)</param>
	/// <param name="normalizedMin">	 Minimum possible value of the normalized range (Generally always 0.0 for VST)</param>
	/// <param name="normalizedMax">	 Maximum possible value of the normalized range (Generally always 1.0 for VSTs)</param>
	/// <param name="normalizedMidpoint">Value in the range you want to use as the correlated midpoint (Generally 0.5 for Decibels due to automation)</param>
	/// <param name="decibelMinimum">	 Minimum possible value for the desired decibal range (ex: -96)</param>
	/// <param name="decibelMaximum">	 Maximum possible value for the desired decibal range (ex: 12)</param>
	/// <param name="decibelUnityForMid">Decimal value you want mapped to normalizedMidpoint (Generally 0.0 for Unity Gain Mapped to 0.5 in the host)</param>
	/// <returns>Decibel input normalized to value between 0 and 1.0 for VST host use</returns>
	static long double mapDecibelsToProperNormalizedValue(const long double y, const long double normalizedMin, const long double normalizedMax, const long double normalizedMidpoint, const long double decibelMinimum, const long double decibelMaximum, const long double decibelUnityForMid)
	{
		long double x, x0, x1, y0, y1;
		if (y < 0)
		{
			/*long double x;
			x = y + 96;
			x = x / 96;
			x = x * 0.5;
			return x;*/

			x0 = normalizedMin;
			y0 = decibelMinimum;
			x1 = normalizedMidpoint;
			y1 = decibelUnityForMid;

		} else if (y >= 0)
		{
			//			long double x;
			//			x = (y / 12);
			//			x = x* 0.5;
			//			x = x + 0.5;
			//			return x;
			x0 = normalizedMidpoint;
			y0 = decibelUnityForMid;
			x1 = normalizedMax;
			y1 = decibelMaximum;
		} else
		{
			std::cout << "SOMETHING TERRIBLE THIS WAY COMES" << std::endl;
			return -1;
		}
		if ((y1 - y0) == 0) return 0;  //prevent divide by 0
		x = (((y - y0) / (y1 - y0)) * (x1 - x0)) + x0;
		return x;
	}


	/*	static long double mapDecibelsToProperNormalizedValue(const long double y)
	{
	if (y < 0)
	{
	long double x;
	x = y + 96;
	x = x / 96;
	x = x * 0.5;
	return x;

	} else if (y >= 0)
	{
	long double x;
	x = (y / 12);
	x = x* 0.5;
	x = x + 0.5;
	return x;
	} else
	{
	std::cout << "SOMETHING TERRIBLE THIS WAY COMES" << std::endl;
	return -1;
	}
	}*/

	static long double mapNormalizedValueToDecibelGain(const long double x)
	{
		// Given value between 0 and 1.0, map to decibel gain between 0 and 3.98107
		if (x <= 0.5)
		{
			long double y;

			y = x / 0.5;
			y *= 0;
			y -= 0;
			return y;
		} else if (x > 0.5)
		{
			long double y = (x - 0.5);
			y /= 0.5;
			y *= 3.98107;
			return y;
		} else
		{
			std::cout << "SOMETHING TERRIBLE THIS WAY COMES" << std::endl;
			return -1;
		}
	}


	// Given decibel gain between 0 and 3.98107, map to normalized value between 0 and 1 with 0.5 = 
	static long double mapDecibelGainToProperNormal(const long double y)
	{
		if (y < 0)
		{
			long double x;
			x = y + 0;
			x = x / 0;  ///hmmm
			x = x * 0.5;
			return x;

		} else if (y >= 0)
		{
			long double x;
			x = (y / 3.98107);
			x = x* 0.5;
			x = x + 0.5;
			return x;
		} else
		{
			std::cout << "SOMETHING TERRIBLE THIS WAY COMES" << std::endl;
			return -1;
		}
	}


	static long double logTest(const long double value)
	{
		return (20.0L * log10(0.5L)) + 12.0L;
	}

	/// <summary>Converts a normalized (0.0-1.0) gain value to decibels in a given range</summary>
	/// <param name="gain">Input Gain value normalized between 0 and 1</param>
	/// <param name="maximumDecibels">Maximum Decibel value desired for range</param>
	/// <param name="minusInfinityDb">Minimum Decibel value, below which -INF is returned</param>
	/// <returns>Decibel representation of the input value, between -96 and maximumDecibels</returns>
	template <typename Type>
	static Type gainToDecibelRange(const Type gain, const Type maximumDecibels, const Type minusInfinityDb)
	{
		return gain > Type() ? ((Type)std::log10(gain) * (Type) 20.0) + (Type)maximumDecibels : minusInfinityDb;
	}

	/// <summary>Takes a normalized gain value representing an arbitrary Decibel range and converts it to a raw decibel gain value where 1.0 = 0dB</summary>
	/// <param name="normGainValue">Value between 0 and 1.0 that represents a converted decibel from arbitrary range</param>
	/// <param name="maximumDecibels">The maximum decibel value of the arbitrary range</param>
	/// <param name="minusInfinityDb">Any decibel value below this is returned as a 0</param>
	/// <returns>A de-normalized Gain value that can be used to process audio samples</returns>
	template <typename Type>
	static Type decibelRangeGainToRawDecibelGain(const Type normGainValue, const Type maximumDecibels, const Type minusInfinityDb)
	{
		//return gain > Type() ? jmax(minusInfinityDb, ((Type)std::log10(gain) * (Type) 20.0) + (Type)maximumDecibels)
		//	: minusInfinityDb;
		long double decibels = DecibelConversions::gainToDecibelRange<Type>((Type)normGainValue, (Type)maximumDecibels, (Type)minusInfinityDb);
		return DecibelConversions::decibelsToGain<Type>(decibels, -96.0);
		//return (Type) 10.0; DONE

	}

	//DECIBELS TO GAIN linear normalized
	/** Converts a decibel reading to a string, with the 'dB' suffix.
	If the decibel value is lower than minusInfinityDb, the return value will
	be "-INF dB".

	cout << "**Using mapNormalizedValueToDecibels**" << endl;
	long double mapped = DecibelConversions::mapNormalizedValueToDecibels(0.5);
	cout << " input of 0.5 to decibel (expect 0.0): " << mapped << endl;

	mapped = DecibelConversions::mapNormalizedValueToDecibels(0.0);
	cout << " input of 0.0 to decibel (expect -96): " << mapped << endl;

	mapped = DecibelConversions::mapNormalizedValueToDecibels(1.0);
	cout << " input of 1.0 to decibel (expect 12.0): " << mapped << endl;

	cout << "**Using mapDecibelsToProperNormal**" << endl;
	mapped = DecibelConversions::mapDecibelsToProperNormal(0.0);
	cout << " input of 0.0db to normal (expect 0.5): " << mapped << endl;

	mapped = DecibelConversions::mapDecibelsToProperNormal(-96.0);
	cout << " input of -96.0db to normal (expect 0.0): " << mapped << endl;

	mapped = DecibelConversions::mapDecibelsToProperNormal(-95.99999999999L);
	cout << " input of -95.99999999db to normal (expect 0.0): " << mapped << endl;

	mapped = DecibelConversions::mapDecibelsToProperNormal(12.0);
	cout << " input of 12.0db to normal (expect 1.0): " << mapped << endl;

	mapped = DecibelConversions::mapDecibelsToProperNormal(11.99999999999L);
	cout << " input of 11.99999db to normal (expect 1.0): " << mapped << endl;
	*/

private:
	//==============================================================================
	enum
	{
		defaultMinusInfinitydB = -96
	};



};


#endif   DECIBEL_CONVERSIONS_H_INCLUDED
