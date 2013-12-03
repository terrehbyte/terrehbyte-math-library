//////////////////////////////////////////////////////////////////////////
//	File:	MatrixThree.h
//	Author:	Terry Nguyen
//	Date:	11/19/2013
//	Brief:	Provides access to MatrixFour for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#ifndef _MATRIXTHREE_H_
#define _MATRIXTHREE_H_

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace Matrix3
{
	class DLLEXPORT Matrix3
	{
	public:

		Matrix3();
		~Matrix3();

		float m_afArray[3][3];

		Matrix3 Transpose();
		Matrix3 Scale(const float a_fFactorScalar);

		Matrix3	operator + (const Matrix3 a_Addend);
		Matrix3	operator + (const float a_AddendScalar);

		Matrix3	operator - (const Matrix3 a_Subtrahend);
		Matrix3	operator - (const float a_SubtrahendScalar);

		Matrix3	operator * (const Matrix3 a_Factor);
		Matrix3	operator * (const float a_FactorScalar);


	};
}

#endif