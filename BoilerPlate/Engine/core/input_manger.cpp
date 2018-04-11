#include "input_manager.hpp"

namespace engine {

	input_manager::input_manager(){

		mD = false;
		mA = false;
		mSpace = false;

	}
	void input_manager::set_a(bool value)
	{
		mA = value;
	}
	void input_manager::set_d(bool value)
	{
		mD = value;
	}
	void input_manager::set_space(bool value)
	{
		mSpace = value;
	}
	bool input_manager::Space_IsPressed()
	{
		return mSpace;
	}
	bool input_manager::A_IsPressed()
	{
		return mA;
	}
	bool input_manager::D_IsPressed()
	{
		return mD;
	}
}