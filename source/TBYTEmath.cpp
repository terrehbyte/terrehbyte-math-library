//////////////////////////////////////////////////////////////////////////
//	File:	TBYTEmath.h
//	Author:	Terry Nguyen
//	Date:	12/18/2013
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
		float fRadians = a_fDegrees * (M_PI / 180);
		return fRadians;
	}

	float RadiansToDegrees(float a_fRadians)
	{
		float fDegrees = a_fRadians * (180 / M_PI);
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