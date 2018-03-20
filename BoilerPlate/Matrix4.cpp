#include "Matrix4.hpp"

namespace Engine 
{
	namespace Math 
	{
		matrix4::matrix4() {}
		
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
			mValues[4] = 0;
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

			return newMatrix4;
		}


		float matrix4::get_individual_element(int indexLine) {

			return mValues[indexLine];
		}


		int * matrix4::get_angles(){

			float yaw, pitch, roll;
			static int angles[3];

			if ( mValues[0] == 1.0f){

				yaw = atan2f(mValues[8], mValues[14]);
				pitch = 0;
				roll = 0;

			}

			else if (mValues[0] == -1.0f){

				yaw = atan2f(mValues[8], mValues[14]);
				pitch = 0;
				roll = 0;
			} 

			else{

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

		matrix4& matrix4::operator=(matrix4& right_hand_side){

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


		float& matrix4::operator[](const int& member){

			return mValues[member];
		}


		matrix4& matrix4::operator+=( matrix4& right_hand_side){

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


		matrix4& matrix4::operator-=(matrix4& right_hand_side){

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

			return *this;
		}

		matrix4& matrix4::operator*=( matrix4& right_hand_side){

			//First Position
			mValues[0] = mValues[0] * right_hand_side.mValues[0] +
				mValues[4] * right_hand_side.mValues[1] +
				mValues[8] * right_hand_side.mValues[2] +
				mValues[12] * right_hand_side.mValues[3];

			//Second Position
			mValues[1] = mValues[1] * right_hand_side.mValues[0] +
				mValues[5] * right_hand_side.mValues[1] +
				mValues[9] * right_hand_side.mValues[2] +
				mValues[13] * right_hand_side.mValues[3];

			//Third Position
			mValues[2] = mValues[2] * right_hand_side.mValues[0] +
				mValues[6] * right_hand_side.mValues[1] +
				mValues[10] * right_hand_side.mValues[2] +
				mValues[14] * right_hand_side.mValues[3];

			//Fourth Position
			mValues[3] = mValues[3] * right_hand_side.mValues[0] +
				mValues[7] * right_hand_side.mValues[1] +
				mValues[11] * right_hand_side.mValues[2] +
				mValues[15] * right_hand_side.mValues[3];

			//Fifth Position
			mValues[4] = mValues[0] * right_hand_side.mValues[4] +
				mValues[4] * right_hand_side.mValues[5] +
				mValues[8] * right_hand_side.mValues[6] +
				mValues[12] * right_hand_side.mValues[7];

			//Sixth Position
			mValues[5] = mValues[1] * right_hand_side.mValues[4] +
				mValues[5] * right_hand_side.mValues[5] +
				mValues[9] * right_hand_side.mValues[6] +
				mValues[13] * right_hand_side.mValues[7];

			//Seventh Position
			mValues[6] = mValues[2] * right_hand_side.mValues[4] +
				mValues[6] * right_hand_side.mValues[5] +
				mValues[10] * right_hand_side.mValues[6] +
				mValues[14] * right_hand_side.mValues[7];

			//Eighth Position
			mValues[7] = mValues[3] * right_hand_side.mValues[4] +
				mValues[7] * right_hand_side.mValues[5] +
				mValues[11] * right_hand_side.mValues[6] +
				mValues[15] * right_hand_side.mValues[7];

			//Ninth Position
			mValues[8] = mValues[0] * right_hand_side.mValues[8] +
				mValues[4] * right_hand_side.mValues[9] +
				mValues[8] * right_hand_side.mValues[10] +
				mValues[12] * right_hand_side.mValues[11];

			//Tenth Position
			mValues[9] = mValues[1] * right_hand_side.mValues[8] +
				mValues[5] * right_hand_side.mValues[9] +
				mValues[9] * right_hand_side.mValues[10] +
				mValues[13] * right_hand_side.mValues[11];

			//Eleventh Position
			mValues[10] = mValues[2] * right_hand_side.mValues[8] +
				mValues[6] * right_hand_side.mValues[9] +
				mValues[10] * right_hand_side.mValues[10] +
				mValues[14] * right_hand_side.mValues[11];

			//Twelfth Position
			mValues[11] = mValues[3] * right_hand_side.mValues[8] +
				mValues[7] * right_hand_side.mValues[9] +
				mValues[11] * right_hand_side.mValues[10] +
				mValues[15] * right_hand_side.mValues[11];

			//Thirteenth Position
			mValues[12] = mValues[0] * right_hand_side.mValues[12] +
				mValues[4] * right_hand_side.mValues[13] +
				mValues[8] * right_hand_side.mValues[14] +
				mValues[12] * right_hand_side.mValues[15];

			//Fourteenth Position
			mValues[13] = mValues[1] * right_hand_side.mValues[12] +
				mValues[5] * right_hand_side.mValues[13] +
				mValues[9] * right_hand_side.mValues[14] +
				mValues[13] * right_hand_side.mValues[15];

			//Fifteenth Position
			mValues[14] = mValues[2] * right_hand_side.mValues[12] +
				mValues[6] * right_hand_side.mValues[13] +
				mValues[10] * right_hand_side.mValues[14] +
				mValues[14] * right_hand_side.mValues[15];

			//Sixteenth Position
			mValues[15] = mValues[3] * right_hand_side.mValues[12] +
				mValues[7] * right_hand_side.mValues[13] +
				mValues[11] * right_hand_side.mValues[14] +
				mValues[15] * right_hand_side.mValues[15];
			
			return *this;
			
		}


		matrix4 matrix4::operator+( matrix4& right_hand_side) const{

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


		matrix4 matrix4::operator-( matrix4& right_hand_side) const{

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


		matrix4 matrix4::operator*( matrix4& right_hand_side) const{

			matrix4 newMatrix4 = matrix4();
			//First Position
			newMatrix4.mValues[0] = mValues[0] * right_hand_side.mValues[0] +
				mValues[4] * right_hand_side.mValues[1] +
				mValues[8] * right_hand_side.mValues[2] +
				mValues[12] * right_hand_side.mValues[3];

			//Second Position
			newMatrix4.mValues[1] = mValues[1] * right_hand_side.mValues[0] +
				mValues[5] * right_hand_side.mValues[1] +
				mValues[9] * right_hand_side.mValues[2] +
				mValues[13] * right_hand_side.mValues[3];

			//Third Position
			newMatrix4.mValues[2] = mValues[2] * right_hand_side.mValues[0] +
				mValues[6] * right_hand_side.mValues[1] +
				mValues[10] * right_hand_side.mValues[2] +
				mValues[14] * right_hand_side.mValues[3];

			//Fourth Position
			newMatrix4.mValues[3] = mValues[3] * right_hand_side.mValues[0] +
				mValues[7] * right_hand_side.mValues[1] +
				mValues[11] * right_hand_side.mValues[2] +
				mValues[15] * right_hand_side.mValues[3];

			//Fifth Position
			newMatrix4.mValues[4] = mValues[0] * right_hand_side.mValues[4] +
				mValues[4] * right_hand_side.mValues[5] +
				mValues[8] * right_hand_side.mValues[6] +
				mValues[12] * right_hand_side.mValues[7];

			//Sixth Position
			newMatrix4.mValues[5] = mValues[1] * right_hand_side.mValues[4] +
				mValues[5] * right_hand_side.mValues[5] +
				mValues[9] * right_hand_side.mValues[6] +
				mValues[13] * right_hand_side.mValues[7];

			//Seventh Position
			newMatrix4.mValues[6] = mValues[2] * right_hand_side.mValues[4] +
				mValues[6] * right_hand_side.mValues[5] +
				mValues[10] * right_hand_side.mValues[6] +
				mValues[14] * right_hand_side.mValues[7];

			//Eighth Position
			newMatrix4.mValues[7] = mValues[3] * right_hand_side.mValues[4] +
				mValues[7] * right_hand_side.mValues[5] +
				mValues[11] * right_hand_side.mValues[6] +
				mValues[15] * right_hand_side.mValues[7];

			//Ninth Position
			newMatrix4.mValues[8] = mValues[0] * right_hand_side.mValues[8] +
				mValues[4] * right_hand_side.mValues[9] +
				mValues[8] * right_hand_side.mValues[10] +
				mValues[12] * right_hand_side.mValues[11];

			//Tenth Position
			newMatrix4.mValues[9] = mValues[1] * right_hand_side.mValues[8] +
				mValues[5] * right_hand_side.mValues[9] +
				mValues[9] * right_hand_side.mValues[10] +
				mValues[13] * right_hand_side.mValues[11];

			//Eleventh Position
			newMatrix4.mValues[10] = mValues[2] * right_hand_side.mValues[8] +
				mValues[6] * right_hand_side.mValues[9] +
				mValues[10] * right_hand_side.mValues[10] +
				mValues[14] * right_hand_side.mValues[11];

			//Twelfth Position
			newMatrix4.mValues[11] = mValues[3] * right_hand_side.mValues[8] +
				mValues[7] * right_hand_side.mValues[9] +
				mValues[11] * right_hand_side.mValues[10] +
				mValues[15] * right_hand_side.mValues[11];

			//Thirteenth Position
			newMatrix4.mValues[12] = mValues[0] * right_hand_side.mValues[12] +
				mValues[4] * right_hand_side.mValues[13] +
				mValues[8] * right_hand_side.mValues[14] +
				mValues[12] * right_hand_side.mValues[15];

			//Fourteenth Position
			newMatrix4.mValues[13] = mValues[1] * right_hand_side.mValues[12] +
				mValues[5] * right_hand_side.mValues[13] +
				mValues[9] * right_hand_side.mValues[14] +
				mValues[13] * right_hand_side.mValues[15];

			//Fifteenth Position
			newMatrix4.mValues[14] = mValues[2] * right_hand_side.mValues[12] +
				mValues[6] * right_hand_side.mValues[13] +
				mValues[10] * right_hand_side.mValues[14] +
				mValues[14] * right_hand_side.mValues[15];

			//Sixteenth Position
			newMatrix4.mValues[15] = mValues[3] * right_hand_side.mValues[12] +
				mValues[7] * right_hand_side.mValues[13] +
				mValues[11] * right_hand_side.mValues[14] +
				mValues[15] * right_hand_side.mValues[15];
			return newMatrix4;
		}


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
		}

				
		matrix4 matrix4::rotate_on_x(float angle){

			matrix4 newmatrix = matrix4();
			newmatrix.mValues[5]   = std::cos(-angle);
			newmatrix.mValues[6]   = -std::sin(-angle);
			newmatrix.mValues[9]   = std::sin(-angle);
			newmatrix.mValues[10]  = std::cos(-angle);

			return newmatrix;
		}


		matrix4 matrix4::rotate_on_y(float angle){

			matrix4 newmatrix = matrix4();
			newmatrix.mValues[0]= std::cos(-angle);
			newmatrix.mValues[2]= std::sin(-angle);
			newmatrix.mValues[8]= -std::sin(-angle);
			newmatrix.mValues[10] = std::cos(-angle);

			return newmatrix;
		}


		matrix4 matrix4::rotate_on_z(float angle){

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

			else {

				rotate_on_x(angle);
				rotate_on_x(angle);
				rotate_on_z(angle);
			}
		}


		matrix4 matrix4::get_translation_matrix(Vector4 translationVector){

			matrix4 mtx4;

			mtx4[3] = translationVector.x;
			mtx4[7] = translationVector.y;
			mtx4[11] = translationVector.z;

			return mtx4;
			
		}


		Vector4 & matrix4::translate_matrix(Vector4 translationVector){

			matrix4 mtx4; 

			mtx4 = get_translation_matrix(translationVector);

			translationVector.x = (mtx4[0] * translationVector.x) +
				(mtx4[1] * translationVector.y) +
				(mtx4[2] * translationVector.z) +
				(mtx4[2] * translationVector.w);

			translationVector.y = (mtx4[4] * translationVector.x) +
				(mtx4[5] * translationVector.y) +
				(mtx4[6] * translationVector.z) +
				(mtx4[7] * translationVector.w);

			translationVector.z = (mtx4[8] * translationVector.x) +
				(mtx4[9] * translationVector.y) +
				(mtx4[10] * translationVector.z) +
				(mtx4[11] * translationVector.w);

			translationVector.w = (mtx4[12] * 1) +
				(mtx4[13] * 1) +
				(mtx4[14] * 1) +
				(mtx4[15] * 1);


			return translationVector;
		}


		matrix4 matrix4::invert_matrix(){

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