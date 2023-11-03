#ifndef MAP_H
#define MAP_H

#include"ResourceManager.h"
#include<vector>

class pos
{
public:
	float x, y,width,heigbt;

	pos(float x, float y,float widt,float height)
	{
		this->x = x;
		this->y = y;
		this->width = widt;
		this->heigbt = height;
	}

	pos()
	{

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
	bool checkCollision(float x, float y, float width, float height, float width2, float height2);
};
#endif
