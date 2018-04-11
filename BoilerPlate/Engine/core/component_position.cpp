#include "component_position.hpp"

namespace engine
{
	namespace core
	{
		
		component_position::component_position(const std::string& pName)
		{
			mName = pName;
			mPosition = math::Vector4();
		}

		component_position::component_position(const std::string& pName, math::Vector4 pPosition)
		{
			mName = pName;
			mPosition = pPosition;
		}

		math::Vector4 component_position::get_position()
		{
			return mPosition;
		}

		void component_position::set_position(math::Vector4 pPosition)
		{
			mPosition = pPosition;
		}
		
	}
}