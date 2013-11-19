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

	int ConvertHextoInt(const std::string a_HexValue)
	{
		using std::string;
		using std::ostringstream;

		ostringstream CharSStream;

		CharSStream << a_HexValue;

		int iHex;
		int iCheckPos = 0;

		/*
		while (CharSStream[iCheckPos] != '\0')
		{


			// Iterate to Next Char
			iCheckPos++;
		}
		*/
		

		return iHex;
	}

	void Vector4::ConstructFromHex(std::string a_HexRed,
						  std::string a_HexBlue,
						  std::string a_HexGreen,
						  std::string a_HexAlpha)
	{
		using std::string;
		using std::hex;

		// Process RED
		fW = ConvertHextoInt(a_HexRed);
		// Process BLUE
		fX = ConvertHextoInt(a_HexBlue);
		// Process GREEN
		fX = ConvertHextoInt(a_HexGreen);
		// Process ALPHA
		fX = ConvertHextoInt(a_HexAlpha);
	}
}