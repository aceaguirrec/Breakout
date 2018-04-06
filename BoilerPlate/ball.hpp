#pragma once

#ifndef BALL_HPP
#define BALL_HPP


#include "object_vertex.hpp"
#include "Engine\core\game_object.hpp"


namespace engine {

	namespace core {

		class ball : public game_object {

		public:

			ball();


			object_vertex* get_ball_vertices();
			int* get_ball_indices();
			int get_ball_texture_index();


		private:

			object_vertex mBallVertices[4] = {
				// positions         // colors           // texture coords
				{ 0.03f, 0.03f, 0.0f,    1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 1.0f },   // top right
				{ 0.03f, -0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  1.0f, 0.0f },   // bottom right
				{ -0.03f, 0.03f, 0.0f,   1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 1.0f },   // top left
				{ -0.03f, -0.03f, 0.0f,  1.0f, 1.0f, 1.0f, 1.0f,  0.0f, 0.0f }    // bottom left    

			};
		

			int mBallIndices[7] = { 0, 1, 2, 1, 3, 2, 0 };
			int mBallTextureIndex;
		
		
		};

	}

}
#endif //!BALL_HPP
