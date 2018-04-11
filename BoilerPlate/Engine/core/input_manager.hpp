#pragma once
#ifndef _INPUT_MANAGER_HPP
#define _INPUT_MANAGER_HPP
namespace engine {

	class input_manager {

	public:
		/* ==========================
		* CONSTRUCTORS
		* ==========================*/
		input_manager();


		void set_a(bool);
		void set_d(bool);
		void set_space(bool);
		bool A_IsPressed();
		bool D_IsPressed();
		bool Space_IsPressed();

	private:

		/* ==========================
		* MEMBERS
		* ==========================*/
		bool mD;
		bool mA;
		bool mSpace;
	};
}
#endif //!_INPUT_MANAGER_HPP