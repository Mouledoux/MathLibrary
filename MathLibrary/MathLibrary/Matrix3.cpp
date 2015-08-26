#include "Matrix3.h"
#include <cmath>

Matrix3::Matrix3() 
	: m11(1), m12(0), m13(0),
	  m21(0), m22(1), m23(0),
	  m31(0), m32(0), m33(1){}
Matrix3::Matrix3(const Vector3 &col1, const Vector3 &col2, const Vector3 &col3)
	: m11(col1.x), m12(col2.x), m13(col3.x),
	  m21(col1.y), m22(col2.y), m23(col3.y),
	  m31(col1.z), m32(col2.z), m33(col3.z) {}
Matrix3::Matrix3(const Vector3 col[3])
	: v1(col[0]), v2(col[1]), v3(col[2]) {}
Matrix3::Matrix3(float m11, float m12, float m13,
				 float m21, float m22, float m23,
				 float m31, float m32, float m33)
				 : m11(m11), m12(m12), m13(m13),
				   m21(m21), m22(m22), m23(m23),
				   m31(m31), m32(m32), m33(m33) {}

Matrix3 &Matrix3::Transpose()
{
	return *this = GetTranspose();
}
Matrix3  Matrix3::GetTranspose() const
{
	return Matrix3(m11, m21, m31,
				   m12, m22, m32,
				   m13, m23, m33);
}

Matrix3 Matrix3::operator + (const Matrix3 &rhs) const
{
	return Matrix3(v1 + rhs.v1, v2 + rhs.v2, v3 + rhs.v3);
}
Matrix3 Matrix3::operator - (const Matrix3 &rhs) const
{
	return Matrix3(v1 - rhs.v1, v2 - rhs.v2, v3 - rhs.v3);
}
Matrix3 Matrix3::operator * (const Matrix3 &rhs) const
{
	return Matrix3(m11 * rhs.m11 + m12 * rhs.m21 + m13 * rhs.m31, // = m11
				   m11 * rhs.m12 + m12 * rhs.m22 + m13 * rhs.m32, // = m12
				   m11 * rhs.m13 + m12 * rhs.m23 + m13 * rhs.m33, // = m13

				   m21 * rhs.m11 + m22 * rhs.m21 + m23 * rhs.m31, // = m21
				   m21 * rhs.m12 + m22 * rhs.m22 + m23 * rhs.m32, // = m22
				   m21 * rhs.m13 + m22 * rhs.m23 + m23 * rhs.m33, // = m23

				   m31 * rhs.m11 + m32 * rhs.m21 + m33 * rhs.m31, // = m31
				   m31 * rhs.m12 + m32 * rhs.m22 + m33 * rhs.m32, // = m32
				   m31 * rhs.m13 + m32 * rhs.m23 + m33 * rhs.m33  // = m33
				   );
}
Vector3 Matrix3::operator * (const Vector3& rhs) const
{
	Matrix3 t = this->GetTranspose();
	return Vector3(t.v1.dot(rhs), t.v2.dot(rhs), t.v3.dot(rhs));
}

Matrix3 &Matrix3::operator  = (Matrix3 &rhs)
{
	return Matrix3(rhs.m11, rhs.m12, rhs.m11,
				   rhs.m21, rhs.m22, rhs.m21,
				   rhs.m31, rhs.m32, rhs.m31);
}

Matrix3 &Matrix3::operator += (Matrix3 &rhs)
{
	return *this = *this + rhs;
}
Matrix3 &Matrix3::operator -= (Matrix3 &rhs)
{
	return *this = *this - rhs;
}
Matrix3 &Matrix3::operator *= (Matrix3 &rhs)
{
	return *this = *this * rhs;
}

bool Matrix3::operator == (const Matrix3 &rhs)const
{
	return v1 == rhs.v1 && v2 == rhs.v2 && v3 == rhs.v3;
}
bool Matrix3::operator != (const Matrix3 &rhs)const
{
	return v1 != rhs.v1 || v2 != rhs.v2 || v3 != rhs.v3;
}