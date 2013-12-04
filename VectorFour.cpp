//////////////////////////////////////////////////////////////////////////
//	File:	VectorThree.cpp
//	Author:	Terry Nguyen
//	Date:	11/05/2013
//	Brief:	Defines functions pertaining to Vector3D
//
//////////////////////////////////////////////////////////////////////////

#include <math.h>
#include "VectorFour.h"
#include <iostream>
#include <sstream>

// ** CONSTRUCTORS ** - initialize values

namespace Vector4
{
	Vector4::Vector4()
	{
		fW = 0;
		fY = 0;
		fX = 0;
		fZ = 0;
	}
	
	// ** DESTRUCTORS ** - destroy values in heap
	Vector4::~Vector4()
	{
	}

	float	Vector4::GetMagnitude()
	{
		float fFirst	= fW * fW;
		float fSecond	= fX * fX;
		float fThird	= fY * fY;
		float fFourth	= fZ * fZ;
		
	
		return sqrt(fFirst + fSecond + fThird + fFourth);
	}

	Vector4 Vector4::GetNormal()
	{
		Vector4 temp;

		float fMagnitude = GetMagnitude();

		temp.fW = fW / fMagnitude;
		temp.fX = fX / fMagnitude;
		temp.fY = fY / fMagnitude;
		temp.fZ = fZ / fMagnitude;
		
		return temp;
	}

	void Vector4::ConstructFromHex(
		int a_iRED,
		int a_iGREEN,
		int a_iBLUE,
		int a_iALPHA
		)
	{	
		fW = a_iRED / 255;
		fX = a_iGREEN / 255;
		fY = a_iBLUE / 255;
		fZ = a_iALPHA / 255;
	}
}