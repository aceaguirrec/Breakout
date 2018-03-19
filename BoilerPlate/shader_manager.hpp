#pragma once
#ifndef _SHADER_MANAGER_H
#define _SHADER_MANAGER_H

#include <algorithm>
#include <fstream>
#include <GL/glew.h>
#include <iostream>
#include <SDL2/SDL_opengl.h>
#include <sstream>
#include <string>
#include <vector>


namespace engine {

		class shader_manager
		{
		public:
			shader_manager();
			GLuint LoadShaders(const char * vertex_file_path, const char * fragment_file_path);

		};
	}

#endif
