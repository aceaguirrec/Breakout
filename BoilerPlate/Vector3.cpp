#include "Vector3.hpp"
#include "Vector2.hpp"
#include <cmath>
namespace engine {

	namespace math {

		Vector3 Vector3::Origin = Vector3();

		Vector3::Vector3() {

			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			length = 0.0f;
		}

		Vector3::Vector3(float _x, float _y, float _z) {

			x = _x;
			y = _y;
			z = _z;
			length = 0.0f;

			//Calculate length
			vectorLength();
		}

		Vector3::Vector3(float _uniform) {

			x = _uniform;
			y = _uniform;
			z = _uniform;
			length = 0.0f;

			//Calculate length
			vectorLength();
		}

		Vector3::Vector3(const Vector2& v2) {

			x = v2.x;
			y = v2.y;
			z = 0.0f;
			length = 0.0f;

			//Calculate length
			vectorLength();
		}

		float Vector3::vectorLength() const {

			return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
		}

		float Vector3::squaredLength() const{

			return (std::pow(x, 2) + std::pow(y, 2));
		}

		float Vector3::normalize(){

			// Calculate length
			vectorLength();

			float inverseScale = 1.0f / length;
			x *= inverseScale;
			y *= inverseScale;
			z *= inverseScale;

			return length;
		}


		Vector3& Vector3::operator=(const Vector3& rhs){

			// Prevent self assignment
			if (this == &rhs) return *this;

			x = rhs.x;
			y = rhs.y;
			z = rhs.z;

			return *this;
		}

		Vector3& Vector3::operator+=(const Vector3& rhs){

			x = x + rhs.x;
			y = y + rhs.y;
			z = z + rhs.z;
			 
			return *this;
		}

		Vector3& Vector3::operator-=(const Vector3& rhs){

			x = x - rhs.x;
			y = y - rhs.y;
			z = z - rhs.z;

			return *this;
		}

		Vector3& Vector3::operator*=(const Vector3& rhs){

			x = x * rhs.x;
			y = y * rhs.y;
			z = z * rhs.z;

			return *this;
		}

		Vector3& Vector3::operator/=(const Vector3& rhs){

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			x = x / rhs.x;
			y = y / rhs.y;
			z = z / rhs.z;

			return *this;
		}


		Vector3 Vector3::operator+(const Vector3& rhs) const{

			return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
				
		}

		Vector3 Vector3::operator-(const Vector3& rhs) const{

			return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
		}

		Vector3 Vector3::operator*(const Vector3& rhs) const{

			return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
		}

		Vector3 Vector3::operator/(const Vector3& rhs) const{

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			return Vector3(x / rhs.x, y / rhs.y, z / rhs.z);
		}

		bool Vector3::operator==(const Vector3& rhs) const{

			return
				x == rhs.x && y == rhs.y && z == rhs.z;
		}

		bool Vector3::operator!=(const Vector3& rhs) const{

			return
				x != rhs.x || y != rhs.y || z != rhs.z;
		}

		Vector3 operator*(float scaleUnit, const Vector3& rhs){

			return Vector3(scaleUnit * rhs.x, scaleUnit * rhs.y, scaleUnit * rhs.z);
		}

		Vector3 operator*(const Vector3& lhs, float scaleUnit){

			return Vector3(scaleUnit * lhs.x, scaleUnit * lhs.y, scaleUnit * lhs.z);
		}


	}
}