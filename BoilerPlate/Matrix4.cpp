#include "Matrix4.hpp"

namespace Engine
{
	namespace math
	{
		matrix4::matrix4() {
		}
<<<<<<< HEAD

		matrix4::matrix4(float member0, float member4, float member8, float member12,
			float member1, float member5, float member9, float member13,
			float member2, float member6, float member10, float member14,
			float member3, float member7, float member11, float member15)
		{
			// line = i columns = j
			mValues[0][0] = member0;
			mValues[1][0] = member1;
			mValues[2][0] = member2;
			mValues[3][0] = member3;
			mValues[0][1] = member4;
			mValues[1][1] = member5;
			mValues[2][1] = member6;
			mValues[3][1] = member7;
			mValues[0][2] = member8;
			mValues[1][2] = member9;
			mValues[2][2] = member10;
			mValues[3][2] = member11;
			mValues[0][3] = member12;
			mValues[1][3] = member13;
			mValues[2][3] = member14;
			mValues[3][3] = member15;
		}
		matrix4::matrix4(std::vector<float> array) { // use pointers
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					//mValues[j][i] = array[j][i];
				}
			}
		}
		void matrix4::identity() {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					if (i == j) mValues[j][i] = 1;
					else mValues[j][i] = 0;
				}
			}
=======
		
		matrix4::matrix4(float member0, float member4, float member8,  float member12,
						 float member1, float member5, float member9,  float member13,
						 float member2, float member6, float member10, float member14,
						 float member3, float member7, float member11, float member15)
		{
			mValues[0]  = member0;
			mValues[1]  = member1;
			mValues[2]  = member2;
			mValues[3]  = member3;
			mValues[4]  = member4;
			mValues[5]  = member5;
			mValues[6]  = member6;
			mValues[7]  = member7;
			mValues[8]  = member8;
			mValues[9]  = member9;
			mValues[10] = member10;
			mValues[11] = member11;
			mValues[12] = member12;
			mValues[13] = member13;
			mValues[14] = member14;
			mValues[15] = member15;
		}
		matrix4::matrix4(std::vector<float> array) { 
			mValues[0] = array[0];
			mValues[1] = array[1];
			mValues[2] = array[2];
			mValues[3] = array[3];
			mValues[4] = array[4];
			mValues[5] = array[5];
			mValues[6] = array[6];
			mValues[7] = array[7];
			mValues[8] = array[8];
			mValues[9] = array[9];
			mValues[10] = array[10];
			mValues[11] = array[11];
			mValues[12] = array[12];
			mValues[13] = array[13];
			mValues[14] = array[14];
			mValues[15] = array[15];
		}
		void matrix4::identity() {
			mValues[0] = 1;
			mValues[1] = 0;
			mValues[2] = 0;
			mValues[3] = 0;
			mValues[5] = 1;
			mValues[6] = 0;
			mValues[7] = 0;
			mValues[8] = 0;
			mValues[9] = 0;
			mValues[10] = 1;
			mValues[11] = 0;
			mValues[12] = 0;
			mValues[13] = 0;
			mValues[14] = 0;
			mValues[15] = 1;
>>>>>>> 9914f330f358c03f2225848152920c9a73440643
		}
		int* matrix4::get_values() {
			static int pointerToValues[15];
			for (int i = 0; i < 15; i++) {
					pointerToValues[i] = mValues[i];
			}
			return pointerToValues;
		}
		matrix4 matrix4::get_transpose() {
			matrix4 newMatrix4 = matrix4();
<<<<<<< HEAD
<<<<<<< HEAD
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					newMatrix4.mValues[i][j] = mValues[j][i];
				}
			}
			return newMatrix4;
		}
		float matrix4::get_individual_element(int indexLine, int indexColumn) {
			return mValues[indexLine][indexColumn];
		}
		int * matrix4::get_angles() {
			float yaw, pitch, roll;
			static int angles[3];
			if (mValues[0][0] == 1.0f)
=======
			mValues[0] = 1;
			mValues[1] = 0;
			mValues[2] = 0;
			mValues[3] = 0;
			mValues[5] = 1;
			mValues[6] = 0;
			mValues[7] = 0;
			mValues[8] = 0;
			mValues[9] = 0;
			mValues[10] = 1;
			mValues[11] = 0;
			mValues[12] = 0;
			mValues[13] = 0;
			mValues[14] = 0;
			mValues[15] = 1;
=======
			newMatrix4[1] = mValues[4];
			newMatrix4[2] = mValues[8];
			newMatrix4[3] = mValues[12];
			newMatrix4[6] = mValues[9];
			newMatrix4[7] = mValues[13];
			newMatrix4[8] = mValues[2];
			newMatrix4[9] = mValues[6];
			newMatrix4[11] = mValues[14];
			newMatrix4[12] = mValues[3];
			newMatrix4[13] = mValues[7];
			newMatrix4[14] = mValues[11];
>>>>>>> a3604fe7838709dc8bbd79aeeac94cb99bb8a59e
			return newMatrix4;
		}
		float matrix4::get_individual_element(int indexLine) {
			return mValues[indexLine];
		}
		int * matrix4::get_angles(){
			float yaw, pitch, roll;
			static int angles[3];
			if ( mValues[0] == 1.0f)
>>>>>>> 9914f330f358c03f2225848152920c9a73440643
			{
				yaw = atan2f(mValues[8], mValues[14]);
				pitch = 0;
				roll = 0;

			}
			else if (mValues[0] == -1.0f)
			{
				yaw = atan2f(mValues[8], mValues[14]);
				pitch = 0;
				roll = 0;
			}
			else
			{

				yaw = atan2(-mValues[2], mValues[0]);
				pitch = asin(mValues[1]);
				roll = atan2(-mValues[9], mValues[5]);
			}
			angles[0] = roll;
			angles[1] = yaw;
			angles[2] = pitch;
			return angles;
		}
		//operators

		matrix4& matrix4::operator=(matrix4& right_hand_side)
		{
			// prevent self assignment
			if (this == &right_hand_side) return *this;

			mValues[0] = right_hand_side[0];
			mValues[1] = right_hand_side[1];
			mValues[2] = right_hand_side[2];
			mValues[3] = right_hand_side[3];
			mValues[4] = right_hand_side[4];
			mValues[5] = right_hand_side[5];
			mValues[6] = right_hand_side[6];
			mValues[7] = right_hand_side[7];
			mValues[8] = right_hand_side[8];
			mValues[9] = right_hand_side[9];
			mValues[10] = right_hand_side[10];
			mValues[11] = right_hand_side[11];
			mValues[12] = right_hand_side[12];
			mValues[13] = right_hand_side[13];
			mValues[14] = right_hand_side[14];
			mValues[15] = right_hand_side[15];
		}
		float& matrix4::get_member(int index) {
			return mValues[index];
		}
		float& matrix4::operator[](const int& member)
		{
			return mValues[member];
		}
		matrix4& matrix4::operator+=( matrix4& right_hand_side)
		{
			mValues[0] += right_hand_side[0];
			mValues[1] += right_hand_side[1];
			mValues[2] += right_hand_side[2];
			mValues[3] += right_hand_side[3];
			mValues[4] += right_hand_side[4];
			mValues[5] += right_hand_side[5];
			mValues[6] += right_hand_side[6];
			mValues[7] += right_hand_side[7];
			mValues[8] += right_hand_side[8];
			mValues[9] += right_hand_side[9];
			mValues[10] += right_hand_side[10];
			mValues[11] += right_hand_side[11];
			mValues[12] += right_hand_side[12];
			mValues[13] += right_hand_side[13];
			mValues[14] += right_hand_side[14];
			mValues[15] += right_hand_side[15];
			return *this;
		}
		matrix4& matrix4::operator-=(matrix4& right_hand_side)
		{
<<<<<<< HEAD
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					for (int k = 0; k < 3; k++) mValues[j][i] +=
<<<<<<< HEAD
						mValues[j][i + k] * right_hand_side.mValues[j][i + k];
=======
						 mValues[j][i + k] * right_hand_side.mValues[j][i + k];
>>>>>>> 9914f330f358c03f2225848152920c9a73440643
				}
			}
=======
			mValues[0] -= right_hand_side[0];
			mValues[1] -= right_hand_side[1];
			mValues[2] -= right_hand_side[2];
			mValues[3] -= right_hand_side[3];
			mValues[4] -= right_hand_side[4];
			mValues[5] -= right_hand_side[5];
			mValues[6] -= right_hand_side[6];
			mValues[7] -= right_hand_side[7];
			mValues[8] -= right_hand_side[8];
			mValues[9] -= right_hand_side[9];
			mValues[10] -= right_hand_side[10];
			mValues[11] -= right_hand_side[11];
			mValues[12] -= right_hand_side[12];
			mValues[13] -= right_hand_side[13];
			mValues[14] -= right_hand_side[14];
			mValues[15] -= right_hand_side[15];
>>>>>>> a3604fe7838709dc8bbd79aeeac94cb99bb8a59e
			return *this;
		}

		/*matrix4& matrix4::operator*=( matrix4& right_hand_side)
		{
			
		}*/
		matrix4 matrix4::operator+( matrix4& right_hand_side) const
		{
			matrix4 newmatrix4 = matrix4();
			newmatrix4[0] = mValues[0] + right_hand_side[0];
			newmatrix4[1] = mValues[1] + right_hand_side[1];
			newmatrix4[2] = mValues[2] + right_hand_side[2];
			newmatrix4[3] = mValues[3] + right_hand_side[3];
			newmatrix4[4] = mValues[4] + right_hand_side[4];
			newmatrix4[5] = mValues[5] + right_hand_side[5];
			newmatrix4[6] = mValues[6] + right_hand_side[6];
			newmatrix4[7] = mValues[7] + right_hand_side[7];
			newmatrix4[8] = mValues[8] + right_hand_side[8];
			newmatrix4[9] = mValues[9] + right_hand_side[9];
			newmatrix4[10] = mValues[10] + right_hand_side[10];
			newmatrix4[11] = mValues[11] + right_hand_side[11];
			newmatrix4[12] = mValues[12] + right_hand_side[12];
			newmatrix4[13] = mValues[13] + right_hand_side[13];
			newmatrix4[14] = mValues[14] + right_hand_side[14];
			newmatrix4[15] = mValues[15] + right_hand_side[15];
			return newmatrix4;
		}

		matrix4 matrix4::operator-( matrix4& right_hand_side) const
		{
			matrix4 newmatrix4 = matrix4();
			newmatrix4[0] = mValues[0] - right_hand_side[0];
			newmatrix4[1] = mValues[1] - right_hand_side[1];
			newmatrix4[2] = mValues[2] - right_hand_side[2];
			newmatrix4[3] = mValues[3] - right_hand_side[3];
			newmatrix4[4] = mValues[4] - right_hand_side[4];
			newmatrix4[5] = mValues[5] - right_hand_side[5];
			newmatrix4[6] = mValues[6] - right_hand_side[6];
			newmatrix4[7] = mValues[7] - right_hand_side[7];
			newmatrix4[8] = mValues[8] - right_hand_side[8];
			newmatrix4[9] = mValues[9] - right_hand_side[9];
			newmatrix4[10] = mValues[10] - right_hand_side[10];
			newmatrix4[11] = mValues[11] - right_hand_side[11];
			newmatrix4[12] = mValues[12] - right_hand_side[12];
			newmatrix4[13] = mValues[13] - right_hand_side[13];
			newmatrix4[14] = mValues[14] - right_hand_side[14];
			newmatrix4[15] = mValues[15] - right_hand_side[15];
			return newmatrix4;
		}
		/*matrix4 matrix4::operator*( matrix4& right_hand_side) const
		{
<<<<<<< HEAD
			matrix4 newMatrix4 = matrix4();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
<<<<<<< HEAD
					for (int k = 0; k < 3; k++) newMatrix4.mValues[j][i]
						+= mValues[j][i + k] * right_hand_side.mValues[j][i + k];
=======
						for (int k = 0; k < 3; k++) newMatrix4.mValues[j][i] 
							+=  mValues[j][i+k] * right_hand_side.mValues[j][i+k];
>>>>>>> 9914f330f358c03f2225848152920c9a73440643
				}
			}
			return newMatrix4;
		}
		void matrix4::print_the_matrix(std::ostream &myOstream, const matrix4 &matrix) {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					myOstream << mValues[j][i] << " ";
				}
				myOstream << "\n";
			}
=======
			
		}*/
		void matrix4::print_the_matrix(std::ostream &myostream, const matrix4 &matrix) {
				myostream << mValues[0] << " ";
				myostream << mValues[4] << " ";
				myostream << mValues[8] << " ";
				myostream << mValues[12] << " ";
				myostream  << "\n";
				myostream << mValues[1] << " ";
				myostream << mValues[5] << " ";
				myostream << mValues[9] << " ";
				myostream << mValues[13] << " ";
				myostream << "\n";
				myostream << mValues[2] << " ";
				myostream << mValues[6] << " ";
				myostream << mValues[10] << " ";
				myostream << mValues[14] << " ";
				myostream  << "\n";
				myostream << mValues[3] << " ";
				myostream << mValues[7] << " ";
				myostream << mValues[11] << " ";
				myostream << mValues[15] << " ";
>>>>>>> a3604fe7838709dc8bbd79aeeac94cb99bb8a59e
		}
				
		matrix4 matrix4::rotate_on_x(float angle)
		{
			matrix4 newmatrix = matrix4();
			newmatrix.mValues[5]   = std::cos(-angle);
			newmatrix.mValues[6]   = -std::sin(-angle);
			newmatrix.mValues[9]   = std::sin(-angle);
			newmatrix.mValues[10]  = std::cos(-angle);
			return newmatrix;
		}

		matrix4 matrix4::rotate_on_y(float angle)
		{
			matrix4 newmatrix = matrix4();
			newmatrix.mValues[0]= std::cos(-angle);
			newmatrix.mValues[2]= std::sin(-angle);
			newmatrix.mValues[8]= -std::sin(-angle);
			newmatrix.mValues[10] = std::cos(-angle);
			return newmatrix;
		}

		matrix4 matrix4::rotate_on_z(float angle)
		{
			matrix4 newmatrix = matrix4();
			newmatrix.mValues[0] = std::cos(-angle);
			newmatrix.mValues[1] = -std::sin(-angle);
			newmatrix.mValues[4] = std::sin(-angle);
			newmatrix.mValues[5] = std::cos(-angle);
			return newmatrix;
		}
		void matrix4::rotate_matrix(float axis, float angle) {
			if (axis == 0) {
				rotate_on_x(angle);
			}
			else if (axis == 1) {
				rotate_on_x(angle);
			}
			else if (axis == 2) {
				rotate_on_z(angle);
			}
<<<<<<< HEAD
<<<<<<< HEAD
		}
		matrix4 matrix4::translate_matrix() {
			matrix4 newMatrix = matrix4();

			return newMatrix;
		}
=======
=======
			else {
				rotate_on_x(angle);
				rotate_on_x(angle);
				rotate_on_z(angle);
			}
>>>>>>> a3604fe7838709dc8bbd79aeeac94cb99bb8a59e
		}
		/*matrix4 matrix4::translate_matrix(){
			
<<<<<<< HEAD
			return newMatrix;
		}
>>>>>>> 9914f330f358c03f2225848152920c9a73440643
		bool matrix4::invert_matrix(const double member[16], double indexOut[16])
		{
			double index[16], determinate;
			int i;

			index[0] = member[5] * member[10] * member[15] -
				member[5] * member[11] * member[14] -
				member[9] * member[6] * member[15] +
				member[9] * member[7] * member[14] +
				member[13] * member[6] * member[11] -
				member[13] * member[7] * member[10];
<<<<<<< HEAD

			index[4] = -member[4] * member[10] * member[15] +
				member[4] * member[11] * member[14] +
				member[8] * member[6] * member[15] -
				member[8] * member[7] * member[14] -
				member[12] * member[6] * member[11] +
				member[12] * member[7] * member[10];

			index[8] = member[4] * member[9] * member[15] -
				member[4] * member[11] * member[13] -
				member[8] * member[5] * member[15] +
				member[8] * member[7] * member[13] +
				member[12] * member[5] * member[11] -
				member[12] * member[7] * member[9];

			index[12] = -member[4] * member[9] * member[14] +
				member[4] * member[10] * member[13] +
				member[8] * member[5] * member[14] -
				member[8] * member[6] * member[13] -
				member[12] * member[5] * member[10] +
				member[12] * member[6] * member[9];

			index[1] = -member[1] * member[10] * member[15] +
				member[1] * member[11] * member[14] +
				member[9] * member[2] * member[15] -
				member[9] * member[3] * member[14] -
				member[13] * member[2] * member[11] +
				member[13] * member[3] * member[10];

			index[5] = member[0] * member[10] * member[15] -
				member[0] * member[11] * member[14] -
				member[8] * member[2] * member[15] +
				member[8] * member[3] * member[14] +
				member[12] * member[2] * member[11] -
				member[12] * member[3] * member[10];

			index[9] = -member[0] * member[9] * member[15] +
				member[0] * member[11] * member[13] +
				member[8] * member[1] * member[15] -
				member[8] * member[3] * member[13] -
				member[12] * member[1] * member[11] +
				member[12] * member[3] * member[9];

			index[13] = member[0] * member[9] * member[14] -
				member[0] * member[10] * member[13] -
				member[8] * member[1] * member[14] +
				member[8] * member[2] * member[13] +
				member[12] * member[1] * member[10] -
				member[12] * member[2] * member[9];

=======

			index[4] = -member[4] * member[10] * member[15] +
				member[4] * member[11] * member[14] +
				member[8] * member[6] * member[15] -
				member[8] * member[7] * member[14] -
				member[12] * member[6] * member[11] +
				member[12] * member[7] * member[10];

			index[8] = member[4] * member[9] * member[15] -
				member[4] * member[11] * member[13] -
				member[8] * member[5] * member[15] +
				member[8] * member[7] * member[13] +
				member[12] * member[5] * member[11] -
				member[12] * member[7] * member[9];

			index[12] = -member[4] * member[9] * member[14] +
				member[4] * member[10] * member[13] +
				member[8] * member[5] * member[14] -
				member[8] * member[6] * member[13] -
				member[12] * member[5] * member[10] +
				member[12] * member[6] * member[9];

			index[1] = -member[1] * member[10] * member[15] +
				member[1] * member[11] * member[14] +
				member[9] * member[2] * member[15] -
				member[9] * member[3] * member[14] -
				member[13] * member[2] * member[11] +
				member[13] * member[3] * member[10];

			index[5] = member[0] * member[10] * member[15] -
				member[0] * member[11] * member[14] -
				member[8] * member[2] * member[15] +
				member[8] * member[3] * member[14] +
				member[12] * member[2] * member[11] -
				member[12] * member[3] * member[10];

			index[9] = -member[0] * member[9] * member[15] +
				member[0] * member[11] * member[13] +
				member[8] * member[1] * member[15] -
				member[8] * member[3] * member[13] -
				member[12] * member[1] * member[11] +
				member[12] * member[3] * member[9];

			index[13] = member[0] * member[9] * member[14] -
				member[0] * member[10] * member[13] -
				member[8] * member[1] * member[14] +
				member[8] * member[2] * member[13] +
				member[12] * member[1] * member[10] -
				member[12] * member[2] * member[9];

>>>>>>> 9914f330f358c03f2225848152920c9a73440643
			index[2] = member[1] * member[6] * member[15] -
				member[1] * member[7] * member[14] -
				member[5] * member[2] * member[15] +
				member[5] * member[3] * member[14] +
				member[13] * member[2] * member[7] -
				member[13] * member[3] * member[6];

			index[6] = -member[0] * member[6] * member[15] +
				member[0] * member[7] * member[14] +
				member[4] * member[2] * member[15] -
				member[4] * member[3] * member[14] -
				member[12] * member[2] * member[7] +
				member[12] * member[3] * member[6];

			index[10] = member[0] * member[5] * member[15] -
				member[0] * member[7] * member[13] -
				member[4] * member[1] * member[15] +
				member[4] * member[3] * member[13] +
				member[12] * member[1] * member[7] -
				member[12] * member[3] * member[5];

			index[14] = -member[0] * member[5] * member[14] +
				member[0] * member[6] * member[13] +
				member[4] * member[1] * member[14] -
				member[4] * member[2] * member[13] -
				member[12] * member[1] * member[6] +
				member[12] * member[2] * member[5];

			index[3] = -member[1] * member[6] * member[11] +
				member[1] * member[7] * member[10] +
				member[5] * member[2] * member[11] -
				member[5] * member[3] * member[10] -
				member[9] * member[2] * member[7] +
				member[9] * member[3] * member[6];

			index[7] = member[0] * member[6] * member[11] -
				member[0] * member[7] * member[10] -
				member[4] * member[2] * member[11] +
				member[4] * member[3] * member[10] +
				member[8] * member[2] * member[7] -
				member[8] * member[3] * member[6];

			index[11] = -member[0] * member[5] * member[11] +
				member[0] * member[7] * member[9] +
				member[4] * member[1] * member[11] -
				member[4] * member[3] * member[9] -
				member[8] * member[1] * member[7] +
				member[8] * member[3] * member[5];

			index[15] = member[0] * member[5] * member[10] -
				member[0] * member[6] * member[9] -
				member[4] * member[1] * member[10] +
				member[4] * member[2] * member[9] +
				member[8] * member[1] * member[6] -
				member[8] * member[2] * member[5];

			determinate = member[0] * index[0] + member[1] * index[4] + member[2] * index[8] + member[3] * index[12];
=======
		}*/
		matrix4 matrix4::invert_matrix()
		{
			matrix4 invertMatrix = matrix4();
			double determinate;

			invertMatrix[0] = mValues[5] * mValues[10] * mValues[15] -
				mValues[5] * mValues[11] * mValues[14] -
				mValues[9] * mValues[6] * mValues[15] +
				mValues[9] * mValues[7] * mValues[14] +
				mValues[13] * mValues[6] * mValues[11] -
				mValues[13] * mValues[7] * mValues[10];

			invertMatrix[4] = -mValues[4] * mValues[10] * mValues[15] +
				mValues[4] * mValues[11] * mValues[14] +
				mValues[8] * mValues[6] * mValues[15] -
				mValues[8] * mValues[7] * mValues[14] -
				mValues[12] * mValues[6] * mValues[11] +
				mValues[12] * mValues[7] * mValues[10];

			invertMatrix[8] = mValues[4] * mValues[9] * mValues[15] -
				mValues[4] * mValues[11] * mValues[13] -
				mValues[8] * mValues[5] * mValues[15] +
				mValues[8] * mValues[7] * mValues[13] +
				mValues[12] * mValues[5] * mValues[11] -
				mValues[12] * mValues[7] * mValues[9];

			invertMatrix[12] = -mValues[4] * mValues[9] * mValues[14] +
				mValues[4] * mValues[10] * mValues[13] +
				mValues[8] * mValues[5] * mValues[14] -
				mValues[8] * mValues[6] * mValues[13] -
				mValues[12] * mValues[5] * mValues[10] +
				mValues[12] * mValues[6] * mValues[9];

			invertMatrix[1] = -mValues[1] * mValues[10] * mValues[15] +
				mValues[1] * mValues[11] * mValues[14] +
				mValues[9] * mValues[2] * mValues[15] -
				mValues[9] * mValues[3] * mValues[14] -
				mValues[13] * mValues[2] * mValues[11] +
				mValues[13] * mValues[3] * mValues[10];

			invertMatrix[5] = mValues[0] * mValues[10] * mValues[15] -
				mValues[0] * mValues[11] * mValues[14] -
				mValues[8] * mValues[2] * mValues[15] +
				mValues[8] * mValues[3] * mValues[14] +
				mValues[12] * mValues[2] * mValues[11] -
				mValues[12] * mValues[3] * mValues[10];

			invertMatrix[9] = -mValues[0] * mValues[9] * mValues[15] +
				mValues[0] * mValues[11] * mValues[13] +
				mValues[8] * mValues[1] * mValues[15] -
				mValues[8] * mValues[3] * mValues[13] -
				mValues[12] * mValues[1] * mValues[11] +
				mValues[12] * mValues[3] * mValues[9];

			invertMatrix[13] = mValues[0] * mValues[9] * mValues[14] -
				mValues[0] * mValues[10] * mValues[13] -
				mValues[8] * mValues[1] * mValues[14] +
				mValues[8] * mValues[2] * mValues[13] +
				mValues[12] * mValues[1] * mValues[10] -
				mValues[12] * mValues[2] * mValues[9];

			invertMatrix[2] = mValues[1] * mValues[6] * mValues[15] -
				mValues[1] * mValues[7] * mValues[14] -
				mValues[5] * mValues[2] * mValues[15] +
				mValues[5] * mValues[3] * mValues[14] +
				mValues[13] * mValues[2] * mValues[7] -
				mValues[13] * mValues[3] * mValues[6];

			invertMatrix[6] = -mValues[0] * mValues[6] * mValues[15] +
				mValues[0] * mValues[7] * mValues[14] +
				mValues[4] * mValues[2] * mValues[15] -
				mValues[4] * mValues[3] * mValues[14] -
				mValues[12] * mValues[2] * mValues[7] +
				mValues[12] * mValues[3] * mValues[6];

			invertMatrix[10] = mValues[0] * mValues[5] * mValues[15] -
				mValues[0] * mValues[7] * mValues[13] -
				mValues[4] * mValues[1] * mValues[15] +
				mValues[4] * mValues[3] * mValues[13] +
				mValues[12] * mValues[1] * mValues[7] -
				mValues[12] * mValues[3] * mValues[5];

			invertMatrix[14] = -mValues[0] * mValues[5] * mValues[14] +
				mValues[0] * mValues[6] * mValues[13] +
				mValues[4] * mValues[1] * mValues[14] -
				mValues[4] * mValues[2] * mValues[13] -
				mValues[12] * mValues[1] * mValues[6] +
				mValues[12] * mValues[2] * mValues[5];

			invertMatrix[3] = -mValues[1] * mValues[6] * mValues[11] +
				mValues[1] * mValues[7] * mValues[10] +
				mValues[5] * mValues[2] * mValues[11] -
				mValues[5] * mValues[3] * mValues[10] -
				mValues[9] * mValues[2] * mValues[7] +
				mValues[9] * mValues[3] * mValues[6];

			invertMatrix[7] = mValues[0] * mValues[6] * mValues[11] -
				mValues[0] * mValues[7] * mValues[10] -
				mValues[4] * mValues[2] * mValues[11] +
				mValues[4] * mValues[3] * mValues[10] +
				mValues[8] * mValues[2] * mValues[7] -
				mValues[8] * mValues[3] * mValues[6];

			invertMatrix[11] = -mValues[0] * mValues[5] * mValues[11] +
				mValues[0] * mValues[7] * mValues[9] +
				mValues[4] * mValues[1] * mValues[11] -
				mValues[4] * mValues[3] * mValues[9] -
				mValues[8] * mValues[1] * mValues[7] +
				mValues[8] * mValues[3] * mValues[5];

			invertMatrix[15] = mValues[0] * mValues[5] * mValues[10] -
				mValues[0] * mValues[6] * mValues[9] -
				mValues[4] * mValues[1] * mValues[10] +
				mValues[4] * mValues[2] * mValues[9] +
				mValues[8] * mValues[1] * mValues[6] -
				mValues[8] * mValues[2] * mValues[5];

			determinate = mValues[0] * invertMatrix[0] + mValues[1] * invertMatrix[4] 
				+ mValues[2] * invertMatrix[8] + mValues[3] * invertMatrix[12];
>>>>>>> a3604fe7838709dc8bbd79aeeac94cb99bb8a59e

			if (determinate == 0)
				//return false;

			determinate = 1.0 / determinate;

			
			invertMatrix[0]  = invertMatrix[0] * determinate;
			invertMatrix[1]  = invertMatrix[1] * determinate;
			invertMatrix[2]  = invertMatrix[2] * determinate;
			invertMatrix[3]  = invertMatrix[3] * determinate;
			invertMatrix[4]  = invertMatrix[4] * determinate;
			invertMatrix[5]  = invertMatrix[5] * determinate;
			invertMatrix[6]  = invertMatrix[6] * determinate;
			invertMatrix[7]  = invertMatrix[7] * determinate;
			invertMatrix[8]  = invertMatrix[8] * determinate;
			invertMatrix[9]  = invertMatrix[9] * determinate;
			invertMatrix[10] = invertMatrix[10] * determinate;
			invertMatrix[11] = invertMatrix[11] * determinate;
			invertMatrix[12] = invertMatrix[12] * determinate;
			invertMatrix[13] = invertMatrix[13] * determinate;
			invertMatrix[14] = invertMatrix[14] * determinate;
			invertMatrix[15] = invertMatrix[15] * determinate;

			return invertMatrix;

		}

	}
}