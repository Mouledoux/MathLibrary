#pragma once
#define RAD2DEG 57.2957795
#define DEG2RAD 0.0174532925

class Vector2
{
public:
	union
	{
		struct { float x, y; };
		float v[2];
	};

	Vector2();
	Vector2(float a_x, float a_y);

	Vector2 operator * (float rhs)			const;
	Vector2 operator / (float rhs)			const;
	Vector2 operator + (const Vector2 &rhs) const;
	Vector2 operator - (const Vector2 &rhs) const;

	Vector2 operator - ()				    const;

	Vector2 &operator *= (float rhs);
	Vector2 &operator /= (float rhs);
	Vector2 &operator += (const Vector2 &rhs);
	Vector2 &operator -= (const Vector2 &rhs);

	Vector2 &operator = (const Vector2 &rhs);

	bool operator == (const Vector2 &rhs)	const;
	bool operator != (const Vector2 &rhs)	const;

	float dot(const Vector2 &rhs)			const;
	float angle()							const;
	float angleBetween(const Vector2 &rhs)	const;

	float magnitude() const;
	Vector2 normal()  const;
	Vector2 &normalize();
};