//////////////////////////////////////////////////////////////////////////
//	File:	VectorThree.h
//	Author:	Terry Nguyen
//	Date:	12/11/2013
//	Brief:	Provides access to VectorThree for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#ifndef _VECTORTHREE_H_
#define _VECTORTHREE_H_

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace tbyte
{
	class DLLEXPORT Vector3
	{
	public:
		Vector3();
		~Vector3();

		float	fX;
		float	fY;
		float	fZ;

		// Get Euler Angle Between Two Vectors
		float Vector3::GetEulerAngle(const Vector3 &a_Term);

		// Returns the Dot Product between the caller and the Vector3 term
		float	GetDotProduct(const Vector3 &a_Term);

		// Return what the caller would be when normalized
		Vector3	GetNormal();

		// Returns the cross product between caller and term
		Vector3	GetCrossProduct(const Vector3 &a_Term);
		
		// Returns the magnitude of the vector
		float	GetMagnitude();

		// Return a linearly interpolated Vector3
		Vector3 Lerp(const Vector3 &a_TerminatingVector, const float &a_fInterpPoint);

		Vector3	operator + (const Vector3 &a_First);
		Vector3	operator + (const float &a_fAddendScalar);
		Vector3 operator += (const Vector3 &a_Addend);
		Vector3 operator += (const float &a_fAddendScalar);
	
		Vector3 operator - (const Vector3 &a_Subtrahend);
		Vector3 operator - (const float &a_fSubtrahendScalar);
		Vector3 operator -= (const Vector3 &a_Subtrahend);
		Vector3 operator -= (const float &a_fSubtrahendScalar);

		Vector3 operator * (const float &a_fScalar);
		Vector3 operator *= (const float &a_fScalar);

		Vector3 operator / (const float &a_fScalar);
		Vector3 operator /= (const float &a_fScalar);
	
		Vector3	operator = (const Vector3 &a_Source);
		bool	operator == (const Vector3 &a_Source);
	};
}
#endif

