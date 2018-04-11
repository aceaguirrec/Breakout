#pragma once

#ifndef _VECTOR3_H_
#define _VECTOR3_H_
#include "Vector2.hpp"
namespace engine
{
	namespace math
	{
		struct vector2;
		class vector3
		{
		public:
			/* ==========================
			* STATIC
			* ==========================*/
			static vector3 Origin;

			/* ==========================
			* CTOR
			* ==========================*/
			vector3();
			vector3(float, float, float);
			vector3(float);
			vector3(const vector2&);

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			float   Length() const;
			float   SquaredLength() const;
			float	Normalize();
			vector3 cross_product(const vector3 &, const vector3 &);

			/* ==========================
			* OPERATORS
			* ==========================*/
			vector3& operator= (const vector3&);
			vector3& operator+=(const vector3&);
			vector3& operator-=(const vector3&);
			vector3& operator*=(const vector3&);
			vector3& operator/=(const vector3&);
			vector3  operator+(const vector3&) const;
			vector3  operator-(const vector3&) const;
			vector3  operator*(const vector3&) const;
			vector3  operator/(const vector3&) const;
			bool     operator==(const vector3&) const;
			bool     operator!=(const vector3&) const;
			friend vector3 operator*(float, const vector3&);
			friend vector3 operator*(const vector3&, float);

			/* ==========================
			* MEMBERS
			* ==========================*/
			float x;
			float y;
			float z;
			float length;
		};
	}
}

#endif // !_VECTOR3_H_