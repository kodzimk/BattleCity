#include "Map.h"
#include<iostream>

Map::Map()
{
	ResourceManager manage;
	this->map = manage.LoadFromFile("res/textures/map_8x8.png", 1);
	this->effects = manage.LoadFromFile("res/textures/map_16x16.png", 1);

	texCoord[0] = 0;
	texCoord[1] = 1;

	texCoord[2] = 0.1;
	texCoord[3] = 1;

	texCoord[4] = 0.1;
	texCoord[5] = 0.9;

	texCoord[6] = 0;
	texCoord[7] = 0.9;

	texCoord2[0] = 0;
	texCoord2[1] = 0.4;
			
	texCoord2[2] = 0.15;
	texCoord2[3] = 0.4;
			
	texCoord2[4] = 0.15;
	texCoord2[5] = 0.2;
			
	texCoord2[6] = 0;
	texCoord2[7] = 0.2;
	this->counts = 0;

}

Map::~Map()
{
	for (int i = 0; i < this->positions.size(); i++)
	{
		delete this->positions[i];
	}
}

void Map::render(float vertex[])
{
	float effects[] = {
		0,1,
		0.12,1,
		0.12,0.8,
		0,0.8
	};
	float effects2[] = {
		0.5,0.7,
		0.62,0.7,
		0.62,0.5,
		0.5,0.5
	};

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glActiveTexture(GL_TEXTURE0);
	glVertexPointer(2, GL_FLOAT, 0, vertex);
	glTexCoordPointer(2, GL_FLOAT, 0, &this->texCoord);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			glPushMatrix();
			if (j == 0)
			{
				glTranslatef(-0.8, i * 0.1, 0);
				if (counts < 31)
				{				
					counts++;
					this->positions.push_back(new pos(-0.8, i*0.1,0.1,0.1));
				}
			}

			if (j == 1)
			{
				glTranslatef(-0.5, i * 0.1, 0);
				if (counts < 31)
				{
					counts++;
					this->positions.push_back(new pos(-0.5, i*0.1,0.1,0.1));
				}
			}

			if (j == 2&&i!=0)
			{
				glTranslatef(-0.2, i * 0.1, 0);
				if (counts < 31)
				{
					counts++;
					this->positions.push_back(new pos(-0.2, i*0.1,0.1,0.1));
				}
			}
			else if(j==2&&i==0)
			{
				glTranslatef(-0.1,  -0.2, 0);
				if (counts < 31)
				{
					counts++;
					this->positions.push_back(new pos(-0.1, -0.2,0.1,0.1));
				}
			}

			if (j == 3&&i!=0)
			{
				glTranslatef(0.1, i * 0.1, 0);
				if (counts < 31)
				{
					counts++;
					this->positions.push_back(new pos(0.1, i*0.1,0.1,0.1));
				}
			}
			else if (j == 3 && i == 0)
			{
				glTranslatef(0, -0.2, 0);
				if (counts < 31)
				{
					counts++;
					this->positions.push_back(new pos(0, -0.2,0.1,0.1));
				}
			}

			if (j == 4)
			{
				glTranslatef(0.4, i * 0.1, 0);
				if (counts < 31)
				{
					counts++;
					this->positions.push_back(new pos(0.4, i*0.1,0.1,0.1));
				}
			}
			if (j == 5)
			{
				glTranslatef(0.7, i * 0.1, 0);
				if (counts < 31)
				{
					counts++;
					this->positions.push_back(new pos(0.7, i*0.1,0.1,0.1));
				}
			}


			glBindTexture(GL_TEXTURE_2D, this->map);
			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			glPopMatrix();
		}
	}


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++) {

			glPushMatrix();
			glTranslatef(0, -0.45, 0);

			if (j == 0)
			{
				glTranslatef(-0.8, -i * 0.1, 0);
				if (counts < 70)
				{
					counts++;
					this->positions.push_back(new pos(-0.8,-0.45+( -i * 0.1), 0.1, 0.1));
				}
			}

			if (j == 1)
			{
				glTranslatef(-0.5, -i * 0.1, 0);
				if (counts < 70)
				{
					counts++;
					this->positions.push_back(new pos(-0.5, -0.45 + (-i * 0.1), 0.1, 0.1));
				}
			}

			if (j == 2)
			{
				glTranslatef(0, 0.2, 0);
				glTranslatef(-0.2, -i * 0.1, 0);
				if (counts < 70)
				{
					counts++;
					this->positions.push_back(new pos(-0.2, -0.25 + (-i * 0.1), 0.1, 0.1));
				}
			}


			if (j == 3)
			{
			
				glTranslatef(0, 0.2, 0);
				glTranslatef(0.1, -i * 0.1, 0);
				if (counts < 70)
				{
					counts++;
					this->positions.push_back(new pos(0.1, -0.25 + (-i * 0.1), 0.1, 0.1));
				}
			}


			if (j == 4)
			{
				glTranslatef(0.4, -i * 0.1, 0);
				if (counts < 70)
				{
					counts++;
					this->positions.push_back(new pos(0.4, -0.45 + (-i * 0.1), 0.1, 0.1));
				}
			}
			if (j == 5)
			{
				glTranslatef(0.7, -i * 0.1, 0);
				if (counts < 70)
				{
					counts++;
					this->positions.push_back(new pos(0.7, -0.45 + (-i * 0.1), 0.1, 0.1));
				}
			}

			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			glPopMatrix();
		}
	}



	for (int i = 0; i < 10; i++)
	{

			glPushMatrix();


			if (i == 0)
			{
				glTranslatef(-0.2, -0.7, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(-0.2, -0.7, 0.1, 0.1));
				}
			}
			if (i == 2)
			{
				glTranslatef(-0.1, -0.7, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(-0.1,-0.7, 0.1, 0.1));
				}
			}
			if (i == 1)
			{
				glTranslatef(0, -0.7, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(0, -0.7, 0.1, 0.1));
				}
			}
			if (i == 3)
			{
				glTranslatef(0.1, -0.7, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(0.1, -0.7, 0.1, 0.1));
				}
			}


			if (i == 4)
			{
				glTranslatef(-0.2, -0.8, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(-0.2,-0.8, 0.1, 0.1));
				}
			}
			if (i == 5)
			{
				glTranslatef(-0.2, -0.9, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(-0.2, -0.9, 0.1, 0.1));
				}
			}
			if (i == 6)
			{
				glTranslatef(-0.2, -1, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(-0.2, -1, 0.1, 0.1));
				}
			}

			if (i == 7)
			{
				glTranslatef(0.1, -0.8, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(0.1, -0.8, 0.1, 0.1));
				}
			}
			if (i == 8)
			{
				glTranslatef(0.1, -0.9, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(0.1, -0.9, 0.1, 0.1));
				}
			}
			if (i == 9)
			{
				glTranslatef(0.1, -1, 0);
				if (counts < 82)
				{
					counts++;
					this->positions.push_back(new pos(0.1, -1, 0.1, 0.1));
				}
			}
		

			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			glPopMatrix();
		
	}

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, this->effects);
	glTexCoordPointer(2, GL_FLOAT, 0, &effects2);
	glTranslatef(-0.95, -0.2, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, this->effects);
	glTexCoordPointer(2, GL_FLOAT, 0, &effects2);
	glTranslatef(0.85 , -0.2, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, this->effects);
	glTexCoordPointer(2, GL_FLOAT, 0, &effects2);
	glTranslatef(0, 0.3, 0);

	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glPopMatrix();


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			glPushMatrix();

			glBindTexture(GL_TEXTURE_2D, this->map);
			glTexCoordPointer(2, GL_FLOAT, 0, &texCoord2);

			if (j == 0 && i == 1)
			{
				glTranslatef(-1, -0.3, 0);
				if (counts < 110)
				{
					counts++;
					this->positions.push_back(new pos(-1, -0.3, 0.1, 0.1));
				}
			}
			else  if (j == 0)
			{
				glTranslatef(-0.9, -0.3, 0);
				if (counts < 110)
				{
					counts++;
					this->positions.push_back(new pos(-0.9, -0.3, 0.1, 0.1));
				}
			}

			if (j == 1 && i == 1)
			{
				glTranslatef(0.9, -0.3, 0);
				if (counts < 110)
				{
					counts++;
					this->positions.push_back(new pos(0.9, -0.3, 0.1, 0.1));
				}
			}
			else if (j == 1)
			{
				glTranslatef(0.8, -0.3, 0);
				if (counts < 110)
				{
					counts++;
					this->positions.push_back(new pos(0.8, -0.3, 0.1, 0.1));
				}
			}

			if (j == 2 && i == 1)
			{		
				glTranslatef(-0.1, 0.2, 0);		
				if (counts < 90)
				{
					counts++;
					this->positions.push_back(new pos(-0.1, 0.2, 0.1, 0.1));
				}
			}
			else if (j == 2)
			{

				glTranslatef(0, 0.2, 0);
				if (counts < 90)
				{
					counts++;
					this->positions.push_back(new pos(0,0.2, 0.1, 0.1));
				}
			}

			glDrawArrays(GL_TRIANGLE_FAN,0,4);
			glPopMatrix();
		}
	}

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, this->effects);
	glTexCoordPointer(2, GL_FLOAT, 0, &effects);
	if (counts < 110)
	{
		counts++;
		this->positions.push_back(new pos(-0.05, -0.87, 0.1, 0.1));
	}

		glTranslatef(-0.05, -0.87, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glPopMatrix();


	
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

bool Map::checkCollision(float x, float y, float width,float height,float width2,float height2)
{
	for (int i = 0; i < this->positions.size(); i++)
	{
		pos box1right;
		box1right.x = x;
		box1right.y = y;
		pos box1left;
		box1left.x = x + width;
		box1left.y = y + height;

		pos box2left;
		pos box2right;
		box2right.x = this->positions[i]->x;
		box2right.y = this->positions[i]->y;
		box2left.x = this->positions[i]->x + width2;
		box2left.y = this->positions[i]->y + height2;

		if (box2right.x <= box1left.x &&
			box2left.x >= box1right.x &&
			box2right.y <= box1left.y &&
			box2left.y >= box1right.y)
		{
			return false;
		}
	}
	return true;
}
