#include <Windows.h>
#include "error_manager.hpp"


namespace engine {

	int error_manager::displayError(std::string fileName, std::string fileLineNumber, 
		std::string errorMessage, std::string rawErrorMessage){

		std::string error = "In file: " + fileName + "\nIn line: " + fileLineNumber +
							"\n" + errorMessage + "\nUsing OpenGL 3.30 and GLSL 330 core";

		LPCSTR display_message_box = error.c_str();


		#ifdef _WIN32

		int messageBox = MessageBoxA(NULL, display_message_box, 
			rawErrorMessage.c_str(), MB_ICONWARNING | MB_OK);

		#elif defined _unix_ || defined APPLE 

		std::cerr << displayError;

		#endif
		return messageBox;
	}

}