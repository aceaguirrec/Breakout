#include "Matrix4.hpp"

namespace engine
{
	namespace math
	{
		matrix4::matrix4() {
		}

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
		}
		int* matrix4::get_values() {
			static int pointerToValues[15];
			int counter = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					pointerToValues[counter] = mValues[j][i];
					counter++;
				}
			}
			return pointerToValues;
		}
		matrix4 matrix4::get_transpose() {
			matrix4 newMatrix4 = matrix4();
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
			{
				yaw = atan2f(mValues[1][3], mValues[3][4]);
				pitch = 0;
				roll = 0;

			}
			else if (mValues[0][0] == -1.0f)
			{
				yaw = atan2f(mValues[1][3], mValues[3][4]);
				pitch = 0;
				roll = 0;
			}
			else
			{

				yaw = atan2(-mValues[3][1], mValues[1][1]);
				pitch = asin(mValues[2][1]);
				roll = atan2(-mValues[2][3], mValues[2][2]);
			}
			angles[0] = roll;
			angles[1] = yaw;
			angles[2] = pitch;
			return angles;
		}
		//operators

		matrix4& matrix4::operator=(const matrix4& right_hand_side)
		{
			// Prevent self assignment
			if (this == &right_hand_side) return *this;

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					mValues[j][i] = right_hand_side.mValues[j][i];
				}
			}
			return *this;
		}

		matrix4& matrix4::operator+=(const matrix4& right_hand_side)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					mValues[j][i] += right_hand_side.mValues[j][i];
				}
			}

			return *this;
		}

		matrix4& matrix4::operator-=(const matrix4& right_hand_side)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					mValues[j][i] -= right_hand_side.mValues[j][i];
				}
			}
			return *this;
		}

		matrix4& matrix4::operator*=(const matrix4& right_hand_side)
		{
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					for (int k = 0; k < 3; k++) mValues[j][i] +=
						mValues[j][i + k] * right_hand_side.mValues[j][i + k];
				}
			}
			return *this;
		}

		matrix4 matrix4::operator+(const matrix4& right_hand_side) const
		{
			matrix4 newMatrix4 = matrix4();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					newMatrix4.mValues[j][i] = mValues[j][i] + right_hand_side.mValues[j][i];
				}
			}
			return newMatrix4;
		}

		matrix4 matrix4::operator-(const matrix4& right_hand_side) const
		{
			matrix4 newMatrix4 = matrix4();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					newMatrix4.mValues[j][i] = mValues[j][i] - right_hand_side.mValues[j][i];
				}
			}
			return newMatrix4;
		}
		matrix4 matrix4::operator*(const matrix4& right_hand_side) const
		{
			matrix4 newMatrix4 = matrix4();
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; i++) {
					for (int k = 0; k < 3; k++) newMatrix4.mValues[j][i]
						+= mValues[j][i + k] * right_hand_side.mValues[j][i + k];
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
		}
		matrix4 matrix4::rotate_on_x(float angle)
		{
			matrix4 newMatrix = matrix4();
			newMatrix.mValues[0][1] = std::cos(-angle);
			newMatrix.mValues[0][1] = -std::sin(-angle);
			newMatrix.mValues[2][3] = std::sin(-angle);
			newMatrix.mValues[3][3] = std::cos(-angle);
			return newMatrix;
		}

		matrix4 matrix4::rotate_on_y(float angle)
		{
			matrix4 newMatrix = matrix4();
			newMatrix.mValues[0][0] = std::cos(-angle);
			newMatrix.mValues[3][0] = std::sin(-angle);
			newMatrix.mValues[0][2] = -std::sin(-angle);
			newMatrix.mValues[3][3] = std::cos(-angle);
			return newMatrix;
		}

		matrix4 matrix4::rotate_on_z(float angle)
		{
			matrix4 newMatrix = matrix4();
			newMatrix.mValues[0][0] = std::cos(-angle);
			newMatrix.mValues[1][0] = -std::sin(-angle);
			newMatrix.mValues[1][1] = std::sin(-angle);
			newMatrix.mValues[2][1] = std::cos(-angle);
			return newMatrix;
		}
		void matrix4::rotate_matrix(float axis, float angle) {
			if (axis == 0) {
				rotate_on_x(angle);
			}
			else if (axis == 1) {
				rotate_on_y(angle);
			}
			else if (axis == 2) {
				rotate_on_z(angle);
			}
		}
		matrix4 matrix4::translate_matrix() {
			matrix4 newMatrix = matrix4();

			return newMatrix;
		}
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

			if (determinate == 0)
				return false;

			determinate = 1.0 / determinate;

			for (i = 0; i < 16; i++)
				indexOut[i] = index[i] * determinate;

			return true;
		}

	}
}