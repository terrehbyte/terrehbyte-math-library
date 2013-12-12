//////////////////////////////////////////////////////////////////////////
//	File:	VectorFour.h
//	Author:	Terry Nguyen
//	Date:	12/11/2013
//	Brief:	Provides access to VectorFour
//
//////////////////////////////////////////////////////////////////////////

#ifndef _VECTORFOUR_H_
#define _VECTORFOUR_H_

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace Vector4
{
	class DLLEXPORT Vector4
	{
	public:
		Vector4();
		~Vector4();

		float	fW;
		float	fX;
		float	fY;
		float	fZ;

		// Returns the magnitude of the vector
		float	GetMagnitude();

		// Return what the caller would be when normalized
		Vector4	GetNormal();
		
		// Reconstructs the caller to be comrpised of hex color values
		void	ConstructFromHex(
			float a_iRED,
			float a_iGREEN,
			float a_iBLUE,
			float a_iALPHA
			);

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