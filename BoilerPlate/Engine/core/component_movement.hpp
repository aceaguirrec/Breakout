#pragma once
#ifndef _COMPONENT_MOVEMENT_HPP_
#define _COMPONENT_MOVEMENT_HPP_

#include "component.hpp"
namespace engine
{
	namespace core
	{
			class component_movement : public core::component
			{
			public:

				component_movement(const std::string& pName, float pMovementValue);

				float* get_impulse_value();
				float* get_angle();


			private:

				float mImpulse;
				float mAngle;

			};
	}
}


#endif
