#include "Vector4.h"
#include <cmath>

Vector4::Vector4(){}
Vector4::Vector4(float a_x, float a_y, float a_z, float a_w)
	:x(a_x), y(a_y), z(a_z), w(a_w) {}

Vector4 Vector4::operator * (float rhs)			 const
{
	return Vector4(x * rhs, y * rhs, z * rhs, w * rhs);
}
Vector4 Vector4::operator / (float rhs)			 const
{
	return Vector4(x / rhs, y / rhs, z / rhs, w / rhs);
}
Vector4 Vector4::operator + (const Vector4 &rhs) const
{
	return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
}
Vector4 Vector4::operator - (const Vector4 &rhs) const
{
	return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}

Vector4 Vector4::operator - ()					 const
{
	return Vector4(x * -1, y * -1, z * -1, w * -1);
}

Vector4 &Vector4::operator *= (float rhs)
{
	return Vector4(x *= rhs, y *= rhs, z *= rhs, w *= rhs);
}
Vector4 &Vector4::operator /= (float rhs)
{
	return Vector4(x /= rhs, y /= rhs, z /= rhs, w /= rhs);
}
Vector4 &Vector4::operator += (const Vector4 &rhs)
{
	return Vector4(x += rhs.x, y += rhs.y, z += rhs.z, w += rhs.w);
}
Vector4 &Vector4::operator -= (const Vector4 &rhs)
{
	return Vector4(x -= rhs.x, y -= rhs.y, z -= rhs.z, w -= rhs.w);
}

Vector4 &Vector4::operator =  (const Vector4 &rhs)
{
	return Vector4(x = rhs.x, y = rhs.y, z = rhs.z, w = rhs.w);
}

bool Vector4::operator == (const Vector4 &rhs)	const
{
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w);
}
bool Vector4::operator != (const Vector4 &rhs)	const
{
	return (x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w);
}

float Vector4::dot(const Vector4 &rhs)			const
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w));
}
float Vector4::angleBetween(const Vector4 &rhs)	const
{
	return acos(dot(rhs) / magnitude() * rhs.magnitude());
}

float    Vector4::magnitude()				    const
{
	return sqrt((x * x) + (y * y) + (z * z) + (w * w));
}
Vector4  Vector4::normal()						const
{
	return *this / magnitude();
}
Vector4 &Vector4::normalize()
{
	return *this = normal();
}