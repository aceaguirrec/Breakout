#include "component_model_matrix.hpp"

namespace engine
{
	namespace core
	{
		
			component_model_matrix::component_model_matrix(const std::string& hName)
			{
				mName = hName;
				mModelMatrix = math::matrix4();
			}


			math::matrix4* component_model_matrix::get_model_matrix()
			{
				return &mModelMatrix;
			}
		
	}
}