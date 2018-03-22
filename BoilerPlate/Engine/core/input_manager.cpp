#include "input_manager.hpp"


input_manager::input_manager(){

	dKey = false;
	delKey = false;
	escKey = false;
}


bool input_manager::get_d(){

	return dKey;
}


bool input_manager::get_del(){

	return delKey;
}


bool input_manager::get_esc(){

	return escKey;
}


void input_manager::set_d(bool dState){

	dKey = dState;
}


void input_manager::set_del(bool delState){

	delKey = delState;
}


void input_manager::set_esc(bool escState){

	escKey = escState;
}

