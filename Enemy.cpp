#include "Enemy.h"

Enemy::Enemy(int i)
{
	this->speed = 0.001;
	ResourceManager manager;
	this->enemyTexture = manager.LoadFromFile("res/textures/tanks.png",1);
	texCoord[0] = 0.75;
	texCoord[1] = 1;

	texCoord[2] = 0.8125;
	texCoord[3] = 1;

	texCoord[4] = 0.8125;
	texCoord[5] = 0.9375;

	texCoord[6] = 0.75;
	texCoord[7] = 0.9375;
	this->currentAnim = 0;
	this->sideToMove = 2;

	if (i == 0)
	{
		x = 0.95;
		y = 0.2;

	}
}

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
}

void Enemy::render(GLFWwindow* window,float vertex[],bool isCan)
{
	glPushMatrix();
	this->move(isCan);
	this->animations(window,isCan);

	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glBindTexture(GL_TEXTURE_2D, this->enemyTexture);
	glVertexPointer(2, GL_FLOAT, 0, vertex);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoord);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glPopMatrix();
}

void Enemy::move(bool isCan)
{
	if (sideToMove == 0 && isCan)
	{
		x -= 0.0001;
	}

	if (sideToMove == 2 && isCan)
	{
		y += 0.0001;
	}

	if (sideToMove == 1 && isCan)
	{
		y -= 0.0001;
	}

	if (sideToMove == 3 && isCan)
	{
		x -= 0.0001;
	}

	glTranslatef(-x, -y, 0);
}

void Enemy::animations(GLFWwindow* window,bool isCan)
{
	if (-x >= 0.85)
	{
		texCoord[0] = 0.6250;
		texCoord[1] = 1;

		texCoord[2] = 0.6875;
		texCoord[3] = 1;

		texCoord[4] = 0.6875;
		texCoord[5] = 0.9375;

		texCoord[6] = 0.635;
		texCoord[7] = 0.9375;
		sideToMove = 2;
	}

    if (-y <= -0.75)
    {
    	texCoord[0] = 0.8750;
    	texCoord[1] = 1;
    
    	texCoord[2] = 0.9375;
    	texCoord[3] = 1;
    
    	texCoord[4] = 0.9375;
    	texCoord[5] = 0.9375;
    
    	texCoord[6] = 0.8750;
    	texCoord[7] = 0.9375;
    
    	sideToMove = 3;
    }
	if (-y >=0.75)
	{
		texCoord[0] = 0.8750;
		texCoord[1] = 1;

		texCoord[2] = 0.9375;
		texCoord[3] = 1;

		texCoord[4] = 0.9375;
		texCoord[5] = 0.9375;

		texCoord[6] = 0.8750;
		texCoord[7] = 0.9375;

		sideToMove = 3;
	}




	if (!isCan)
	{
		if (sideToMove == 0)//right
		{
			texCoord[0] = 0.8750;
			texCoord[1] = 1;

			texCoord[2] = 0.9375;
			texCoord[3] = 1;

			texCoord[4] = 0.9375;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.8750;
			texCoord[7] = 0.9375;
			
			sideToMove = 3;
		}
		if (sideToMove == 1)//down
		{
			texCoord[0] = 0.75;
			texCoord[1] = 1;

			texCoord[2] = 0.8125;
			texCoord[3] = 1;

			texCoord[4] = 0.8125;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.75;
			texCoord[7] = 0.9375;

			y -= 0.002;
			sideToMove = 2;
		}
		if (sideToMove == 2)//up
		{

			texCoord[0] = 0.5;
			texCoord[1] = 1;

			texCoord[2] = 0.5625;
			texCoord[3] = 1;

			texCoord[4] = 0.5625;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.5;
			texCoord[7] = 0.9375;
			sideToMove = 1;
		}
		if (sideToMove == 3)//left
		{
			texCoord[0] = 0.625;
			texCoord[1] = 1;

			texCoord[2] = 0.6875;
			texCoord[3] = 1;

			texCoord[4] = 0.6875;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.625;
			texCoord[7] = 0.9375;

			sideToMove = 0;
		}

	}
}
