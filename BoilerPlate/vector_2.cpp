#include <cmath>
#include "vector_2.hpp"


namespace engine
{
	namespace math
	{
		vector_2 vector_2::Origin = vector_2();

		vector_2::vector_2(){
			x = (0.0f);
			y = (0.0f);
			length = (0.0f);
		}

		vector_2::vector_2(float _x, float _y)
		{
			x = (_x);
			y = (_y);
			length = (0.0f);
			// Calculate Length
			Length();
		}

		vector_2::vector_2(float _uniform)
		{
			x = (_uniform);
			y = (_uniform);
			length = (0.0f);
			// Calculate Length
			Length();
		}

		float vector_2::Length() const
		{
			return std::sqrt(x * x + y * y);
		}

		float vector_2::SquaredLength() const
		{
			return x * x + y * y;
		}

		float vector_2::Normalize()
		{
			// Calculate length
			Length();

			float inverseScale = 1.0f / length;
			x *= inverseScale;
			y *= inverseScale;

			return length;
		}

		vector_2& vector_2::operator=(const vector_2& rhs)
		{
			// Prevent self assignment
			if (this == &rhs) return *this;

			x = rhs.x;
			y = rhs.y;

			return *this;
		}

		vector_2& vector_2::operator+=(const vector_2& rhs)
		{
			x = x + rhs.x;
			y = y + rhs.y;

			return *this;
		}

		vector_2& vector_2::operator-=(const vector_2& rhs)
		{
			x = x - rhs.x;
			y = y - rhs.y;

			return *this;
		}

		vector_2& vector_2::operator*=(const vector_2& rhs)
		{
			x = x * rhs.x;
			y = y * rhs.y;

			return *this;
		}

		vector_2& vector_2::operator/=(const vector_2& rhs)
		{
			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";

			x = x / rhs.x;
			y = y / rhs.y;

			return *this;
		}


		vector_2 vector_2::operator+(const vector_2& rhs) const
		{
			return vector_2(
				x + rhs.x,
				y + rhs.y);
		}

		vector_2 vector_2::operator-(const vector_2& rhs) const
		{
			return vector_2(
				x - rhs.x,
				y - rhs.y);
		}

		vector_2 vector_2::operator*(const vector_2& rhs) const
		{
			return vector_2(
				x * rhs.x,
				y * rhs.y);
		}

		vector_2 vector_2::operator/(const vector_2& rhs) const
		{
			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";

			return vector_2(
				x / rhs.x,
				y / rhs.y);
		}

		bool vector_2::operator==(const vector_2& rhs) const
		{
			return
				x == rhs.x &&
				y == rhs.y;
		}

		bool vector_2::operator!=(const vector_2& rhs) const
		{
			return
				x != rhs.x ||
				y != rhs.y;
		}

		vector_2 operator*(float scaleUnit, const vector_2& rhs)
		{
			return vector_2(
				scaleUnit * rhs.x,
				scaleUnit * rhs.y);
		}

		vector_2 operator*(const vector_2& lhs, float scaleUnit)
		{
			return vector_2(
				scaleUnit * lhs.x,
				scaleUnit * lhs.y);
		}
	}
}