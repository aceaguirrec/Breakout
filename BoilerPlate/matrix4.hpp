#pragma once
#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include <iostream>
#include <vector>
#include "Vector4.hpp"
#include "math_utilities.hpp"

namespace engine
{
	namespace math
	{
	
		struct matrix4
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static matrix4				Origin;

			/* ==========================
			* CONSTRUCTORS
			* ==========================*/
										matrix4();
										matrix4(float, float, float, float,
												float, float, float, float, 
												float, float, float, float, 
												float, float, float, float );
										matrix4(std::vector<float>);
			

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			void						identity(void);
			int *						get_values(void);
			float						get_individual_element(int);
			int *						get_angles(void);
			void						rotate_matrix(float , float);
			void						print_the_matrix(std::ostream &, const matrix4 & );
			float&						get_member( int );
			matrix4						get_translation_matrix(Vector4);
			matrix4						rotate_on_x(float);
			matrix4						rotate_on_y(float);
			matrix4						rotate_on_z(float);
			matrix4						get_transpose(void);
			matrix4						invert_matrix(void);
			Vector4&					translate_matrix(Vector4 translationVector);
			void						ortho_matrix(const float &, const float &, const float &,
													const float &, const float &, const float &);
			void						perspective_matrix(const float &, const float &, const float &);
			void						look_at(vector3 , vector3 );

			/* ==========================
			* OPERATORS
			* ==========================*/

			matrix4&					operator= (matrix4&);
			matrix4&					operator+=(matrix4&);
			matrix4&					operator-=(matrix4&);
			matrix4&					operator*=( matrix4&);
			float&						operator[](const int&);
			matrix4						operator+( matrix4&) const;
			matrix4						operator-( matrix4&) const;
			matrix4						operator*( matrix4&) const;
			

			/* ==========================
			* MEMBERS
			* ==========================*/
		private:
			float						mValues[15];
			
		};
	}
}
#endif // !_VMATRIX4_H_
