//////////////////////////////////////////////////////////////////////////
//	File:	TBYTEmath.h
//	Author:	Terry Nguyen
//	Date:	12/11/2013
//	Brief:	Provides functions for handling basic mathematical inconveniences
//
//////////////////////////////////////////////////////////////////////////

#ifndef _TBYTEMATH_H_
#define _TBYTEMATH_H_

namespace tbyte
{
	// Linear Interpolation for Scalar Values
	// http://msdn.microsoft.com/en-us/library/windows/desktop/bb509618%28v=vs.85%29.aspx
	float  LERP(float a_First, float a_Second, float a_InterpolationValue);

	// Convert Deg to Radians
	float  DegreesToRadians(float a_fDegrees);

	// Convert Radians to Deg
	float  RadiansToDegrees(float a_fRadians);

	// Test Scalar Value for Power of Two (shift to nearest power of two)
	bool  CheckPowerOfTwo(double a_dTestNumber);

	double  ShiftNextPowerOfTwo(double &a_dTestNumber);


}

#endif