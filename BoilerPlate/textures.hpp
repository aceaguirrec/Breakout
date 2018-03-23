#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


namespace engine {

	class textures {

	public:
		
		textures();
		textures(const char* texture_path);

		GLuint load_textures(const char* texture_path);
		GLuint get_texture();
		void initialize(const char* texture_path);

	private:

		GLuint mTexture;
	
	};


}
#endif // !TEXTURE_H
