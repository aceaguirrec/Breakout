#pragma once
#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include <iostream>
#include <vector>
#include "vector_4.hpp"

namespace engine
{
	namespace math
	{
	
		struct matrix_4
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static matrix_4 Origin;

			/* ==========================
			* CONSTRUCTORS
			* ==========================*/
			matrix_4();
			matrix_4(float, float, float, float,
					float, float, float, float, 
					float, float, float, float, 
					float, float, float, float );
			matrix_4(std::vector<float>);
			

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			void	 identity(void);
			int *	 get_values(void);
			matrix_4	 get_transpose(void);
			float	 get_individual_element(int);
			int *	 get_angles(void);
			matrix_4	 get_translation_matrix(vector_4 translationVector);
			vector_4& translate_matrix(vector_4 translationVector);
			bool invert_matrix(const double member[16], double indexOut[16]);
			void	 rotate_matrix(float , float);
			matrix_4	 rotate_on_x(float);
			matrix_4	 rotate_on_y(float);
			matrix_4	 rotate_on_z(float);
			void print_the_matrix(std::ostream &, const matrix_4 & );
			float& get_member( int );
			matrix_4 invert_matrix(void);

			/* ==========================
			* OPERATORS
			* ==========================*/

			matrix_4& operator= (matrix_4&);
			matrix_4& operator+=(matrix_4&);
			matrix_4& operator-=(matrix_4&);
			matrix_4& operator*=( matrix_4&);
			float&	 operator[](const int&);
			matrix_4  operator+( matrix_4&) const;
			matrix_4  operator-( matrix_4&) const;
			matrix_4  operator*( matrix_4&) const;
			

			/* ==========================
			* MEMBERS
			* ==========================*/
		private:
			float mValues[15];
			
		};
	}
}
#endif // !_VMATRIX4_H_
