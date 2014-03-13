//////////////////////////////////////////////////////////////////////////
//	File:	TBYTEmath.h
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Provides functions for handling basic mathematical inconveniences
//
//////////////////////////////////////////////////////////////////////////

#include <TerrehByteMath.h>

using std::map;

namespace tbyte
{
	float LERP(const float &a_First, const float &a_Second, const float &a_InterpolationValue)
	{
		return a_First + (a_Second - a_First) * a_InterpolationValue;
	}

	float DegreesToRadians(const float &a_fDegrees)
	{
		return a_fDegrees * (M_PI / 180.0f);
	}

	float RadiansToDegrees(const float &a_fRadians)
	{
		return a_fRadians * (180.f / M_PI);
	}

	bool CheckPowerOfTwo(const double &a_dTestNumber)
	{
		// Cache of Calculated Values
		static map<int, float> Cache;
		
		map<int,float>::iterator RevIt = Cache.end();
		
		//int iIterationVal;
		const int ciBase = 2;

		int iIterationVal = ciBase;

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
		
		// return -1 for error
		return -1;
	}

}