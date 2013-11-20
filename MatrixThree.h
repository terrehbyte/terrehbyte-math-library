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
	private:
		
	public:
		//float fArray[3][3];

		void Transpose();

		Matrix3	operator + (const Matrix3 a_Addend);
		Matrix3	operator + (const float a_AddendScalar);

		Matrix3	operator - (const Matrix3 a_Subtrahend);
		Matrix3	operator - (const float a_SubtrahendScalar);

		Matrix3	operator * (const Matrix3 a_Term);
		Matrix3	operator * (const float a_TermScalar);


	};
}

#endif