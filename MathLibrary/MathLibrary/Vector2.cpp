#include "Vector2.h"
#include <cmath>

Vector2::Vector2(){}
Vector2::Vector2(float a_x, float a_y)
	:x(a_x), y(a_y) {}

Vector2 Vector2::operator * (float rhs)			const
{
	return Vector2(x * rhs, y * rhs);
}
Vector2 Vector2::operator / (float rhs)			const
{
	return Vector2(x / rhs, y / rhs);
}
Vector2 Vector2::operator + (const Vector2 &rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}
Vector2 Vector2::operator - (const Vector2 &rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator - ()					const
{
	return Vector2(x * -1, y * -1);
}

Vector2 &Vector2::operator *= (float rhs)
{
	return Vector2(x *= rhs, y *= rhs);
}
Vector2 &Vector2::operator /= (float rhs)
{
	return Vector2(x /= rhs, y /= rhs);
}
Vector2 &Vector2::operator += (const Vector2 &rhs)
{
	return Vector2(x += rhs.x, y += rhs.y);
}
Vector2 &Vector2::operator -= (const Vector2 &rhs)
{
	return Vector2(x -= rhs.x, y -= rhs.y);
}

Vector2 &Vector2::operator =  (const Vector2 &rhs)
{
	return Vector2(x = rhs.x, y = rhs.y);
}

bool Vector2::operator == (const Vector2 &rhs)	const
{
	return (x == rhs.x && y == rhs.y);
}
bool Vector2::operator != (const Vector2 &rhs)	const
{
	return (x != rhs.x || y != rhs.y);
}

float Vector2::dot(const Vector2 &rhs)			const
{
	return ((x * rhs.x) + (y * rhs.y));
}
float Vector2::angle()							const
{
	return atan2f(y, x);
}
float Vector2::angleBetween(const Vector2 &rhs)	const
{
	return acos(dot(rhs) / magnitude() * rhs.magnitude());
}

float    Vector2::magnitude()						const
{
	return sqrt((x * x) + (y * y));
}
Vector2  Vector2::normal() const
{
	return *this/ magnitude();
}
Vector2 &Vector2::normalize()  						 						 
{
	return *this = normal();
}