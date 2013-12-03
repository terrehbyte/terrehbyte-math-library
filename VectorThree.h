//////////////////////////////////////////////////////////////////////////
//	File:	VectorThree.h
//	Author:	Terry Nguyen
//	Date:	11/05/2013
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

namespace Vector3
{
	class DLLEXPORT Vector3
	{
	public:
		// ** CONSTRUCTORS ** - called when instantiated
		Vector3();

		// ** DESTRUCTORS ** - called when freed from memory
		~Vector3();

		// ** FUNCTIONS **
		float	GetDotProduct(const Vector3 a_Term);
		Vector3	GetNormal();
		Vector3	GetCrossProduct(const Vector3 a_Term);
		float	GetMagnitude(const Vector3 a_Term);

		Vector3 Lerp(const Vector3 a_TerminatingVector, const float a_fInterpPoint);

		// MyVector.GetCrossProduct(OtherVector);
		// GetCrossProduct(MyVector, OtherVector);

		// ** OPERATORS ** - allows the object to be used with basic operators
		Vector3	operator + (const Vector3 a_First);
		Vector3	operator + (const float a_fAddendScalar);
		Vector3 operator += (const Vector3 a_Addend);
		Vector3 operator += (const float a_fAddendScalar);
	
		Vector3 operator - (const Vector3 a_Subtrahend);
		Vector3 operator - (const float a_fSubtrahendScalar);
		Vector3 operator -= (const Vector3 a_Subtrahend);
		Vector3 operator -= (const float a_fSubtrahendScalar);


		Vector3 operator * (const float a_fScalar);
		Vector3 operator *= (const float a_fScalar);

		Vector3 operator / (const float a_fScalar);
		Vector3 operator /= (const float a_fScalar);
	
		void	operator = (const Vector3 a_Source);

		float	fX;
		float	fY;
		float	fZ;
	};
}
#endif

