#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>


namespace engine {

	class textures {

	public:
		/* =============================================================
		* CTOR
		* ============================================================= */
		
		textures();
		textures(const char*, bool );

		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */

		GLuint load_textures(const char* , bool);
		GLuint get_texture();
		void initialize(const char*, bool );

	private:
		/* =============================================================
		* MEMBERS
		* ============================================================= */

		GLuint mTexture;
	
	};


}
#endif // !TEXTURE_H
