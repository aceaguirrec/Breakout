#pragma once

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

namespace engine
{
	namespace math
	{
		struct vector_2
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static vector_2 Origin;

			/* ==========================
			* CTOR
			* ==========================*/
			vector_2();
			vector_2(float, float);
			vector_2(float);

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			float   Length() const;
			float   SquaredLength() const;
			float	Normalize();

			/* ==========================
			* OPERATORS
			* ==========================*/
			vector_2& operator= (const vector_2&);
			vector_2& operator+=(const vector_2&);
			vector_2& operator-=(const vector_2&);
			vector_2& operator*=(const vector_2&);
			vector_2& operator/=(const vector_2&);
			vector_2  operator+(const vector_2&) const;
			vector_2  operator-(const vector_2&) const;
			vector_2  operator*(const vector_2&) const;
			vector_2  operator/(const vector_2&) const;
			bool     operator==(const vector_2&) const;
			bool     operator!=(const vector_2&) const;
			friend vector_2 operator*(float, const vector_2&);
			friend vector_2 operator*(const vector_2&, float);

			/* ==========================
			* MEMBERS
			* ==========================*/
			float x;
			float y;
			float length;
		};
	}
}

#endif // !_VECTOR2_H_