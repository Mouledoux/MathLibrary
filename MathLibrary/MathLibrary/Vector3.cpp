#include "Vector3.h"
#include <cmath>

Vector3::Vector3(){}
Vector3::Vector3(float a_x, float a_y, float a_z)
	:x(a_x), y(a_y), z(a_z) {}

Vector3 Vector3::operator * (float rhs)			 const
{
	return Vector3(x * rhs, y * rhs, z * rhs);
}
Vector3 Vector3::operator / (float rhs)			 const
{
	return Vector3(x / rhs, y / rhs, z / rhs);
}
Vector3 Vector3::operator + (const Vector3 &rhs) const
{
	return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}
Vector3 Vector3::operator - (const Vector3 &rhs) const
{
	return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vector3 Vector3::operator - ()					 const
{
	return Vector3(x * -1, y * -1, z * -1);
}

Vector3 &Vector3::operator *= (float rhs)             
{
	return Vector3(x *= rhs, y *= rhs, z *= rhs);
}
Vector3 &Vector3::operator /= (float rhs)
{
	return Vector3(x /= rhs, y /= rhs, z /= rhs);
}
Vector3 &Vector3::operator += (const Vector3 &rhs)   
{
	return Vector3(x += rhs.x, y += rhs.y, z += rhs.z);
}
Vector3 &Vector3::operator -= (const Vector3 &rhs)   
{
	return Vector3(x -= rhs.x, y -= rhs.y, z -= rhs.z);
}

Vector3 &Vector3::operator =  (const Vector3 &rhs)   
{
	return Vector3(x = rhs.x, y = rhs.y, z = rhs.z);
}

bool Vector3::operator == (const Vector3 &rhs)	const
{
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}
bool Vector3::operator != (const Vector3 &rhs)	const
{
	return (x != rhs.x || y != rhs.y || z != rhs.z);
}

float Vector3::dot(const Vector3 &rhs)			const
{
	return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
}
float Vector3::angleBetween(const Vector3 &rhs)	const
{
	return acos(dot(rhs) / magnitude() * rhs.magnitude());
}

float    Vector3::magnitude()					const
{
	return sqrt((x * x) + (y * y) + (z * z));
}
Vector3  Vector3::cross(const Vector3 &rhs)		const
{
	return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
}
Vector3  Vector3::normal() const
{
	return *this / magnitude();
}
Vector3 &Vector3::normalize()
{
	return *this = normal();
}