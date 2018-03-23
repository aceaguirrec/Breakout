#include "vector3.hpp"
#include <cmath>

namespace engine {

	namespace math {

		vector3 vector3::Origin = vector3();

		vector3::vector3()

			: x(0.0f)
			, y(0.0f)
			, z(0.0f)
			, length(0.0f)
		{}

		vector3::vector3(float _x, float _y, float _z)

			: x(_x)
			, y(_y)
			, z(_z)
			, length(0.0f)
		{
			//Calculate length
			Length();
		}

		vector3::vector3(float _uniform)

			: x(_uniform)
			, y(_uniform)
			, z(_uniform)
			, length(0.0f)
		{
			//Calculate length
			Length();
		}

		vector3::vector3(const vector2& v2)

			: x(v2.x)
			, y(v2.y)
			, z(0.0f)
			, length(0.0f)
		{
			//Calculate length
			Length();
		}

		float vector3::Length() const {

			return std::sqrt(x * x + y * y + z * z);
		}

		float vector3::SquaredLength() const {

			return x * x + y * y + z * z;
		}

		float vector3::Normalize() {

			// Calculate length
			Length();

			float inverseScale = 1.0f / length;
			x *= inverseScale;
			y *= inverseScale;
			z *= inverseScale;

			return length;
		}
		vector3 vector3::cross_product(const vector3& pLeftSide, const vector3& pRightSide)
		{
			vector3 resultVector;
			resultVector.x = pLeftSide.y * pRightSide.z - pLeftSide.z * pRightSide.y;
			resultVector.y = pLeftSide.z * pRightSide.x - pLeftSide.x * pRightSide.z;
			resultVector.z = pLeftSide.x * pRightSide.y - pLeftSide.y * pRightSide.x;

			return resultVector;
		}

		vector3& vector3::operator=(const vector3& rhs) {

			// Prevent self assignment
			if (this == &rhs) return *this;

			x = rhs.x;
			y = rhs.y;
			z = rhs.z;

			return *this;
		}

		vector3& vector3::operator+=(const vector3& rhs) {

			x = x + rhs.x;
			y = y + rhs.y;
			z = z + rhs.z;

			return *this;
		}

		vector3& vector3::operator-=(const vector3& rhs) {

			x = x - rhs.x;
			y = y - rhs.y;
			z = z - rhs.z;

			return *this;
		}

		vector3& vector3::operator*=(const vector3& rhs) {

			x = x * rhs.x;
			y = y * rhs.y;
			z = z * rhs.z;

			return *this;
		}

		vector3& vector3::operator/=(const vector3& rhs) {

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			x = x / rhs.x;
			y = y / rhs.y;
			z = z / rhs.z;

			return *this;
		}


		vector3 vector3::operator+(const vector3& rhs) const {

			return vector3(
				x + rhs.x,
				y + rhs.y,
				z + rhs.z);
		}

		vector3 vector3::operator-(const vector3& rhs) const {

			return vector3(
				x - rhs.x,
				y - rhs.y,
				z - rhs.z);
		}

		vector3 vector3::operator*(const vector3& rhs) const {

			return vector3(
				x * rhs.x,
				y * rhs.y,
				z * rhs.z);
		}

		vector3 vector3::operator/(const vector3& rhs) const {

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			return vector3(
				x / rhs.x,
				y / rhs.y,
				z / rhs.z);
		}

		bool vector3::operator==(const vector3& rhs) const {

			return
				x == rhs.x &&
				y == rhs.y &&
				z == rhs.z;
		}

		bool vector3::operator!=(const vector3& rhs) const {

			return
				x != rhs.x ||
				y != rhs.y ||
				z != rhs.z;
		}

		vector3 operator*(float scaleUnit, const vector3& rhs) {

			return vector3(
				scaleUnit * rhs.x,
				scaleUnit * rhs.y,
				scaleUnit * rhs.z);
		}

		vector3 operator*(const vector3& lhs, float scaleUnit) {

			return vector3(
				scaleUnit * lhs.x,
				scaleUnit * lhs.y,
				scaleUnit * lhs.z);
		}


	}
}