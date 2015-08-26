#pragma once
#define RAD2DEG 57.2957795
#define DEG2RAD 0.0174532925

class Vector4
{
public:
	union
	{
		struct { float x, y, z, w; };
		float v[4];
	};

	Vector4();
	Vector4(float a_x, float a_y, float a_z, float a_w);

	Vector4 operator * (float rhs)			const;
	Vector4 operator / (float rhs)			const;
	Vector4 operator + (const Vector4 &rhs) const;
	Vector4 operator - (const Vector4 &rhs) const;

	Vector4 operator - ()				    const;

	Vector4& operator *= (float rhs);
	Vector4& operator /= (float rhs);
	Vector4& operator += (const Vector4 &rhs);
	Vector4& operator -= (const Vector4 &rhs);

	Vector4& operator = (const Vector4 &rhs);

	bool operator == (const Vector4 &rhs)	const;
	bool operator != (const Vector4 &rhs)	const;

	float dot(const Vector4 &rhs)			const;
	float angleBetween(const Vector4 &rhs)	const;

	float    magnitude()					const;
	Vector4  cross(const Vector4 &rhs)		const;
	Vector4  normal()						const;
	Vector4 &normalize();
};