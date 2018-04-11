#include "component_movement.hpp"

namespace engine
{
	namespace core
	{
		component_movement::component_movement(const std::string& pName, float pMovementValue)
		{
			mName = pName;
			mAngle = 0.0f;
			mImpulse = pMovementValue;
		}

		float* component_movement::get_impulse_value()
		{
			return &mImpulse;
		}

		float* component_movement::get_angle()
		{
			return &mAngle;
		}
		
	}
}