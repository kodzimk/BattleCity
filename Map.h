#ifndef MAP_H
#define MAP_H

#include"ResourceManager.h"
#include<vector>

class pos
{
public:
	float x, y;

	pos(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

class Map
{
public:
	unsigned int map;
	unsigned int effects;
	std::vector<pos*>positions;
	float texCoord[8];
	float texCoord2[8];
	int counts;

	Map();
	~Map();

	void render(float vertex[]);
	bool checkCollision(float x, float y,float size,float sizeY);
};

#endif
