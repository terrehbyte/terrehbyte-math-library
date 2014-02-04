//////////////////////////////////////////////////////////////////////////
//	File:	VectorFour.h
//	Author:	Terry Nguyen
//	Date:	12/18/2013
//	Brief:	Provides access to VectorFour
//
//////////////////////////////////////////////////////////////////////////

#ifndef _VECTORFOUR_H_
#define _VECTORFOUR_H_

#include <math.h>

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace tbyte
{
	class DLLEXPORT Vector4
	{
	public:
		Vector4();
		
		Vector4(const float a_m_fW, const float a_m_fX, const float a_m_fY, const float a_m_fZ);

		~Vector4();

		float	m_fW;
		float	m_fX;
		float	m_fY;
		float	m_fZ;

		// Returns the magnitude of the vector
		float	Magnitude();

		// Return what the caller would be when normalized
		Vector4	Normal();
			void Normalise();

			Vector4 CrossProduct(const Vector4 &a_Term);
		 float DotProduct(const Vector4 &a_Term) ;

		// Reconstructs the caller to be comrpised of hex color values
		Vector4	ConstructFromHex(
			float a_iRED,
			float a_iGREEN,
			float a_iBLUE,
			float a_iALPHA
			);

		// Reconstructs the caller to be comrpised of hex color values
		Vector4	ConstructFromHex(int a_iHEXValue);

		// Operators overloaded - see parameters
		Vector4	operator + (const Vector4 &a_Addend);
		Vector4	operator + (const float &a_fAddendScalar);
		Vector4	operator += (const Vector4 &a_Addend);
		Vector4 operator += (const float &a_fAddendScalar);
	
		Vector4 operator - (const Vector4 &a_Subtrahend);
		Vector4 operator - (const float &a_fSubtrahendScalar);
		Vector4 operator -= (const Vector4 &a_Addend);
		Vector4 operator -= (const float &a_fSubtrahendScalar);
	
		Vector4 operator * (const float &a_fScalar);
		Vector4 operator *= (const float &a_fScalar);

		Vector4 operator / (const float &a_fScalar);	
		Vector4 operator /= (const float &a_fScalar);
	
		Vector4	operator = (const Vector4 &a_Source);
		bool	operator == (const Vector4 &a_Source);
	};
}

#endif