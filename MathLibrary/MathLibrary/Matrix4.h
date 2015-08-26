#pragma once
#include "Vector4.h"

class Matrix4
{
public:
	union
	{
		float m[16];
		float mm[4][4];
		struct { Vector4 v1, v2, v3, v4; };
		struct { float m1, m2, m3, m4, m5, m6, m7, m8, m9, mn10, m11, m12, m13, m14, m15, m16; };
		struct 
		{
			float m11, m12, m13, m14,
				  m21, m22, m23, m24,
				  m31, m32, m33, m34,
				  m41, m42, m43,m44;
		};
	};

	Matrix4();
	Matrix4(const Vector4 &col1,
			const Vector4 &col2,
			const Vector4 &col3,
			const Vector4 &col4);

	Matrix4(const Vector4 col[4]);
	Matrix4(float m[16]);
	Matrix4(float mm[4][4]);
	Matrix4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);

	static Matrix4 Identity() { static Matrix4 id; return id; }
	Matrix4& Transpose();
	Matrix4 GetTranspose() const;

	Matrix4 operator + (const Matrix4 &rhs) const;
	Matrix4 operator - (const Matrix4 &rhs) const;
	Matrix4 operator * (const Matrix4 &rhs) const;
	Vector4 operator * (const Vector4 &rhs) const;

	Matrix4 &operator = (Matrix4 & rhs);

	Matrix4& operator += (Matrix4 &rhs);
	Matrix4& operator -= (Matrix4 &rhs);
	Matrix4& operator *= (Matrix4 &rhs);
};