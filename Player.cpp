#include "Player.h"
#include<iostream>

Player::Player()
{
	ResourceManager manager;

	this->tankTex = manager.LoadFromFile("res/textures/tanks.png", 1);

	this->ugol = 0;
	this->speed = 0;

	texCoord[0] = 0;
	texCoord[1] = 1;

	texCoord[2] = 0.0625;
	texCoord[3] = 1;

	texCoord[4] = 0.0625;
	texCoord[5] = 0.9375;

	texCoord[6] = 0;
	texCoord[7] = 0.9375;

	this->currentSide = 0.0;
	this->sideToMove = 0;
	this->x = -0.17f;
	this->y = 0.1f;
}

Player::~Player()
{
}

void Player::render(float vertex[],GLFWwindow* window,bool isCan)
{

	glPushMatrix();
	this->Move(window,isCan);
	this->animations(window);

	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glBindTexture(GL_TEXTURE_2D,this->tankTex);
	glTexCoordPointer(2, GL_FLOAT, 0, this->texCoord);
	glVertexPointer(2, GL_FLOAT, 0, vertex);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void Player::Move(GLFWwindow* window,bool isCan)
{
	if (glfwGetKey(window,GLFW_KEY_W)>0&& sideToMove==0&&isCan)
	{
	     	y -= 0.0002;
	}
	else if (glfwGetKey(window, GLFW_KEY_S) > 0 && sideToMove == 2&& isCan)
	{
			y += 0.0002;
	}
	else if (glfwGetKey(window, GLFW_KEY_A) > 0 && sideToMove == 1&&  isCan)
	{
	        x += 0.0002;		
	}
	else if (glfwGetKey(window, GLFW_KEY_D) > 0 && sideToMove == 3&& isCan)
	{
			x -= 0.0002;
	}


	glTranslatef(-x, -y, 0);
}

void Player::animations(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_RIGHT) > 0)
	{
		currentSide += 0.004;

		if (floor(currentSide) == 1)
		{
			texCoord[0] = 0;
			texCoord[1] = 1;

			texCoord[2] = 0.0625;
			texCoord[3] = 1;

			texCoord[4] = 0.0625;
			texCoord[5] = 0.9375;

			texCoord[6] = 0;
			texCoord[7] = 0.9375;
			sideToMove = 0;
		}

		if (floor(currentSide) == 2)
		{
			texCoord[0] = 0.375;
			texCoord[1] = 1;

			texCoord[2] = 0.4375;
			texCoord[3] = 1;

			texCoord[4] = 0.4375;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.375;
			texCoord[7] = 0.9375;
			sideToMove = 3;
		}

		if (floor(currentSide) == 3)
		{
			texCoord[0] = 0.25;
			texCoord[1] = 1;

			texCoord[2] = 0.3125;
			texCoord[3] = 1;

			texCoord[4] = 0.3125;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.25;
			texCoord[7] = 0.9375;
			sideToMove = 2;
		}


		if (floor(currentSide) == 4)
		{
			texCoord[0] = 0.125;
			texCoord[1] = 1;

			texCoord[2] = 0.1875;
			texCoord[3] = 1;

			texCoord[4] = 0.1875;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.125;
			texCoord[7] = 0.9375;
			currentSide = 0;
			sideToMove = 1;
		}
		
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT) > 0)
	{
		currentSide += 0.004;

		if (floor(currentSide) == 1)
		{
			texCoord[0] = 0.125;
			texCoord[1] = 1;

			texCoord[2] = 0.1875;
			texCoord[3] = 1;

			texCoord[4] = 0.1875;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.125;
			texCoord[7] = 0.9375;
			sideToMove = 1;
		}

		if (floor(currentSide) == 2)
		{
			texCoord[0] = 0.25;
			texCoord[1] = 1;

			texCoord[2] = 0.3125;
			texCoord[3] = 1;

			texCoord[4] = 0.3125;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.25;
			texCoord[7] = 0.9375;
			sideToMove = 2;
		}

		if (floor(currentSide) == 3)
		{
			texCoord[0] = 0.375;
			texCoord[1] = 1;

			texCoord[2] = 0.4375;
			texCoord[3] = 1;

			texCoord[4] = 0.4375;
			texCoord[5] = 0.9375;

			texCoord[6] = 0.375;
			texCoord[7] = 0.9375;
			sideToMove = 3;
		}


		if (floor(currentSide) == 4)
		{
			texCoord[0] = 0;
			texCoord[1] = 1;

			texCoord[2] = 0.0625;
			texCoord[3] = 1;

			texCoord[4] = 0.0625;
			texCoord[5] = 0.9375;

			texCoord[6] = 0;
			texCoord[7] = 0.9375;
			currentSide = 0;
			sideToMove = 0;
		}

		std::cout << currentSide << std::endl;
		return;
	}
}
