//////////////////////////////////////////////////////////////////////////
//	File:	TBYTEmath.h
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Provides functions for handling basic mathematical inconveniences
//
//////////////////////////////////////////////////////////////////////////

#include "TBYTEmath.h"

using std::map;

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
		// Cache of Calculated Values
		static map<int, float> Cache;
		
		map<int,float>::iterator RevIt = Cache.end();
		
		//int iIterationVal;
		const int ciBase = 2;

		int iIterationVal = ciBase;

		bool bCacheStatus = Cache.empty();

		if ( !Cache.empty())
		{
			// If this key exists, then it must be a power of two
			if (Cache.count(a_dTestNumber))
			{
				return true;
			}

			for (map<int,float>::iterator MapIterator = Cache.begin();
					MapIterator != Cache.end();
					MapIterator++)
			{
				if (MapIterator->first >= a_dTestNumber)
				{
					if (MapIterator->first == a_dTestNumber)
					{
						return true;
					}
					else
					{
						if ( (MapIterator->first) * 2 > a_dTestNumber)
						{
							return false;
						}
					}
				}

			}
		}
		
		if (!Cache.empty())
		{
			RevIt--;
			iIterationVal = RevIt->first;
		}

		while (iIterationVal < a_dTestNumber)
		{
			iIterationVal *= 2;

			Cache.emplace(std::pair<int, float>(iIterationVal,0));

			if (iIterationVal == a_dTestNumber)
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