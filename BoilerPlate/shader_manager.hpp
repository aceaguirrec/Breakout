#pragma once

#ifndef SHADER_MANAGER_HPP
#define SHADER_MANAGER_HPP

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>



namespace Engine
{

	struct shader_manager
	{
	public:


		shader_manager();

		GLuint LoadShaders(const char* pVertexFilePath, const char* pFragmentFilePath);


	};

}
#endif
