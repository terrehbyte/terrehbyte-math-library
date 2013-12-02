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

	float	Vector4::GetMagnitude(const Vector4 a_Term)
	{
		float fFirst	= a_Term.fW * a_Term.fW;
		float fSecond	= a_Term.fX * a_Term.fX;
		float fThird	= a_Term.fY * a_Term.fY;
		float fFourth	= a_Term.fZ * a_Term.fZ;
		
	
		return sqrt(fFirst + fSecond + fThird + fFourth);
	}

	Vector4 Vector4::GetNormal(const Vector4 a_Term)
	{
		Vector4 temp;

		float fMagnitude = GetMagnitude(a_Term);

		temp.fW = a_Term.fW / fMagnitude;
		temp.fX = a_Term.fX / fMagnitude;
		temp.fY = a_Term.fY / fMagnitude;
		temp.fZ = a_Term.fZ / fMagnitude;
		
		return temp;
	}

	void Vector4::ConstructFromHex(
		int a_iRED,
		int a_iGREEN,
		int a_iBLUE,
		int a_iALPHA
		)
	{	
		fW = a_iRED;
		fX = a_iGREEN;
		fY = a_iBLUE;
		fZ = a_iALPHA;
	}
}