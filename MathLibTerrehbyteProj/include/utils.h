//////////////////////////////////////////////////////////////////////////
//	File:	utils.h  
//	Author:	Terry Nguyen  
//	Date:	01/25/2016
//	Brief:	Contains common functions used in mathematical calculations
//
//////////////////////////////////////////////////////////////////////////

#ifndef _UTILS_H_
#define _UTILS_H_

#include "internal\_compiler.h"

namespace tbyte
{
	/* General Mathematical Functions */

	// Linear Interpolation for Scalar Values
	float TBYTELIB LERP(const float &a_First, const float &a_Second, const float &a_InterpolationValue);

	// Returns Degrees as Radians
	float TBYTELIB DegreesToRadians(const float &a_fDegrees);

	// Returns Radians as Degrees
	float TBYTELIB RadiansToDegrees(const float &a_fRadians);

	// Test Scalar Value if Power of Two
	bool TBYTELIB CheckPowerOfTwo(const double &a_dTestNumber);

	// Shift a Given Value to the Next Power of Two
	double TBYTELIB ShiftNextPowerOfTwo(double &a_dTestNumber);

}

#endif