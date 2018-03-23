#include "vector2.hpp"
#include <cmath>

namespace engine
{
	namespace math
	{
		vector2 vector2::Origin = vector2();

		vector2::vector2(){
			x = (0.0f);
			y = (0.0f);
			length = (0.0f);
		}

		vector2::vector2(float _x, float _y)
		{
			x = (_x);
			y = (_y);
			length = (0.0f);
			// Calculate Length
			Length();
		}

		vector2::vector2(float _uniform)
		{
			x = (_uniform);
			y = (_uniform);
			length = (0.0f);
			// Calculate Length
			Length();
		}

		float vector2::Length() const
		{
			return std::sqrt(x * x + y * y);
		}

		float vector2::SquaredLength() const
		{
			return x * x + y * y;
		}

		float vector2::Normalize()
		{
			// Calculate length
			Length();

			float inverseScale = 1.0f / length;
			x *= inverseScale;
			y *= inverseScale;

			return length;
		}

		vector2& vector2::operator=(const vector2& rhs)
		{
			// Prevent self assignment
			if (this == &rhs) return *this;

			x = rhs.x;
			y = rhs.y;

			return *this;
		}

		vector2& vector2::operator+=(const vector2& rhs)
		{
			x = x + rhs.x;
			y = y + rhs.y;

			return *this;
		}

		vector2& vector2::operator-=(const vector2& rhs)
		{
			x = x - rhs.x;
			y = y - rhs.y;

			return *this;
		}

		vector2& vector2::operator*=(const vector2& rhs)
		{
			x = x * rhs.x;
			y = y * rhs.y;

			return *this;
		}

		vector2& vector2::operator/=(const vector2& rhs)
		{
			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";

			x = x / rhs.x;
			y = y / rhs.y;

			return *this;
		}


		vector2 vector2::operator+(const vector2& rhs) const
		{
			return vector2(
				x + rhs.x,
				y + rhs.y);
		}

		vector2 vector2::operator-(const vector2& rhs) const
		{
			return vector2(
				x - rhs.x,
				y - rhs.y);
		}

		vector2 vector2::operator*(const vector2& rhs) const
		{
			return vector2(
				x * rhs.x,
				y * rhs.y);
		}

		vector2 vector2::operator/(const vector2& rhs) const
		{
			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";

			return vector2(
				x / rhs.x,
				y / rhs.y);
		}

		bool vector2::operator==(const vector2& rhs) const
		{
			return
				x == rhs.x &&
				y == rhs.y;
		}

		bool vector2::operator!=(const vector2& rhs) const
		{
			return
				x != rhs.x ||
				y != rhs.y;
		}

		vector2 operator*(float scaleUnit, const vector2& rhs)
		{
			return vector2(
				scaleUnit * rhs.x,
				scaleUnit * rhs.y);
		}

		vector2 operator*(const vector2& lhs, float scaleUnit)
		{
			return vector2(
				scaleUnit * lhs.x,
				scaleUnit * lhs.y);
		}
	}
}