#pragma once

#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include <vector>

namespace engine
{
	namespace math
	{
	
		struct Matrix4
		{
			/* ==========================
			* STATIC
			* ==========================*/
			static Matrix4 Origin;

			/* ==========================
			* CONSTRUCTORS
			* ==========================*/
			Matrix4();
			Matrix4(float, float, float, float,
					float, float, float, float, 
					float, float, float, float, 
					float, float, float, float );
			Matrix4(std::vector<float>);
			

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			void	 identity(void);
			int *	 get_values(void);
			Matrix4	 get_transpose(void);
			float	 get_individual_element(int, int);
			int *	 get_angles(void);
			void	 translate_matrix(void);
			void	 rotate_matrix(float , float);
			void	 rotate_on_x(float);
			void	 rotate_on_y(float);
			void	 rotate_on_z(float);
			void	 invert_matrix(void);
			void	 transform(void);

			/* ==========================
			* OPERATORS
			* ==========================*/

			Matrix4& operator= (const Matrix4&);
			Matrix4& operator+=(const Matrix4&);
			Matrix4& operator-=(const Matrix4&);
			Matrix4& operator*=(const Matrix4&);
			Matrix4& operator/=(const Matrix4&);
			Matrix4  operator+(const Matrix4&) const;
			Matrix4  operator-(const Matrix4&) const;
			Matrix4  operator*(const Matrix4&) const;
			Matrix4  operator/(const Matrix4&) const;

			/* ==========================
			* MEMBERS
			* ==========================*/
		private:
			float mValues[4][4];
		};
	}
}
#endif // !_VMATRIX4_H_