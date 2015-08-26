#pragma once
#define RAD2DEG 57.2957795
#define DEG2RAD 0.0174532925

class Vector3
{
public:
	union
	{
		struct { float x, y, z; };
		float v[3];
	};

	Vector3();
	Vector3(float a_x, float a_y, float a_z);

	Vector3 operator * (float rhs)			const;
	Vector3 operator / (float rhs)			const;
	Vector3 operator + (const Vector3 &rhs) const;
	Vector3 operator - (const Vector3 &rhs) const;

	Vector3 operator - ()				    const;

	Vector3 &operator *= (float rhs);
	Vector3 &operator /= (float rhs);
	Vector3 &operator += (const Vector3 &rhs);
	Vector3 &operator -= (const Vector3 &rhs);

	Vector3 &operator = (const Vector3 &rhs);

	bool operator == (const Vector3 &rhs)	const;
	bool operator != (const Vector3 &rhs)	const;

	float dot(const Vector3 &rhs)			const;
	float angleBetween(const Vector3 &rhs)	const;

	float magnitude() const;
	Vector3 cross(const Vector3 &rhs)		const;
	Vector3 normal()  const;
	Vector3 &normalize();
};