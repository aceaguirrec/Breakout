#include "MathUtilities.hpp"
#include "Math.h"
using namespace std;

namespace Engine
{
	namespace Math
	{
		math_utilities::math_utilities() {
		}
		float math_utilities::mPi = (float)(3.141592);

		float math_utilities::float_to_int(float x) {
			float y = 0;
			y = (float)(round(x));
			return y;
		}
		float math_utilities::float_to_even(float x) {
			float y = 0;
			y = (float)(round(x));
			if (y - 2 == 1) y += 1;
			return y;
		}
		float math_utilities::clamp(float num, float min, float max) {
			return (num / min) * max;
		}

		float math_utilities::degrees_to_radians(float angle) {
			return (float)(angle * 0.01745);
		}

		float math_utilities::radians_to_degrees(float radian) {
			float x = (float)(radian * 57.295779513);
			x = (float)(round(x));
			return x;
		}
		float math_utilities::radians_distance(float radianA, float radianB) {
			radianB -= radianA;
			return radianB;
		}
		float math_utilities::angular_distance(float angleA, float angleB) {
			angleB -= angleA;
			return angleB;
		}

		bool math_utilities::is_a_power_of_two(int num) {
			if (num % 2 == 1) return false;
			int n = num;
			for (int i = 0; i < n; i++) {
				if (num == 2) return true;
				num = num / 2;
				if (num % 2 == 1) {
					return false;
				}
			}
			return num;
		}
		float math_utilities::interpolate(float start, float end, float target) {
			float res = 0;
			res = target * (end - start) + start;
			return end;
		}
	}
}