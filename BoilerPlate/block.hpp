#pragma once

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "Engine\core\component.hpp"
#include "Engine\core\game_object.hpp"
#include "object_vertex.hpp"

namespace engine {

	namespace core {

		class block : public game_object {

		public:
			block();

			object_vertex* get_block_vertices();
			int* get_block_indices();
			int get_block_texture_index();


		private:

			object_vertex mBlockVertices[4] = {
				// positions         // colors          // texture coords
				{0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f},   // top right
				{0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f },   // bottom right
				{-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f},   // bottom left
				{-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f}    // top left 
			};


			int mBlockIndices[7] = { 0, 1, 3, 1, 2, 3 };
			int mBlockTextureIndex;
		

		};
	
	}
}
#endif //!BLOCK_HPP
