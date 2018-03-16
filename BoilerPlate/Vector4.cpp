#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Vector4.hpp"
#include <cMath>

namespace Engine
{
	namespace Math
	{
		Vector4 Vector4::Origin = Vector4();

		Vector4::Vector4() {

			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
			length = 0.0f;
		
		}

		Vector4::Vector4(float _x, float _y, float _z, float _w) {

			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 0.0f;
			length = 0.0f;

		
			// Calculate Length
			vectorLength();
		}

		Vector4::Vector4(float _uniform){

			x = _uniform;
			y = _uniform;
			z = _uniform;
			w = _uniform;
			length = 0.0f;

		
			// Calculate Length
			vectorLength();
		}

		Vector4::Vector4(const Vector2& vec2) {

			x = vec2.x;
			y = vec2.y;
			z = 0.0f;
			w = 0.0f;
			length = 0.0f;


			// Calculate Length
			vectorLength();
		}

		Vector4::Vector4(const Vector3& vec3) {

			x = vec3.x;
			y = vec3.y;
			z = vec3.z;
			w = 0.0f;
			length = 0.0f;


			// Calculate Length
			vectorLength();
		}


		float Vector4::vectorLength() const{

			return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) + std::pow(w, 2));
		}


		float Vector4::squaredLength() const {

			return (std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2) + std::pow(w, 2));
		}

		float Vector4::normalize() {

			// Calculate length
			vectorLength();

			float inverseScale = 1.0f / length;
			x *= inverseScale;
			y *= inverseScale;
			z *= inverseScale;

			return length;
		}


		Vector4& Vector4::operator=(const Vector4& rhs) {

			// Prevent self assignment
			if (this == &rhs) return *this;

			x = rhs.x;
			y = rhs.y;
			z = rhs.z;

			return *this;
		}


		Vector4& Vector4::operator+=(const Vector4& rhs) {

			x = x + rhs.x;
			y = y + rhs.y;
			z = z + rhs.z;

			return *this;
		}


		Vector4& Vector4::operator-=(const Vector4& rhs) {

			x = x - rhs.x;
			y = y - rhs.y;
			z = z - rhs.z;

			return *this;
		}


		Vector4& Vector4::operator*=(const Vector4& rhs) {

			x = x * rhs.x;
			y = y * rhs.y;
			z = z * rhs.z;

			return *this;
		}


		Vector4& Vector4::operator/=(const Vector4& rhs) {

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			x = x / rhs.x;
			y = y / rhs.y;
			z = z / rhs.z;

			return *this;
		}


		Vector4 Vector4::operator+(const Vector4& rhs) const {

			return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
		}


		Vector4 Vector4::operator-(const Vector4& rhs) const {

			return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
		}


		Vector4 Vector4::operator*(const Vector4& rhs) const {

			return Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w);
		}


		Vector4 Vector4::operator/(const Vector4& rhs) const {

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			return Vector4(x / rhs.x, y / rhs.y, z / rhs.z, w / rhs.w);
		}


		bool Vector4::operator==(const Vector4& rhs) const {

			return
				x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
		}


		bool Vector4::operator!=(const Vector4& rhs) const {

			return
				x != rhs.x || y != rhs.y || z != rhs.z || w != rhs.w;
		}


		Vector4 operator*(float scaleUnit, const Vector4& rhs) {

			return Vector4(scaleUnit * rhs.x, scaleUnit * rhs.y, scaleUnit * rhs.z, scaleUnit * rhs.w);
		}


		Vector4 operator*(const Vector4& lhs, float scaleUnit) {

			return Vector4(scaleUnit * lhs.x, scaleUnit * lhs.y, scaleUnit * lhs.z, scaleUnit * lhs.w);
		}
	}
}
