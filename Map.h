#ifndef MAP_H
#define MAP_H

#include"ResourceManager.h"

class Map
{
public:
	unsigned int map;
	unsigned int effects;
	float texCoord[8];
	float texCoord2[8];

	Map();
	~Map();

	void render(float vertex[]);
};

#endif
