#pragma once
#ifndef _COMPONENT_MODEL_MATRIX_HPP_
#define _COMPONENT_MODEL_MATRIX_HPP_

#include "../math/Vector4.hpp"

#include "../core/component.hpp"


namespace engine
{
	namespace core
	{
		class component_model_matrix : public component
		{

		public:
			//crt
			component_model_matrix(const std::string& );
			//public funct.
			math::matrix4* get_model_matrix();

		private:
			//member
			math::matrix4 mModelMatrix;
		};
		
	}
}


#endif