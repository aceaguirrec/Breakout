#pragma once
#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include <vector>
#include <iostream>

namespace Engine
{
	namespace math
	{
<<<<<<< HEAD

=======
	
>>>>>>> 9914f330f358c03f2225848152920c9a73440643
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
<<<<<<< HEAD
				float, float, float, float,
				float, float, float, float,
				float, float, float, float);
			matrix4(std::vector<float>);

=======
					float, float, float, float, 
					float, float, float, float, 
					float, float, float, float );
			matrix4(std::vector<float>);
			
>>>>>>> 9914f330f358c03f2225848152920c9a73440643

			/* ==========================
			* PUBLIC FUNCTIONS
			* ==========================*/
			void	 identity(void);
			int *	 get_values(void);
			matrix4	 get_transpose(void);
<<<<<<< HEAD
			float	 get_individual_element(int, int);
			int *	 get_angles(void);
			matrix4	 translate_matrix(void);
			bool invert_matrix(const double member[16], double indexOut[16]);
			void	 rotate_matrix(float, float);
			matrix4	 rotate_on_x(float);
			matrix4	 rotate_on_y(float);
			matrix4	 rotate_on_z(float);
			void print_the_matrix(std::ostream &, const matrix4 &);
=======
			float	 get_individual_element(int);
			int *	 get_angles(void);
			matrix4	 translate_matrix(void);
			bool invert_matrix(const double member[16], double indexOut[16]);
			void	 rotate_matrix(float , float);
			matrix4	 rotate_on_x(float);
			matrix4	 rotate_on_y(float);
			matrix4	 rotate_on_z(float);
			void print_the_matrix(std::ostream &, const matrix4 & );
<<<<<<< HEAD
>>>>>>> 9914f330f358c03f2225848152920c9a73440643
=======
			float& get_member( int );
			matrix4 invert_matrix(void);
>>>>>>> a3604fe7838709dc8bbd79aeeac94cb99bb8a59e

			/* ==========================
			* OPERATORS
			* ==========================*/

<<<<<<< HEAD
			matrix4& operator= (const matrix4&);
			matrix4& operator+=(const matrix4&);
			matrix4& operator-=(const matrix4&);
			matrix4& operator*=(const matrix4&);
			matrix4  operator+(const matrix4&) const;
			matrix4  operator-(const matrix4&) const;
			matrix4  operator*(const matrix4&) const;
<<<<<<< HEAD

=======
=======
			matrix4& operator= (matrix4&);
			matrix4& operator+=(matrix4&);
			matrix4& operator-=(matrix4&);
			matrix4& operator*=( matrix4&);
			float&	 operator[](const int&);
			matrix4  operator+( matrix4&) const;
			matrix4  operator-( matrix4&) const;
			matrix4  operator*( matrix4&) const;
>>>>>>> a3604fe7838709dc8bbd79aeeac94cb99bb8a59e
			
>>>>>>> 9914f330f358c03f2225848152920c9a73440643

			/* ==========================
			* MEMBERS
			* ==========================*/
<<<<<<< HEAD
			//private:
			float mValues[4][4];
=======
		private:
			float mValues[15];
			
>>>>>>> 9914f330f358c03f2225848152920c9a73440643
		};
	}
}
#endif // !_VMATRIX4_H_
