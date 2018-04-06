#include "ball.hpp"

namespace engine {

	namespace core {

		ball::ball() {

			mBallTextureIndex = 1; 
		}


		object_vertex* ball::get_ball_vertices() {

			return mBallVertices;
		}


		int* ball::get_ball_indices() {

			return mBallIndices;
		}


		int ball::get_ball_texture_index() {

			return mBallTextureIndex;
		}


	}
}