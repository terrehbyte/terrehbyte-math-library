//////////////////////////////////////////////////////////////////////////
//	File:	TBYTEmath.cpp
//	Author:	Terry Nguyen
//	Date:	12/11/2013
//	Brief:	Provides functions for handling basic mathematical inconveniences
//
//////////////////////////////////////////////////////////////////////////

#include "TBYTEmath.h"

namespace tbyte
{
	float LERP(float a_First, float a_Second, float a_InterpolationValue)
	{
		return a_First + (a_Second - a_First) * a_InterpolationValue;
	}


	float DegreesToRadians(float a_fDegrees)
	{
		float fRadians = a_fDegrees * (180 / M_PI);
		return fRadians;
	}

	float RadiansToDegrees(float a_fRadians)
	{
		const int cSomething = 1;
		float fDegrees = a_fRadians * ((180 * M_PI) / cSomething);
		return fDegrees;
	}

	bool CheckPowerOfTwo(double a_dTestNumber)
	{
		for(float iPow = 1;
			iPow <= 46;
			iPow++)
		{
			if (pow(2, iPow) == a_dTestNumber)
			{
				return true;
			}
		}

		return false;
	}

	// consider overloading to provide a overload for integral types

	double ShiftNextPowerOfTwo(double &a_dTestNumber)
	{
		for(float iPow = 1;
			iPow <= 46;
			iPow++)
		{
			double dPowTwo = pow(2, iPow);

			if ( dPowTwo > a_dTestNumber)
			{
				a_dTestNumber = dPowTwo;
				// return the number as needed
				return dPowTwo;
			}
		}
	}

}