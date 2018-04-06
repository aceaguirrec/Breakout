#include "block.hpp"

namespace engine {

	namespace core {

		block::block() {

			mBlockTextureIndex = 0;
		}


		object_vertex* block::get_block_vertices() {

			return mBlockVertices;
		}


		int* block::get_block_indices(){

			return mBlockIndices;
		}


		int block::get_block_texture_index(){

			return mBlockTextureIndex;
		}


		}
}