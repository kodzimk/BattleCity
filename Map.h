#ifndef MAP_H
#define MAP_H

#include"ResourceManager.h"

class Map
{
public:
	unsigned int texture;
	float texCoord[8];

	Map();
	~Map();

	void render(float vertex[]);
};

#endif
