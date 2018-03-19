#pragma once
#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include <iostream>
#include <vector>
#include "Vector4.hpp"

namespace Engine
{
	namespace Math
	{
	
		struct matrix4
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static matrix4 Origin;

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
			void	 identity(void);
			int *	 get_values(void);
			matrix4	 get_transpose(void);
			float	 get_individual_element(int);
			int *	 get_angles(void);
			matrix4	 translation_matrix(Vector4 translationVector);
			Vector4& translate(Vector4 translationVector);
			bool invert_matrix(const double member[16], double indexOut[16]);
			void	 rotate_matrix(float , float);
			matrix4	 rotate_on_x(float);
			matrix4	 rotate_on_y(float);
			matrix4	 rotate_on_z(float);
			void print_the_matrix(std::ostream &, const matrix4 & );
			float& get_member( int );
			matrix4 invert_matrix(void);

			/* ==========================
			* OPERATORS
			* ==========================*/

			matrix4& operator= (matrix4&);
			matrix4& operator+=(matrix4&);
			matrix4& operator-=(matrix4&);
			matrix4& operator*=( matrix4&);
			float&	 operator[](const int&);
			matrix4  operator+( matrix4&) const;
			matrix4  operator-( matrix4&) const;
			matrix4  operator*( matrix4&) const;
			

			/* ==========================
			* MEMBERS
			* ==========================*/
		private:
			float mValues[15];
			
		};
	}
}
#endif // !_VMATRIX4_H_
