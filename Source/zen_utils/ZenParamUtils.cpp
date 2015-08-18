/* ==============================================================================
//  ZenParamUtils.h
//  Part of the Zentropia JUCE Collection
//  @author Casey Bailey (<a href="SonicZentropy@gmail.com">email</a>)
//  @version 0.1
//  @date 2015/08/16
//  Copyright (C) 2015 by Casey Bailey
//  Provided under the [GNU license]
//
//  Details: Generic Utilities for dealing with JUCE Parameters
//
//  Zentropia is hosted on Github at [https://github.com/SonicZentropy]
==============================================================================
*/

/*Here's some functions for manipulating parameters. Use the inverse functions in 'getParameter' and 'setParameterNotifyingHost' and the non-inverse in 'setParamer'. The warp functions, borrowed from JUCE's slider class allow you to set a value you wish to be represented by 0.5 - useful for frequency control for example.The intStep functions allow integers to be represented and the Bool is self explanatory.Hope these help.*/


#include "ZenParamUtils.h"
#include <math.h>

//using namespace juce;
namespace juce
{
	/// <summary>
	/// Use in setParameter
	/// </summary>
	/// <param name="x"></param>
	/// <param name="max"></param>
	/// <param name="min"></param>
	/// <param name="mid"></param>
	/// <returns></returns>
	float ZenParamUtils::warp(float x, float max, float min, float mid)
	{
		float sf = warpCoefficients(max, min, mid);

		float y = exp(log(x) / sf);
		return min + (max - min) * y;
	}

	/// <summary>
	/// Use in 'getParameter' and 'setParameterNotifyingHost'
	/// </summary>
	/// <param name="x">The x.</param>
	/// <param name="max">The maximum.</param>
	/// <param name="min">The minimum.</param>
	/// <param name="mid">The mid.</param>
	/// <returns>float.</returns>
	float ZenParamUtils::inverseWarp(float x, float max, float min, float mid)
	{
		float sf = warpCoefficients(max, min, mid);

		float n = (x - min) / (max - min);

		return pow(n, sf);
	}

	/// <summary>
	/// Returns skew coeff
	/// </summary>
	/// <param name="max">The maximum.</param>
	/// <param name="min">The minimum.</param>
	/// <param name="mid">The mid.</param>
	/// <returns>float.</returns>
	float ZenParamUtils::warpCoefficients(float max, float min, float mid)
	{
		float  skewFactor = log(0.5f) / log((mid - min)
			/ (max - min));

		return skewFactor;
	}

	/// <summary>
	/// Returns boolean TRUE if input >= 0.5, else false
	/// </summary>
	/// <param name="inputValue">Normalized 0.0-1.0 range float value</param>
	/// <returns>(bool) value converted to a bool</returns>
	bool ZenParamUtils::convertNormalizedValueToBoolViaRange(float inputValue)
	{
		if (inputValue < 0.5)
			return false;
		else
			return true;
	}

	/// <summary>
	/// Takes boolean input value and returns 1.0 if the boolean is true, 0.0 if false
	/// </summary>
	/// <param name="inputBool">Arbitrary input boolean</param>
	/// <returns>(float) 1.0 if input was true, 0.0 if input is false</returns>
	float ZenParamUtils::convertBoolToFloatNormalized(bool inputBool)
	{
		if (inputBool)
			return 1.0;
		else
			return 0.0;
	}

	/// <summary>
	/// Given a float value normalized in the range 0-1, return the value linearly rescaled/denormalized
	/// to the range of (float) min - max
	/// </summary>
	/// <param name="value">Input Value from arbitrary range (GUI Input Methods)</param>
	/// <param name="minValue">Minimum of GUI value's range</param>
	/// <param name="maxValue">Maximum of GUI value's range</param>
	/// <returns></returns>
	float ZenParamUtils::normalizeValueLinear ( 
		const double& value, const double& minValue, const double& maxValue )
	{
		jassert(maxValue > minValue);

		float normalized = static_cast<float>((value - minValue) / (maxValue - minValue));
		jassert(normalized >= 0.0f && normalized <= 1.0f);
		return normalized;
	}

	/// <summary>
	/// Given a denormalized float variable plus range min/max, return a normalized 0-1 value
	/// </summary>
	/// <param name="normalized">The normalized input value</param>
	/// <param name="minValue">Minimum value of desired range</param>
	/// <param name="maxValue">Maximum value of desired range</param>
	/// <returns>(float) Denormalized value between given min/max</returns>
	float ZenParamUtils::denormalizeValueLinear ( 
		const float& normalized, const double& minValue, const double& maxValue )
	{
		jassert(normalized >= 0.0f && normalized <= 1.0f);
		jassert(maxValue > minValue);

		return static_cast<float>(minValue + normalized * (maxValue - minValue));
	}
}
#if 0
/*************************************************
The "warping" of the parameters, and converting their values to Strings seemed to be worth extracting into dedicated classes to keep TextEditor, Slider and host automation in synch.Especially since it has do be done over and over again at many different places in the code(if you have more than a few parameters)

Long answer :
A plugin we developed last year required a lot parameters to be manipulated, saved or automated.Doing all the serialization and normalization in our AudioProcessor subclass would have become messy, and the same kind of conversions between internal, "warped" values and their string representations are also needed when changing or displaying parameters in the GUI(some with standard, some with custom JUCE components).

Heavily summarized, I ended up with
- a set of classes to define parameters, their value ranges, validation and conversion rules
- a set of listeners to connect standard JUCE components to these parameters
- an AutomatedAudioProcessor class that implements the persistence and automation of plugin - parameters in a generic way

This might sound a bit over - engineered to some, but looking back it was well worth the effort.It turned out to be quite useful, not only for plugin automation and GUI, but also for (de)serializing the state of your audio - chain(undo / redo, copy / paste, command line parsing, unit - tests)
*/
#endif