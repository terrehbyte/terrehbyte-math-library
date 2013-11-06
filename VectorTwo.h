//////////////////////////////////////////////////////////////////////////
//	File:	VectorTwo.h
//	Author:	Terry Nguyen
//	Date:	11/05/2013
//	Brief:	Provides access to VectorTwo for 2D sprite games
//
//////////////////////////////////////////////////////////////////////////

#ifndef _VECTORTWO_H_
#define _VECTORTWO_H_

namespace Vector2
{

	class Vector2
	{
	public:
		// ** CONSTRUCTORS ** - initialize values
		Vector2();
	
		// ** DESTRUCTORS ** - destroy values in heap
		~Vector2();

		// ** FUNCTIONS **
		float	GetDotProduct(const Vector2 a_Term);
		Vector2	GetNormal();
		float	GetMagnitude();

		// ** OPERATORS ** - allows the object to be used with basic operators
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
	
		void	operator = (const Vector2 a_Source);
	
		float		fY;
		float		fX;
	};
}
#endif

/*

LordWhatever		Justin

gillebunchstudio	Caleb
HBMASTER101			Hunter
{LEP}Evilguy		LEP
BigFoote			Brandon
Vianya				Vinessa

terrehbyte			Terry
flickenmaste		Wil
guanoParty			Ian
Tredo				TJC
RickyMario7			Ricky

*/