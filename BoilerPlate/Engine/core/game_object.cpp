
// STL
#include <algorithm>

// 
#include "component.hpp"
#include "game_object.hpp"

namespace engine
{
	namespace core
	{
		game_object::game_object()
			: mParent(nullptr)
		{}

		game_object::~game_object()
		{
			// Delete all attached components
			//
			while (!mComponents.empty()) delete mComponents.back(), mComponents.pop_back();

			// Delete all attached children
			//
			while (!mChildren.empty()) delete mChildren.back(), mChildren.pop_back();
		}

		void game_object::attach_component(component* component)
		{
			component->SetOwner(this);
			mComponents.push_back(component);
		}

		void game_object::remove_component(component* component)
		{
			mComponents.erase(
				remove(mComponents.begin(), mComponents.end(), component), mComponents.end()
			);

			delete component;
		}

		void game_object::add_child(game_object* child)
		{
			// Set the child parent
			child->mParent = this;

			// 
			mChildren.push_back(child);
		}

		void game_object::remove_child(game_object* child)
		{
			mChildren.erase(
				remove(mChildren.begin(), mChildren.end(), child), mChildren.end()
			);

			delete child;
		}

		void game_object::update(double deltaTime)
		{
			// update components
			//
			std::vector< component* >::iterator comp = mComponents.begin();
			for (; comp != mComponents.end(); ++comp)
			{
				(*comp)->update(deltaTime);
			}

			// update children
			//
			std::vector< game_object* >::iterator child = mChildren.begin();
			for (; child != mChildren.end(); ++child)
			{
				(*child)->update(deltaTime);
			}

			// Base class function call
			//
			i_update::update(deltaTime);
		}

		void game_object::render()
		{
			
			std::vector< game_object* >::iterator child = mChildren.begin();
			for (; child != mChildren.end(); ++child)
			{
				(*child)->render();
			}
			
		}
		component* game_object::get_component(const std::string pName)
		{
			for (int i = 0; i < mComponents.size(); i++)
			{
				if (mComponents[i]->get_name() == pName)
				{
					return mComponents[i];
				}
			}

			return NULL;
		}

		void game_object::translate(math::Vector4 pTranslateVector)
		{
			this->get_component("model_matrix")->get_model_matrix()->translate(pTranslateVector);
			this->get_component("position")->set_position(this->get_component("position")->get_position() += pTranslateVector);
		}
	}
}