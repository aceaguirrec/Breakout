#pragma once
#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

#include <vector>

//
#include "i_update.hpp"
#include "i_render.hpp"
#include "unique_id.hpp"

namespace engine
{
	namespace core
	{
		class component;
		class scene;
		class game_object : public i_update, public i_render, public unique_id
		{
		public:
			/* =============================================================
			* CTOR FUNCTIONS
			* ============================================================= */
			game_object();
			~game_object();

			/* =============================================================
			* PUBLIC FUNCTIONS
			* ============================================================= */
			void attach_component(component*);
			void remove_component(component*);
			void add_child(game_object*);
			void remove_child(game_object*);
			void update(double deltaTime) override;
			void render() override;

			/* =============================================================
			* GETTER FUNCTIONS
			* ============================================================= */
			std::vector<component*>get_components() const { return mComponents; }
			std::vector<game_object*> get_children() const { return mChildren; }
			game_object* get_parent() const { return mParent; }

			template<typename T>
			T* get_component()
			{
				// If no components have been attached then return nothing
				//
				if (mComponents.size() == 0) return nullptr;

				std::vector< component* >::iterator comp = mComponents.begin();
				for (; comp != mComponents.end(); ++comp)
				{
					T* the_component = dynamic_cast<T*>(*comp);
					if (the_component)
					{
						return the_component;
					}
				}

				return nullptr;
			}
		protected:
			/* =============================================================
			* MEMBERS
			* ============================================================= */
			std::vector<component*>	mComponents;
			std::vector<game_object*> mChildren;
			game_object* mParent;
		};
	}
}
#endif // !GAMEOBJECT_HPP
