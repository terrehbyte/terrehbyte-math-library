#include "TBYTEmath.h"

namespace tbyte
{
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
				// return the number as needed
				return dPowTwo;
			}
		}
	}
}