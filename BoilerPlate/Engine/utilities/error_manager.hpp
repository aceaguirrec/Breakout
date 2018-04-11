#pragma once

#ifndef ERROR_MANAGER_HPP
#define ERROR_MANAGER_HPP

#include <iostream>


namespace engine {

	struct error_manager {

	public:

		int displayError(std::string fileName, std::string fileLineNumber, 
			std::string errorMessage, std::string rawErrorMessage);
	};
}

#endif // !ERROR_MANAGER_HPP