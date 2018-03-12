#pragma once
#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include <vector>

namespace Engine
{
	namespace Math
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
			Matrix4(float[]);
			

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			float	 identity(void);
			float*	 get_values(void);
			float	 get_transpose(void);
			float&	 get_individual_element(void);
			float	 get_angles(void);
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