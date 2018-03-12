#include "Matrix4.hpp"

namespace engine 
{
	namespace math 
	{

		Matrix4::Matrix4() {}
		

		Matrix4::Matrix4(float member0, float member4, float member8,  float member12,
						 float member1, float member5, float member9,  float member13,
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


		Matrix4::Matrix4(std::vector<float> array) {
													// use pointers
			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					//mValues[j][i] = array[j][i];
				}
			}
		}


		void Matrix4::identity() {

			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					if (i == j) mValues[j][i] = 1;
					else mValues[j][i] = 0;
				}
			}
		}


		int* Matrix4::get_values() {

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


		Matrix4 Matrix4::get_transpose() {

			Matrix4 newMatrix4 = Matrix4();
			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					newMatrix4.mValues[i][j] = mValues[j][i];
				}
			}
			return newMatrix4;
		}


		float Matrix4::get_individual_element(int indexLine, int indexColumn) {

			return mValues[indexLine][indexColumn];
		}


		int * Matrix4::get_angles(){

			float yaw, pitch, roll;
			static int angles[3];
			if ( mValues[0][0] == 1.0f){

				yaw = atan2f(mValues[1][3], mValues[3][4]);
				pitch = 0;
				roll = 0;

			}

			else if (mValues[0][0] == -1.0f){

				yaw = atan2f(mValues[1][3], mValues[3][4]);
				pitch = 0;
				roll = 0;
			}

			else{

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


		Matrix4& Matrix4::operator=(const Matrix4& ride_hand_side){

			// Prevent self assignment
			if (this == &ride_hand_side) return *this;

			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					mValues[j][i] = ride_hand_side.mValues[j][i];
				}
			}
			return *this;
		}


		Matrix4& Matrix4::operator+=(const Matrix4& ride_hand_side){

			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					mValues[j][i] += ride_hand_side.mValues[j][i];
				}
			}

			return *this;
		}


		Matrix4& Matrix4::operator-=(const Matrix4& ride_hand_side){

			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					mValues[j][i] -= ride_hand_side.mValues[j][i];
				}
			}
			return *this;
		}


		Matrix4& Matrix4::operator*=(const Matrix4& ride_hand_side){

			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					for (int k = 0; k < 3; k++) {

						mValues[j][i] += 
							mValues[j][i + k] *
							ride_hand_side.mValues[j][i + k];
					}
				}
			}
			return *this;
		}


		Matrix4 Matrix4::operator+(const Matrix4& ride_hand_side) const{

			Matrix4 newMatrix4 = Matrix4();
			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					newMatrix4.mValues[j][i] = mValues[j][i] + ride_hand_side.mValues[j][i];
				}
			}
			return newMatrix4;
		}

		Matrix4 Matrix4::operator-(const Matrix4& ride_hand_side) const{

			Matrix4 newMatrix4 = Matrix4();
			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					newMatrix4.mValues[j][i] = mValues[j][i] - ride_hand_side.mValues[j][i];
				}
			}
			return newMatrix4;
		}


		Matrix4 Matrix4::operator*(const Matrix4& ride_hand_side) const{

			Matrix4 newMatrix4 = Matrix4();
			for (int i = 0; i < 4; i++) {

				for (int j = 0; j < 4; i++) {

					for (int k = 0; k < 3; k++) {
						newMatrix4.mValues[j][i]+=
							mValues[j][i + k] * 
							ride_hand_side.mValues[j][i + k];
					}
				}
			}
			return newMatrix4;
		}


		/*
		Matrix4 Matrix4::operator/(const Matrix4& ride_hand_side) const
		{
			
		}
		Matrix4& Matrix4::operator/=(const Matrix4& ride_hand_side)
		{
			return NULL;
		}*/


	}
}