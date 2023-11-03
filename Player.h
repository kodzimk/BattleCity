#ifndef PLAYER_H
#define PLAYER_H

#include"ResourceManager.h"

class Player
{
public:
	bool isShoot;
	float bullX, bullY;
	int sideToShoot;
	int bulletCnt;
	float x, y;
	int sideToMove;
	double currentSide;
	unsigned int tankTex;
	float texCoord[8];
	float speed;
	float ugol;

	Player();
	~Player();

	void render(float vertex[],GLFWwindow* window,bool isCan);
	void Move(GLFWwindow* window,bool isCan);
	void animations(GLFWwindow* window);
	const bool isEnemyCollide(float x, float y, float width, float height);
};

#endif

