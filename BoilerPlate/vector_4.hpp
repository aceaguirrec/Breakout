#pragma once
#ifndef _VECTOR4_H_
#define _VECTOR4_H_

namespace engine
{
	namespace math
	{
		struct vector_2;
		struct vector_3;
		struct vector_4
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static vector_4 Origin;

			/* ==========================
			* CTOR
			* ==========================*/
			vector_4();
			vector_4(float, float, float, float);
			vector_4(float);
			vector_4(const vector_2&);
			vector_4(const vector_3&);

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			float   Length() const;
			float   SquaredLength() const;
			float	Normalize();

			/* ==========================
			* OPERATORS
			* ==========================*/
			vector_4& operator= (const vector_4&);
			vector_4& operator+=(const vector_4&);
			vector_4& operator-=(const vector_4&);
			vector_4& operator*=(const vector_4&);
			vector_4& operator/=(const vector_4&);
			vector_4  operator+(const vector_4&) const;
			vector_4  operator-(const vector_4&) const;
			vector_4  operator*(const vector_4&) const;
			vector_4  operator/(const vector_4&) const;
			bool     operator==(const vector_4&) const;
			bool     operator!=(const vector_4&) const;
			friend vector_4 operator*(float, const vector_4&);
			friend vector_4 operator*(const vector_4&, float);

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