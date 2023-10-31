#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include<GL/glew.h>
#include<GLFW/glfw3.h>


class ResourceManager
{
public:
	int width;
	int height;
	int cnt;

	ResourceManager();
	~ResourceManager();

	unsigned int LoadFromFile(const char* path,int active);
};

#endif

