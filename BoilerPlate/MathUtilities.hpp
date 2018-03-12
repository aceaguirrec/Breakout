#pragma once
#ifndef _MATHUTILITIES_H_
#define _MATHUTILITIES_H_

namespace engine
{
	namespace math
	{
		
		struct math_utilities
		{
			/* ==========================
			* CONSTRUCTORS
			* ==========================*/
			
			math_utilities();

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			float float_to_int(float);
			float float_to_even(float);
			float clamp(float, float, float);
			float degrees_to_radians(float);
			float radians_to_degrees(float);
			float radians_distance(float, float);
			float angular_distance(float, float);
			bool  is_a_power_of_two(int);
			float interpolate(float, float, float);

			/* ==========================
			  MEMBERS
			  ==========================*/

			static float mPi;

			/* ==========================
			* TEMPLATES
			* ==========================*/

			template <class data>
			data get_min(data num1, data num2) {
				if (num1 <= num2) return num1
				else return num2;
			}
			template <class data>
			data get_min(data num1, data num2, data num3) {
				if (num1 <= num2) {
					if (num1 <= num3) return num1;
					else return num3;
				}
				else {
					if (num2 <= num3) return num2;
					else return num3;
				}
			}
			template <class data>
			data get_min(data num1, data num2, data num3, data num4) {
				if (num1 <= num2) {
					if (num3 <= num4) {
						if (num1 <= num3) return num1;
						else return num3;
					}
					else {
						if (num1 <= num4) return num1;
						else return num4;
					}
				}
				else {
					if (num3 <= num4) {
						if (num2 <= num3) return num2;
						else return num3;
					}
					else {
						if (num2 <= num4) return num2;
						else return num4;
					}
				}
			}
			template <class data>
			data get_max(data num1, data num2) {
				if (num1 >= num2) return num1
				else return num2;
			}
			template <class data>
			data get_max(data num1, data num2, data num3) {
				if (num1 >= num2) {
					if (num1 >= num3) return num1;
					else return num3;
				}
				else {
					if (num2 >= num3) return num2;
					else return num3;
				}
			}
			template <class data>
			data get_max(data num1, data num2, data num3, data num4) {
				if (num1 >= num2) {
					if (num3 >= num4) {
						if (num1 >= num3) return num1;
						else return num3;
					}
					else {
						if (num1 >= num4) return num1;
						else return num4;
					}
				}
				else {
					if (num3 >= num4) {
						if (num2 >= num3) return num2;
						else return num3;
					}
					else {
						if (num2 >= num4) return num2;
						else return num4;
					}
				}
			}
		};
	}
}
#endif // !_MATHUTILITIES_H_