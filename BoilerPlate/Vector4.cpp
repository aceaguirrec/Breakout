#include "Vector3.hpp"
#include "Vector2.hpp"
#include "Vector4.hpp"
<<<<<<< HEAD
#include "Vector2.hpp"
#include "Vector3.hpp"
=======
>>>>>>> master

#include <cmath>

namespace Engine
{
	namespace Math
	{
		Vector4 Vector4::Origin = Vector4();

		Vector4::Vector4()
			: x(0.0f)
			, y(0.0f)
			, z(0.0f)
			, w(0.0f)
			, length(0.0f)
		{}

		Vector4::Vector4(float _x, float _y, float _z, float _w)
			: x(_x)
			, y(_y)
			, z(_z)
			, w(_w)
			, length(0.0f)
		{
			// Calculate Length
			Length();
		}

		Vector4::Vector4(float _uniform)
			: x(_uniform)
			, y(_uniform)
			, z(_uniform)
			, w(_uniform)
			, length(0.0f)
		{
			// Calculate Length
			Length();
		}

		Vector4::Vector4(const Vector2& vec2)
			: x(vec2.x)
			, y(vec2.y)
			, z(0.0f)
			, w(0.0f)
			, length(0.0f)
		{
			// Calculate Length
			Length();
		}

		Vector4::Vector4(const Vector3& vec3)
			: x(vec3.x)
			, y(vec3.y)
			, z(vec3.z)
			, w(0.0f)
			, length(0.0f)
		{
			// Calculate Length
			Length();
		}

<<<<<<< HEAD
		float Vector4::Length() const{
=======
		float Vector4::Length() const {
>>>>>>> master

			return std::sqrt(x * x + y * y + z * z);
		}

<<<<<<< HEAD
		float Vector4::SquaredLength() const{
=======
		float Vector4::SquaredLength() const {
>>>>>>> master

			return x * x + y * y + z * z;
		}

<<<<<<< HEAD
		float Vector4::Normalize(){
=======
		float Vector4::Normalize() {
>>>>>>> master

			// Calculate length
			Length();

			float inverseScale = 1.0f / length;
			x *= inverseScale;
			y *= inverseScale;
			z *= inverseScale;

			return length;
		}

<<<<<<< HEAD
		Vector4& Vector4::operator=(const Vector4& rhs){
=======
		Vector4& Vector4::operator=(const Vector4& rhs) {
>>>>>>> master

			// Prevent self assignment
			if (this == &rhs) return *this;

			x = rhs.x;
			y = rhs.y;
			z = rhs.z;

			return *this;
		}

<<<<<<< HEAD
		Vector4& Vector4::operator+=(const Vector4& rhs){
=======
		Vector4& Vector4::operator+=(const Vector4& rhs) {
>>>>>>> master

			x = x + rhs.x;
			y = y + rhs.y;
			z = z + rhs.z;

			return *this;
		}

<<<<<<< HEAD
		Vector4& Vector4::operator-=(const Vector4& rhs){
=======
		Vector4& Vector4::operator-=(const Vector4& rhs) {
>>>>>>> master

			x = x - rhs.x;
			y = y - rhs.y;
			z = z - rhs.z;

			return *this;
		}

<<<<<<< HEAD
		Vector4& Vector4::operator*=(const Vector4& rhs){
=======
		Vector4& Vector4::operator*=(const Vector4& rhs) {
>>>>>>> master

			x = x * rhs.x;
			y = y * rhs.y;
			z = z * rhs.z;

			return *this;
		}

<<<<<<< HEAD
		Vector4& Vector4::operator/=(const Vector4& rhs){
=======
		Vector4& Vector4::operator/=(const Vector4& rhs) {
>>>>>>> master

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			x = x / rhs.x;
			y = y / rhs.y;
			z = z / rhs.z;

			return *this;
		}


<<<<<<< HEAD
		Vector4 Vector4::operator+(const Vector4& rhs) const{
=======
		Vector4 Vector4::operator+(const Vector4& rhs) const {
>>>>>>> master

			return Vector4(
				x + rhs.x,
				y + rhs.y,
				z + rhs.z,
				w + rhs.w);
		}

<<<<<<< HEAD
		Vector4 Vector4::operator-(const Vector4& rhs) const{
=======
		Vector4 Vector4::operator-(const Vector4& rhs) const {
>>>>>>> master

			return Vector4(
				x - rhs.x,
				y - rhs.y,
				z - rhs.z,
				w - rhs.w);
		}

<<<<<<< HEAD
		Vector4 Vector4::operator*(const Vector4& rhs) const{
=======
		Vector4 Vector4::operator*(const Vector4& rhs) const {
>>>>>>> master

			return Vector4(
				x * rhs.x,
				y * rhs.y,
				z * rhs.z,
				w * rhs.w);
		}

<<<<<<< HEAD
		Vector4 Vector4::operator/(const Vector4& rhs) const{
=======
		Vector4 Vector4::operator/(const Vector4& rhs) const {
>>>>>>> master

			if (rhs.x == 0) throw "Division by zero is not defined!";
			if (rhs.y == 0) throw "Division by zero is not defined!";
			if (rhs.z == 0) throw "Division by zero is not defined!";

			return Vector4(
				x / rhs.x,
				y / rhs.y,
				z / rhs.z,
				w / rhs.w);
		}

<<<<<<< HEAD
		bool Vector4::operator==(const Vector4& rhs) const{
=======
		bool Vector4::operator==(const Vector4& rhs) const {
>>>>>>> master

			return
				x == rhs.x &&
				y == rhs.y &&
				z == rhs.z &&
				w == rhs.w;
		}

<<<<<<< HEAD
		bool Vector4::operator!=(const Vector4& rhs) const{
=======
		bool Vector4::operator!=(const Vector4& rhs) const {
>>>>>>> master

			return
				x != rhs.x ||
				y != rhs.y ||
				z != rhs.z ||
				w != rhs.w;
		}

<<<<<<< HEAD
		Vector4 operator*(float scaleUnit, const Vector4& rhs){
=======
		Vector4 operator*(float scaleUnit, const Vector4& rhs) {
>>>>>>> master

			return Vector4(
				scaleUnit * rhs.x,
				scaleUnit * rhs.y,
				scaleUnit * rhs.z,
				scaleUnit * rhs.w);
		}

<<<<<<< HEAD
		Vector4 operator*(const Vector4& lhs, float scaleUnit){
=======
		Vector4 operator*(const Vector4& lhs, float scaleUnit) {
>>>>>>> master

			return Vector4(
				scaleUnit * lhs.x,
				scaleUnit * lhs.y,
				scaleUnit * lhs.z,
				scaleUnit * lhs.w);
		}
	}
}
