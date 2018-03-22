#include "vector_2.hpp"
#include "vector_3.hpp"
#include <cmath>
namespace engine {

	namespace math {

		vector_3 vector_3::Origin = vector_3();

		vector_3::vector_3()

			: x(0.0f)
			, y(0.0f)
			, z(0.0f)
			, length(0.0f)
		{}

		vector_3::vector_3(float _x, float _y, float _z)

			: x(_x)
			, y(_y)
			, z(_z)
			, length(0.0f)
		{
			//Calculate length
			Length();
		}

		vector_3::vector_3(float _uniform)

			: x(_uniform)
			, y(_uniform)
			, z(_uniform)
			, length(0.0f)
		{
			//Calculate length
			Length();
		}

		vector_3::vector_3(const vector_2& v2)

			: x(v2.x)
			, y(v2.y)
			, z(0.0f)
			, length(0.0f)
		{
			//Calculate length
			Length();
		}

		float vector_3::Length() const {

			return std::sqrt(x * x + y * y + z * z);
		}

		float vector_3::SquaredLength() const {

			return x * x + y * y + z * z;
		}

		float vector_3::Normalize() {

			// Calculate length
			Length();

			float inverseScale = 1.0f / length;
			x *= inverseScale;
			y *= inverseScale;
			z *= inverseScale;

			return length;
		}


		vector_3& vector_3::operator=(const vector_3& rhs) {

			// Prevent self assignment
			if (this == &rhs) return *this;

			x = rhs.x;
			y = rhs.y;
			z = rhs.z;

			return *this;
		}

		vector_3& vector_3::operator+=(const vector_3& rhs) {

			x = x + rhs.x;
			y = y + rhs.y;
			z = z + rhs.z;

			return *this;
		}

		vector_3& vector_3::operator-=(const vector_3& rhs) {

			x = x - rhs.x;
			y = y - rhs.y;
			z = z - rhs.z;

			return *this;
		}

		vector_3& vector_3::operator*=(const vector_3& rhs) {

			x = x * rhs.x;
			y = y * rhs.y;
			z = z * rhs.z;

			return *this;
		}

		vector_3& vector_3::operator/=(const vector_3& rhs) {

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			x = x / rhs.x;
			y = y / rhs.y;
			z = z / rhs.z;

			return *this;
		}


		vector_3 vector_3::operator+(const vector_3& rhs) const {

			return vector_3(
				x + rhs.x,
				y + rhs.y,
				z + rhs.z);
		}

		vector_3 vector_3::operator-(const vector_3& rhs) const {

			return vector_3(
				x - rhs.x,
				y - rhs.y,
				z - rhs.z);
		}

		vector_3 vector_3::operator*(const vector_3& rhs) const {

			return vector_3(
				x * rhs.x,
				y * rhs.y,
				z * rhs.z);
		}

		vector_3 vector_3::operator/(const vector_3& rhs) const {

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			return vector_3(
				x / rhs.x,
				y / rhs.y,
				z / rhs.z);
		}

		bool vector_3::operator==(const vector_3& rhs) const {

			return
				x == rhs.x &&
				y == rhs.y &&
				z == rhs.z;
		}

		bool vector_3::operator!=(const vector_3& rhs) const {

			return
				x != rhs.x ||
				y != rhs.y ||
				z != rhs.z;
		}

		vector_3 operator*(float scaleUnit, const vector_3& rhs) {

			return vector_3(
				scaleUnit * rhs.x,
				scaleUnit * rhs.y,
				scaleUnit * rhs.z);
		}

		vector_3 operator*(const vector_3& lhs, float scaleUnit) {

			return vector_3(
				scaleUnit * lhs.x,
				scaleUnit * lhs.y,
				scaleUnit * lhs.z);
		}


	}
}