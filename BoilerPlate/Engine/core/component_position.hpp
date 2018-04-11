#pragma once
#ifndef _COMPONENT_POSITION_HPP_
#define _COMPONENT_POSITION_HPP_

#include "component.hpp"
#include "../math/vector4.hpp"


namespace engine
{
	namespace core
	{
	
		class component_position : public core::component
		{
		public:

			component_position(const std::string& );
			component_position(const std::string& , math::Vector4 );
			math::Vector4 get_position();
			void set_position(math::Vector4 );

		private:
			math::Vector4 mPosition;

		};
		
	}
}


#endif