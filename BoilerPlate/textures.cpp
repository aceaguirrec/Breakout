#include <iostream>
#include "textures.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


namespace Engine {


	textures::textures(){}


	textures::textures(const char* texture_path) {

		mTexture = load_textures(texture_path);
	}

	GLuint textures::load_textures(const char * texture_path){

		unsigned int testTexture;

		glGenTextures(1, &testTexture);
		glBindTexture(GL_TEXTURE_2D, testTexture);

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int numberOfChannels;
		int width;
		int height; 


		//loads texture
		unsigned char* data = stbi_load(texture_path, &width, &height, &numberOfChannels, 0);

		if (data) {

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		else {

			std::cout << "Failed to load texture!" << std::endl;
			return -1;
		}

		stbi_image_free(data);

		return testTexture;
	}


	GLuint textures::get_texture() {

		return mTexture;
	}







}