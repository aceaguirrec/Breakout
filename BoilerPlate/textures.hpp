#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


namespace Engine {

	class textures {

	public:
		
		textures();
		textures(const char* texture_path);

		GLuint load_textures(const char* texture_path);
		GLuint get_texture();

	private:

		GLuint mTexture;
	
	};


}
#endif // !TEXTURE_H
