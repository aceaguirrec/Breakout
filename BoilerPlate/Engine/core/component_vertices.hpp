#pragma once

#ifndef _COMPONENT_VERTICES_HPP_
#define _COMPONENT_VERTICES_HPP_

#include "component.hpp"

namespace engine
{
	namespace core
	{
		
		class component_vertices : public engine::core::component
		{
		public:
			component_vertices(const std::string pName, float pVertices[MAX_VERTICES], int pIndices[MAX_INDICES]);

			float* get_vertices();
			int* get_indices();

		private:

			float mObjectVertices[MAX_VERTICES];
			int mIndices[MAX_INDICES];

		};
		
	}
}



#endif