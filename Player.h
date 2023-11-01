#ifndef PLAYER_H
#define PLAYER_H

#include"ResourceManager.h"

class Player
{
public:
	float x, y;
	int sideToMove;
	double currentSide;
	unsigned int tankTex;
	float texCoord[8];
	float speed;
	float ugol;

	Player();
	~Player();

	void render(float vertex[],GLFWwindow* window);
	void Move(GLFWwindow* window,bool isCan);
	void animations(GLFWwindow* window);
};

#endif

