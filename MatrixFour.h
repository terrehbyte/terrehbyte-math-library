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
		float fArray[4][4];
	};
}

#endif