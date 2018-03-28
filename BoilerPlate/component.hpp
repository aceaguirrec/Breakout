#pragma once
#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>
//
#include "i_update.hpp"

namespace engine
{
	namespace core
	{
		class game_object;
		class component : i_update {
		public:
			/* =============================================================
			* PUBLIC FUNCTIONS
			* ============================================================= */
			explicit component(const std::string& name);
			~component();
			void update(double deltaTime) override;

			/* =============================================================
			* GETTER FUNCTIONS
			* ============================================================= */
			void SetOwner(game_object* owner) { mOwner = owner; }
			game_object* GetOwner() const { return mOwner; }
			std::string GetName() const { return mName; }
		protected:
			/* =============================================================
			* MEMBERS
			* ============================================================= */
			game_object*	mOwner;
			std::string	mName;
		};
	}
}
#endif // !_COMPONENT_HPP_
