#pragma once

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

namespace engine
{
	namespace math
	{
		struct vector_2;
		struct vector_3
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static vector_3 Origin;

			/* ==========================
			* CTOR
			* ==========================*/
			vector_3();
			vector_3(float, float, float);
			vector_3(float);
			vector_3(const vector_2&);

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			float   Length() const;
			float   SquaredLength() const;
			float	Normalize();

			/* ==========================
			* OPERATORS
			* ==========================*/
			vector_3& operator= (const vector_3&);
			vector_3& operator+=(const vector_3&);
			vector_3& operator-=(const vector_3&);
			vector_3& operator*=(const vector_3&);
			vector_3& operator/=(const vector_3&);
			vector_3  operator+(const vector_3&) const;
			vector_3  operator-(const vector_3&) const;
			vector_3  operator*(const vector_3&) const;
			vector_3  operator/(const vector_3&) const;
			bool     operator==(const vector_3&) const;
			bool     operator!=(const vector_3&) const;
			friend vector_3 operator*(float, const vector_3&);
			friend vector_3 operator*(const vector_3&, float);

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