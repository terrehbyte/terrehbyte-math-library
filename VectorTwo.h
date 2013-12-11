//////////////////////////////////////////////////////////////////////////
//	File:	VectorTwo.h
//	Author:	Terry Nguyen
//	Date:	12/11/2013
//	Brief:	Provides access to VectorTwo for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#ifndef _VECTORTWO_H_
#define _VECTORTWO_H_

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace Vector2
{
	class DLLEXPORT Vector2
	{
	public:
		Vector2();
		~Vector2();

		float	fY;
		float	fX;

		// Returns the Dot Product between the caller and the Vector2 term
		float	GetDotProduct(const Vector2 a_Term);
		
		// Return what the caller would be when normalized
		Vector2	GetNormal();

		// Return the magnitude of the Vector
		float	GetMagnitude();

		Vector2 Lerp(const Vector2 a_TerminatingVector, const float a_fInterpolationPoint);

		// Operators overloaded - see parameters
		Vector2	operator + (const Vector2 a_Addend);
		Vector2	operator + (const float a_fAddendScalar);
		Vector2	operator += (const Vector2 a_Addend);
		Vector2 operator += (const float a_fAddendScalar);
	
		Vector2 operator - (const Vector2 a_Subtrahend);
		Vector2 operator - (const float a_fSubtrahendScalar);
		Vector2 operator -= (const Vector2 a_Addend);
		Vector2 operator -= (const float a_fSubtrahendScalar);
	
		Vector2 operator * (const float a_fScalar);
		Vector2 operator *= (const float a_fScalar);

		Vector2 operator / (const float a_fScalar);	
		Vector2 operator /= (const float a_fScalar);
	
		Vector2	operator = (const Vector2 a_Source);
		bool	operator == (const Vector2 a_Source);
	};
}
#endif