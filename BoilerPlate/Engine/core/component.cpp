#include "component.hpp"

namespace engine
{
	namespace core
	{
		component::component()
		{

		}
		component::component(const std::string& name){
			mName = name;
		}

		component::~component(){
			mFather = nullptr;
		}

		void component::update(double deltaTime){
			i_update::update(deltaTime);
		}
	}
}