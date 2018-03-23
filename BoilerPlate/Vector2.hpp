#pragma once

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

namespace engine
{
	namespace math
	{
		struct vector2
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static vector2 Origin;

			/* ==========================
			* CTOR
			* ==========================*/
			vector2();
			vector2(float, float);
			vector2(float);

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			float   Length() const;
			float   SquaredLength() const;
			float	Normalize();

			/* ==========================
			* OPERATORS
			* ==========================*/
			vector2& operator= (const vector2&);
			vector2& operator+=(const vector2&);
			vector2& operator-=(const vector2&);
			vector2& operator*=(const vector2&);
			vector2& operator/=(const vector2&);
			vector2  operator+(const vector2&) const;
			vector2  operator-(const vector2&) const;
			vector2  operator*(const vector2&) const;
			vector2  operator/(const vector2&) const;
			bool     operator==(const vector2&) const;
			bool     operator!=(const vector2&) const;
			friend vector2 operator*(float, const vector2&);
			friend vector2 operator*(const vector2&, float);

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