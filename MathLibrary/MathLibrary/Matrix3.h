#pragma once
#include "Vector3.h"

class Matrix3
{
public:
	union
	{
		float m[9];
		float mm[3][3];
		struct { Vector3 v1, v2, v3; };
		struct { float m1, m2, m3, m4, m5, m6, m7, m8, m9; };
		struct { float m11, m12, m13,
					   m21, m22, m23,
				       m31, m32, m33; };
	};

	Matrix3();
	Matrix3(const Vector3 &col1,
			const Vector3 &col2,
			const Vector3 &col3);
	Matrix3(const Vector3 col[3]);
	Matrix3(float m[9]);
	Matrix3(float mm[3][3]);
	Matrix3(float m11, float m12, float m13,
			float m21, float m22, float m23,
			float m31, float m32, float m33);

	static Matrix3 Identity() { static Matrix3 id; return id; }
	Matrix3& Transpose();
	Matrix3  GetTranspose() const;

	Matrix3 operator + (const Matrix3 &rhs) const;
	Matrix3 operator - (const Matrix3 &rhs) const;
	Matrix3 operator * (const Matrix3 &rhs) const;
	Vector3 operator * (const Vector3 &rhs) const;

	Matrix3 &operator = (Matrix3 & rhs);

	Matrix3 &operator += (Matrix3 &rhs);
	Matrix3 &operator -= (Matrix3 &rhs);
	Matrix3 &operator *= (Matrix3 &rhs);

	bool operator == (const Matrix3 &rhs) const;
	bool operator != (const Matrix3 &rhs) const;
};