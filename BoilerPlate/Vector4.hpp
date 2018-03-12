#pragma once
#ifndef _VECTOR4_H_
#define _VECTOR4_H_

namespace engine
{
	namespace math
	{
		struct Vector2;
		struct Vector3;
		struct Vector4
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static Vector4 Origin;

			/* ==========================
			* CTOR
			* ==========================*/
			Vector4();
			Vector4(float, float, float, float);
			Vector4(float);
			Vector4(const Vector2&);
			Vector4(const Vector3&);

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			float   vectorLength() const;
			float   squaredLength() const;
			float	normalize();

			/* ==========================
			* OPERATORS
			* ==========================*/
			Vector4& operator= (const Vector4&);
			Vector4& operator+=(const Vector4&);
			Vector4& operator-=(const Vector4&);
			Vector4& operator*=(const Vector4&);
			Vector4& operator/=(const Vector4&);
			Vector4  operator+(const Vector4&) const;
			Vector4  operator-(const Vector4&) const;
			Vector4  operator*(const Vector4&) const;
			Vector4  operator/(const Vector4&) const;
			bool     operator==(const Vector4&) const;
			bool     operator!=(const Vector4&) const;
			friend Vector4 operator*(float, const Vector4&);
			friend Vector4 operator*(const Vector4&, float);

			/* ==========================
			* MEMBERS
			* ==========================*/
			float x;
			float y;
			float z;
			float w;
			float length;
		};
	}
}
#endif // !_VECTOR4_H_