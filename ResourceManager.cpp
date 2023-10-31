#include "ResourceManager.h"
#define STB_IMAGE_IMPLEMENTATION   
#include"std_image.h"


ResourceManager::ResourceManager()
{
	this->width = 0;
	this->height = 0;
	this->cnt = 0;
}

ResourceManager::~ResourceManager()
{

}

unsigned int ResourceManager::LoadFromFile(const char* path,int active)
{
	stbi_set_flip_vertically_on_load(1);

    unsigned int texture;
	unsigned char* buffer = stbi_load(path, &width, &height, &cnt, 0);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(buffer);
    
    this->width = 0;
    this->height = 0;
    this->cnt = 0;

    return texture;
}
