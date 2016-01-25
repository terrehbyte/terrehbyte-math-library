//////////////////////////////////////////////////////////////////////////
//	File:	vec4.h  
//	Author:	Terry Nguyen  
//	Date:	01/25/2016
//	Brief:	Contains the class declaration for a Vector4 structure
//
//////////////////////////////////////////////////////////////////////////

#ifndef _VEC4_H_
#define _VEC4_H_

#include "internal\_compiler.h"

namespace tbyte
{
	struct Vector3;

	struct TBYTELIB Vector4
	{
	public:
		Vector4();

		Vector4(const float &a_fX, const float &a_fY, const float &a_fZ, const float &a_fW);

		Vector4(const Vector4 &a_Source);

		~Vector4();

		float	m_fX;
		float	m_fY;
		float	m_fZ;
		float	m_fW;

		// Returns the magnitude of the vector
		float	Magnitude();

		// Return what the caller would be when normalized
		Vector4	Normal();
		void Normalise();

		Vector4 CrossProduct(const Vector4 &a_Term);
		float DotProduct(const Vector4 &a_Term);

		// Reconstructs the caller to be comrpised of hex color values
		static Vector4	ConstructFromHex(float a_iRED,
			float a_iGREEN,
			float a_iBLUE,
			float a_iALPHA);

		// Reconstructs the caller to be comrpised of hex color values
		static Vector4	ConstructFromHex(int a_iHEXValue);

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