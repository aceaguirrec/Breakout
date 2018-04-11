#pragma once
#ifndef _COMPONENT_OBJECT_TYPE_HPP_
#define _COMPONENT_OBJECT_TYPE_HPP_

#include "../core/component.hpp"
namespace engine
{
	namespace core
	{
		
		class component_object_type : public core::component
		{

		public:

			component_object_type(const std::string& pName, const std::string& pObjectType);

			std::string get_object_type();

		private:

			std::string mObjectType;

		};
		
	}
}


#endif