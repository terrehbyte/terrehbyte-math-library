//////////////////////////////////////////////////////////////////////////
//	File:	VectorFour.h
//	Author:	Terry Nguyen
//	Date:	11/05/2013
//	Brief:	Provides access to VectorFour
//
//////////////////////////////////////////////////////////////////////////

#ifndef _VECTORFOUR_H_
#define _VECTORFOUR_H_
#include <string>

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
		// ** CONSTRUCTORS ** - called when instantiated
		Vector4();

		// ** DESTRUCTORS ** - called when freed from memory
		~Vector4();

		// ** FUNCTIONS **
		static float	GetMagnitude(const Vector4 a_Term);
		static Vector4	GetNormal(const Vector4 a_Term);
		
		void	ConstructFromHex(
			int a_iRED,
			int a_iGREEN,
			int a_iBLUE,
			int a_iALPHA
			);

		float	fW;
		float	fX;
		float	fY;
		float	fZ;
	};
}

#endif
