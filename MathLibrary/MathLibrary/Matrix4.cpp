#include "Matrix4.h"
#include <cmath>

Matrix4::Matrix4()
	: m11(1), m12(0), m13(0), m14(0),
	  m21(0), m22(1), m23(0), m24(0),
	  m31(0), m32(0), m33(1), m34(0),
	  m41(0), m42(0), m43(1), m44(1){}
Matrix4::Matrix4(const Vector4 &col1, const Vector4 &col2, const Vector4 &col3, const Vector4 &col4)
	: m11(col1.x), m12(col2.x), m13(col3.x), m14(col4.x),
	m21(col1.y), m22(col2.y), m23(col3.y), m24(col4.y),
	m31(col1.z), m32(col2.z), m33(col3.z), m34(col4.z),
	m41(col1.z), m42(col2.z), m43(col3.z), m44(col4.z) {}
Matrix4::Matrix4(const Vector4 col[3])
	: v1(col[0]), v2(col[1]), v3(col[2]), v4(col[4]) {}
Matrix4::Matrix4(float m11, float m12, float m13, float m14,
				 float m21, float m22, float m23, float m24,
				 float m31, float m32, float m33, float m34,
				 float m41, float m42, float m43, float m44)
				 : m11(m11), m12(m12), m13(m13), m14(m14),
				   m21(m21), m22(m22), m23(m23), m24(m24),
				   m31(m31), m32(m32), m33(m33), m34(m34),
				   m41(m41), m42(m42), m43(m43), m44(m44){}

Matrix4 &Matrix4::Transpose()
{
	return *this = GetTranspose();
}
Matrix4 Matrix4::GetTranspose() const
{
	return Matrix4(m11, m21, m31, m41,
					m12, m22, m32, m42,
					m13, m23, m33, m43,
					m14, m24, m34, m44);
}

Matrix4 Matrix4::operator + (const Matrix4 &rhs) const
{
	return Matrix4(v1 + rhs.v1, v2 + rhs.v2, v3 + rhs.v3, v4 + rhs.v4);
}
Matrix4 Matrix4::operator - (const Matrix4 &rhs) const
{
	return Matrix4(v1 - rhs.v1, v2 - rhs.v2, v3 - rhs.v3, v4 - rhs.v4);
}
Matrix4 Matrix4::operator * (const Matrix4 &rhs) const
{
	return Matrix4( m11 * rhs.m11 + m12 * rhs.m21 + m13 * rhs.m31, // = m11
					m11 * rhs.m12 + m12 * rhs.m22 + m13 * rhs.m32, // = m12
					m11 * rhs.m13 + m12 * rhs.m23 + m13 * rhs.m33, // = m13
					m11 * rhs.m14 + m12 * rhs.m24 + m13 * rhs.m34, // = m14

					m21 * rhs.m11 + m22 * rhs.m21 + m23 * rhs.m31, // = m21
					m21 * rhs.m12 + m22 * rhs.m22 + m23 * rhs.m32, // = m22
					m21 * rhs.m13 + m22 * rhs.m23 + m23 * rhs.m33, // = m23
					m21 * rhs.m14 + m22 * rhs.m24 + m23 * rhs.m34, // = m24

					m31 * rhs.m11 + m32 * rhs.m21 + m33 * rhs.m31, // = m31
					m31 * rhs.m12 + m32 * rhs.m22 + m33 * rhs.m32, // = m32
					m31 * rhs.m13 + m32 * rhs.m23 + m33 * rhs.m33, // = m33
					m31 * rhs.m14 + m32 * rhs.m24 + m33 * rhs.m34, // = m34

					m41 * rhs.m11 + m42 * rhs.m21 + m43 * rhs.m31, // = m41
					m41 * rhs.m12 + m42 * rhs.m22 + m43 * rhs.m32, // = m42
					m41 * rhs.m13 + m42 * rhs.m23 + m43 * rhs.m33, // = m43
					m41 * rhs.m14 + m42 * rhs.m24 + m43 * rhs.m34  // = m44

		);
}
Vector4 Matrix4::operator * (const Vector4& rhs) const
{
	Matrix4 t = this->GetTranspose();
	return Vector4(t.v1.dot(rhs), t.v2.dot(rhs), t.v3.dot(rhs), t.v4.dot(rhs));
}

Matrix4 &Matrix4::operator  = (Matrix4 &rhs)
{
	return Matrix4(rhs.m11, rhs.m12, rhs.m11, rhs.m14,
					rhs.m21, rhs.m22, rhs.m21, rhs.m24,
					rhs.m31, rhs.m32, rhs.m31, rhs.m34,
					rhs.m41, rhs.m42, rhs.m43, rhs.m44);
}

Matrix4 &Matrix4::operator += (Matrix4 &rhs)
{
	return *this = *this + rhs;
}
Matrix4 &Matrix4::operator -= (Matrix4 &rhs)
{
	return *this = *this - rhs;
}
Matrix4 &Matrix4::operator *= (Matrix4 &rhs)
{
	return *this = *this * rhs;
}