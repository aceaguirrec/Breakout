#pragma once

#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "shader_manager.hpp"
#include "textures.hpp"


const int MAX_TEXTURES_NUMBER = 16;


namespace Engine {

	class renderer {

	public:

		renderer();
		~renderer();

		void load_textures(const char* texture_path[]);
		void load_vertices();
		void initialize_program_id();
		void render();
		void toggle_polygon_mode();


	private:

		bool mPolygonMode;

		GLuint mVertexArrayObject;
		GLuint mVertexBufferObject;
		GLuint mElementsBufferObject;
		GLuint mProgramID;

		shader_manager	mShaderManager;

		textures mTextures[MAX_TEXTURES_NUMBER];

	
	};

}

#endif // !RENDERER_HPP