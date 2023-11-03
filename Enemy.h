#ifndef ENEMY_H
#define ENEMY_H

#include"ResourceManager.h"

class Enemy
{
public:
	unsigned int enemyTexture;
	int sideToMove;
	int currentAnim;
	float x, y;
	float texCoord[8];
	float speed;

	Enemy(int x);
	Enemy();
	~Enemy();

	void render(GLFWwindow*window, float vertex[], bool isCan,bool isDie);
	void move(bool isCan);
	void animations(GLFWwindow* window, bool icCan);
};
#endif

