//////////////////////////////////////////////////////////////////////////
//	File:	MatrixFour.h
//	Author:	Terry Nguyen
//	Date:	11/19/2013
//	Brief:	Provides access to MatrixFour for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#ifndef _MATRIXFOUR_H_
#define _MATRIXFOUR_H_

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

namespace Matrix4
{
	class DLLEXPORT Matrix4
	{
	private:

	public:
		Matrix4();
		~Matrix4();

		float m_afArray[4][4];

		Matrix4 Transpose();
		Matrix4 Scale(const float a_fFactorScalar)
		{
		}

		Matrix4	operator + (const Matrix4 a_Addend);
		Matrix4	operator + (const float a_AddendScalar);

		Matrix4	operator - (const Matrix4 a_Subtrahend);
		Matrix4	operator - (const float a_SubtrahendScalar);

		Matrix4	operator * (const Matrix4 a_Factor);
		Matrix4	operator * (const float a_FactorScalar);


	};
}

#endif