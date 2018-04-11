#pragma once
#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>
//
#include "i_update.hpp"
#include "../math/matrix4.hpp"
#include "../math/Vector4.hpp"

const int MAX_VERTICES = 36;
const int MAX_INDICES = 6;

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
			component();
			explicit component(const std::string& name);
			~component();
			void update(double deltaTime) override;

			/* =============================================================
			* GETTER FUNCTIONS
			* ============================================================= */
			void SetOwner(game_object* owner) { mFather = owner; }
			game_object* get_father() const { return mFather; }
			std::string get_name() const { return mName; }
			/* =============================================================
			* virtual functions
			* ============================================================= */
			
			virtual float* get_vertices() { float emptyVertices[MAX_VERTICES]; return emptyVertices; }
			virtual int* get_indices() { int emptyIndices[MAX_INDICES]; return emptyIndices; }
			virtual void set_position(math::Vector4 pNewPosition) {}
			virtual math::Vector4 get_position() { return NULL; }
			virtual float* get_movement_value() { return NULL; }
			virtual float* get_angle() { return NULL; }
			virtual math::matrix4* get_model_matrix() { return NULL; }
			virtual std::string get_object_type() { std::string emptyString = ""; return emptyString; }

		protected:
			/* =============================================================
			* MEMBERS
			* ============================================================= */
			game_object*	mFather;
			std::string		mName;
		};
	}
}
#endif // !_COMPONENT_HPP_
