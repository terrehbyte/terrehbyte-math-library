//////////////////////////////////////////////////////////////////////////
//	File:	TBYTEmath.h
//	Author:	Terry Nguyen
//	Date:	12/11/2013
//	Brief:	Provides functions for handling basic mathematical inconveniences
//
//////////////////////////////////////////////////////////////////////////

#ifndef _TBYTEMATH_H_
#define _TBYTEMATH_H_

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

	// Test Scalar Value for Power of Two (shift to nearest power of two)
	bool DLLEXPORT CheckPowerOfTwo(double a_dTestNumber);

	double DLLEXPORT ShiftNextPowerOfTwo(double &a_dTestNumber);


}

#endif