#pragma once

#ifndef BALL_HPP
#define BALL_HPP


#include "../../object_vertex.hpp"
#include "../../Engine/core/game_object.hpp"


namespace game
{
	namespace objects
	{
		class ball : public engine::core::game_object
		{

		public:
			ball();
			~ball();
		private:

			void attach_components();

		};

	}

}



#endif //!BALL_HPP
