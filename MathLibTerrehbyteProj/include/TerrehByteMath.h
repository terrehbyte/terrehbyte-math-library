//////////////////////////////////////////////////////////////////////////
//	File:	TerrehByteMath.h
//	Author:	Justin Loudermilk
//	Date:	03/06/2014
//	Brief:	Combined all the .h into a single file for ease of including
//
//////////////////////////////////////////////////////////////////////////
#ifndef _TERREH_BYTE_MATH_H_
#define _TERREH_BYTE_MATH_H_

#ifdef DLL
	#define DLLEXPORT __declspec(dllexport)
#else
	#define DLLEXPORT __declspec(dllimport)
#endif

// Vector Needs
#define _USE_MATH_DEFINES
#include <math.h>

// General Mathematical Needs
#include <map>

namespace tbyte
{
	class DLLEXPORT Vector2
	{
	public:
		Vector2();

		Vector2(const float &a_fX, const float &a_fY);

		Vector2(const Vector2 &a_Source);

		~Vector2();

		float	m_fX;
		float	m_fY;
		
		// Get Euler Angle Between Two Vectors
		float EulerAngle(const Vector2 &a_Term);

		// Returns the Dot Product between the caller and the Vector2 term
		float	DotProduct(const Vector2 &a_Term);

		// Return what the caller would be when normalized
		Vector2	Normal();
		void Normalise();
		// Return the magnitude of the Vector
		float	Magnitude();

		// Return linearly interpolated vector
		Vector2 Lerp(const Vector2 &a_TerminatingVector, const float &a_fInterpolationPoint);

		// Operators overloaded - see parameters
		Vector2	operator + (const Vector2 &a_Addend);
		Vector2	operator + (const float &a_fAddendScalar);
		Vector2	operator += (const Vector2 &a_Addend);
		Vector2 operator += (const float &a_fAddendScalar);

		Vector2 operator - (const Vector2 &a_Subtrahend);
		Vector2 operator - (const float &a_fSubtrahendScalar);
		Vector2 operator -= (const Vector2 &a_Addend);
		Vector2 operator -= (const float &a_fSubtrahendScalar);

		Vector2 operator * (const float &a_fScalar);
		Vector2 operator *= (const float &a_fScalar);

		Vector2 operator / (const float &a_fScalar);	
		Vector2 operator /= (const float &a_fScalar);

		Vector2	operator = (const Vector2 &a_Source);
		bool	operator == (const Vector2 &a_Source);
	};
	class DLLEXPORT Vector3
	{
	public:
		Vector3();

		Vector3(const float &a_fX, const float &a_fY, const float &a_fZ);

		Vector3(const Vector3 &a_Source);

		~Vector3();

		float	m_fX;
		float	m_fY;
		float	m_fZ;

		// Get Euler Angle Between Two Vectors
		float	EulerAngle(const Vector3 &a_Term);

		// Returns the Dot Product between the caller and the Vector3 term
		float	DotProduct(const Vector3 &a_Term);

		// Return what the caller would be when normalized
		Vector3	Normal();
		void Normalise();
		// Returns the cross product between caller and term
		Vector3	CrossProduct(const Vector3 &a_Term);

		// Returns the magnitude of the vector
		float	Magnitude();

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
	class DLLEXPORT Vector4
	{
	public:
		Vector4();

		Vector4(const float &a_fX, const float &a_fY, const float &a_fZ, const float &a_fW);

		Vector4(const Vector4 &a_Source);

		~Vector4();

		float	m_fX;
		float	m_fY;
		float	m_fZ;
		float	m_fW;

		// Returns the magnitude of the vector
		float	Magnitude();

		// Return what the caller would be when normalized
		Vector4	Normal();
		void Normalise();

		Vector4 CrossProduct(const Vector4 &a_Term);
		float DotProduct(const Vector4 &a_Term) ;

		// Reconstructs the caller to be comrpised of hex color values
		static Vector4	ConstructFromHex(float a_iRED,
			                             float a_iGREEN,
			                             float a_iBLUE,
			                             float a_iALPHA);

		// Reconstructs the caller to be comrpised of hex color values
		static Vector4	ConstructFromHex(int a_iHEXValue);

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
	class DLLEXPORT Matrix3
	{
	public:

		Matrix3();

        Matrix3(const float &a_f0,
                const float &a_f1,
                const float &a_f2,
                const float &a_f3,
                const float &a_f4,
                const float &a_f5,
                const float &a_f6,
                const float &a_f7,
                const float &a_f8);


		Matrix3(const Matrix3 &a_Source);

		~Matrix3();


		//For better OpenGL use Column Major Order
				float m_afArray[9];

        // Transposes the matrix
		void Transpose();

		// Returns a point that has been transformed by the Matrix3 caller
		tbyte::Vector4 VectorTransform(const tbyte::Vector4 &a_Point);
		tbyte::Vector3 VectorTransform(const tbyte::Vector3 &a_Point);

		// Returns the Identity Matrix for 3x3
		static Matrix3 IdentityMatrix();

		// Returns a Vector4 that has been scaled by the Matrix caller
		tbyte::Vector4 Scale(const tbyte::Vector4 &a_Vector);
		tbyte::Vector3 Scale(const tbyte::Vector3 &a_Vector);

		// Returns a Transform Matrix3 for rotation around the '_'-axis in radians
		static Matrix3 MakeXRotationMatrix(float a_Radians);
		static Matrix3 MakeYRotationMatrix(float a_Radians);
		static Matrix3 MakeZRotationMatrix(float a_Radians);

		// Operators (explained by their parameters)
		Matrix3	operator + (const Matrix3 &a_Addend);
		Matrix3	operator + (const float &a_fAddendScalar);
		Matrix3	operator += (const Matrix3 &a_Addend);
		Matrix3	operator += (const float &a_fAddendScalar);

		Matrix3	operator - (const Matrix3 &a_Subtrahend);
		Matrix3	operator - (const float &a_fSubtrahendScalar);
		Matrix3	operator -= (const Matrix3 &a_Subtrahend);
		Matrix3	operator -= (const float &a_fSubtrahendScalar);

		Matrix3	operator * (const Matrix3 &a_Factor);
		Matrix3	operator * (const float &a_fFactorScalar);
		Matrix3	operator *= (const Matrix3 &a_Factor);
		Matrix3	operator *= (const float &a_fFactorScalar);

		Matrix3 operator = (const Matrix3 &a_Source);
		bool	operator == (const Matrix3 &a_Term);
	};
	class DLLEXPORT Matrix4
	{
	private:

	public:
		Matrix4();

        Matrix4(const float &a_f0,
                const float &a_f1,
                const float &a_f2,
                const float &a_f3,
                const float &a_f4,
                const float &a_f5,
                const float &a_f6,
                const float &a_f7,
                const float &a_f8,
                const float &a_f9,
                const float &a_f10,
                const float &a_f11,
                const float &a_f12,
                const float &a_f13,
                const float &a_f14,
                const float &a_f15);

		Matrix4(const Matrix4 &a_Source);

		~Matrix4();

		//For better OpenGL use Column Major Order
		float m_afArray[16];

		// Transposes the matrix
		void Transpose();

		// Returns a point that has been transformed by the Matrix caller
		tbyte::Vector4 PointTransform(const tbyte::Vector4 &a_Point);

		// Returns the Identity Matrix for 4x4
		static Matrix4 IdentityMatrix();

		// Assigns & Returns the Orthographic Project Matrix that was created
		static Matrix4 MakeOrthoProj(const float &a_fLeft,
                                           const float &a_fRight,
                                           const float &a_fTop,
                                           const float &a_fBottom,
                                           const float &a_fFar,
                                           const float &a_fNear,
                                           Matrix4 * a_Dest = nullptr);

		// Returns a Vector4 that has been scaled by the Matrix caller
		tbyte::Vector4 Scale(const tbyte::Vector4 &a_Vector);
		tbyte::Vector3 Scale(const tbyte::Vector3 &a_Vector);

		// Returns a Transform Matrix4 for rotation around the '_'-axis in radians
		static Matrix4 MakeXRotationMatrix(float a_Radians);
		static Matrix4 MakeYRotationMatrix(float a_Radians);
		static Matrix4 MakeZRotationMatrix(float a_Radians);

		// Returns a Vector4 transformed by the Matrix caller
		tbyte::Vector4 VectorTransform(const tbyte::Vector4 &a_Vector);
		tbyte::Vector3 VectorTransform(const tbyte::Vector3 &a_Vector);

		// Operators (explained by their parameters)
		Matrix4	operator + (const Matrix4 &a_Addend);
		Matrix4	operator + (const float &a_AddendScalar);
		Matrix4 operator += (const Matrix4 &a_Addend);
		Matrix4 operator += (const float &a_AddendScalar);

		Matrix4	operator - (const Matrix4 &a_Subtrahend);
		Matrix4	operator - (const float &a_SubtrahendScalar);
		Matrix4	operator -= (const Matrix4 &a_Subtrahend);
		Matrix4	operator -= (const float &a_SubtrahendScalar);

		Matrix4	operator * (const Matrix4 &a_Factor);
		Matrix4	operator * (const float &a_FactorScalar);
		Matrix4	operator *= (const Matrix4 &a_Factor);
		Matrix4	operator *= (const float &a_FactorScalar);

		Matrix4 operator = (const Matrix4 &a_Source);
		bool	operator == (const Matrix4 &a_Source);


	};

	/* General Mathematical Functions */

	// Linear Interpolation for Scalar Values
	float DLLEXPORT LERP(const float &a_First, const float &a_Second, const float &a_InterpolationValue);

	// Returns Degrees as Radians
	float DLLEXPORT DegreesToRadians(const float &a_fDegrees);

	// Returns Radians as Degrees
	float DLLEXPORT RadiansToDegrees(const float &a_fRadians);

	// Test Scalar Value if Power of Two
	bool DLLEXPORT CheckPowerOfTwo(const double &a_dTestNumber);

	// Shift a Given Value to the Next Power of Two
	double DLLEXPORT ShiftNextPowerOfTwo(double &a_dTestNumber);

}
#endif

