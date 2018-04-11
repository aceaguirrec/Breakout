#include "component_object_type.hpp"

namespace engine
{
	namespace core
	{
		
			component_object_type::component_object_type(const std::string& pName, const std::string& pObjectType)
			{
				mName = pName;
				mObjectType = pObjectType;
			}

			std::string component_object_type::get_object_type()
			{
				return mObjectType;
			}

		
	}
}