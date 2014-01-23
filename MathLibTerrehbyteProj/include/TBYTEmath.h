//////////////////////////////////////////////////////////////////////////
//	File:	TBYTEmath.h
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Provides functions for handling basic mathematical inconveniences
//
//////////////////////////////////////////////////////////////////////////

#ifndef _TBYTEMATH_H_
#define _TBYTEMATH_H_

#define _USE_MATH_DEFINES
#include <math.h>
#include <map>

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace tbyte
{
	// Linear Interpolation for Scalar Values
	// http://msdn.microsoft.com/en-us/library/windows/desktop/bb509618%28v=vs.85%29.aspx
	float DLLEXPORT LERP(float a_First, float a_Second, float a_InterpolationValue);

	// Convert Deg to Radians
	float DLLEXPORT DegreesToRadians(float a_fDegrees);

	// Convert Radians to Deg
	float DLLEXPORT RadiansToDegrees(float a_fRadians);

	// Test Scalar Value if Power of Two
	bool DLLEXPORT CheckPowerOfTwo(double a_dTestNumber);

	// Shift a Given Value to the Next Power of Two
	double DLLEXPORT ShiftNextPowerOfTwo(double &a_dTestNumber);


}

#endif