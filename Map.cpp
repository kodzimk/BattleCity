#include "Map.h"

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
	glScalef(0.2, 0.3, 1);
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glActiveTexture(GL_TEXTURE0);
	glVertexPointer(2, GL_FLOAT, 0, vertex);
	glTexCoordPointer(2, GL_FLOAT, 0, &this->texCoord);
	int a = 0.9;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			glPushMatrix();
			if (j == 0)
			{
				glTranslatef(-4, i * 0.5, 0);
				if (counts < 40)
				{
					counts++;
					this->positions.push_back(new pos(-4, i*0.5));
				}
			}

			if (j == 1)
			{
				glTranslatef(-2.5, i * 0.5, 0);
				if (counts < 40)
				{
					counts++;
					this->positions.push_back(new pos(-2.5, i*0.5));
				}
			}

			if (j == 2&&i!=0)
			{
				glTranslatef(-1, i * 0.5, 0);
				if (counts < 40)
				{
					counts++;
					this->positions.push_back(new pos(-1, i*0.5));
				}
			}
			else if(j==2&&i==0)
			{
				glTranslatef(-1,  -1.5, 0);
				if (counts < 40)
				{
					counts++;
					this->positions.push_back(new pos(-1, -1.5));
				}
			}

			if (j == 3&&i!=0)
			{
				glTranslatef(0.5, i * 0.5, 0);
				if (counts < 40)
				{
					counts++;
					this->positions.push_back(new pos(0.5, i*0.5));
				}
			}
			else if (j == 3 && i == 0)
			{
				glTranslatef(-0.5, -0.5, 0);
				if (counts < 40)
				{
					counts++;
					this->positions.push_back(new pos(-0.5, -0.5));
				}
			}

			if (j == 4)
			{
				glTranslatef(2, i * 0.5, 0);
				if (counts < 40)
				{
					counts++;
					this->positions.push_back(new pos(2, i*0.5));
				}
			}
			if (j == 5)
			{
				glTranslatef(3.5, i * 0.5, 0);
				if (counts < 40)
				{
					counts++;
					this->positions.push_back(new pos(3.5, i*0.5));
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
			glTranslatef(0, -1.8, 0);

			if (j == 0)
			{
				glTranslatef(-4, -i * 0.4, 0);
			}

			if (j == 1)
			{
				glTranslatef(-2.5, -i * 0.4, 0);
			}

			if (j == 2 )
			{
				glTranslatef(0, 1, 0);
				glTranslatef(-1, -i * 0.4, 0);
			}


			if (j == 3)
			{
				glTranslatef(0, 1, 0);
				glTranslatef(0, -i * 0.4, 0);
			}


			if (j == 4)
			{
				glTranslatef(2, -i * 0.4, 0);
			}
			if (j == 5)
			{
				glTranslatef(3.5, -i * 0.4, 0);
			}

			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			glPopMatrix();
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			glPushMatrix();

			if (j == 0)
			{
				glTranslatef(-3, -0.95, 0);
			}
			if (j == 0 && i == 1)
			{
				glTranslatef(-0.5, 0, 0);
			}

			if (j == 1)
			{
				glTranslatef(3, -0.95, 0);
			}
			if (j == 1&&i==1)
			{
				glTranslatef(0.5, 0, 0);
			}

			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			glPopMatrix();
		}
	}

	for (int i = 0; i < 10; i++)
	{

			glPushMatrix();
			glTranslatef(0, -0.2, 0);
			glScalef(0.6, 0.5, 1);

			if (i == 0)
			{
				glTranslatef(-1.5, -5, 0);
			}
			if (i == 2)
			{
				glTranslatef(-0.5, -5, 0);
			}
			if (i == 1)
			{
				glTranslatef(-1, -5, 0);
			}
			if (i == 3)
			{
				glTranslatef(0, -5, 0);
			}


			if (i == 4)
			{
				glTranslatef(-1.5, -5.5, 0);
			}
			if (i == 5)
			{
				glTranslatef(-1.5, -6, 0);
			}
			if (i == 6)
			{
				glTranslatef(-1.5, -6.5, 0);
			}

			if (i == 7)
			{
				glTranslatef(0, -5.5, 0);
			}
			if (i == 8)
			{
				glTranslatef(0, -6, 0);
			}
			if (i == 9)
			{
				glTranslatef(0, -6.5, 0);
			}
		

			glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
			glPopMatrix();
		
	}

	glPushMatrix();
	glScalef(1.2, 1, 1);
	glBindTexture(GL_TEXTURE_2D, this->effects);
	glTexCoordPointer(2, GL_FLOAT, 0, &effects2);
	glTranslatef(-4.1, -0.5, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glPopMatrix();

	glPushMatrix();
	glScalef(1.2, 1, 1);
	glBindTexture(GL_TEXTURE_2D, this->effects);
	glTexCoordPointer(2, GL_FLOAT, 0, &effects2);
	glTranslatef(-0.23 , 1, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glPopMatrix();

	glPushMatrix();
	glScalef(1.2, 1, 1);
	glBindTexture(GL_TEXTURE_2D, this->effects);
	glTexCoordPointer(2, GL_FLOAT, 0, &effects2);
	glTranslatef(3.6, -0.5, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glPopMatrix();

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			glPushMatrix();
			glScalef(0.8, 0.6, 1);
			glBindTexture(GL_TEXTURE_2D, this->map);
			glTexCoordPointer(2, GL_FLOAT, 0, &texCoord2);

			if (j == 0 && i == 1)
			{
				glTranslatef(-5.8, -1, 0);
			}
			else  if (j == 0)
			{
				glTranslatef(-6.3, -1, 0);
			}

			if (j == 1 && i == 1)
			{
				glTranslatef(5.8, -1, 0);
			}
			else if (j == 1)
			{
				glTranslatef(5.3, -1, 0);
			}

			if (j == 2 && i == 1)
			{		
				glScalef(1.25, 1.25, 1);
				glTranslatef(-0.5, 1, 0);		
			}
			else if (j == 2)
			{
				glScalef(1.25, 1.25, 1);
				glTranslatef(0, 1, 0);
			}

			glDrawArrays(GL_TRIANGLE_FAN,0,4);
			glPopMatrix();
		}
	}

	glPushMatrix();
	glScalef(1.3, 0.9, 1);
	glBindTexture(GL_TEXTURE_2D, this->effects);
	glTexCoordPointer(2, GL_FLOAT, 0, &effects);
	glTranslatef(-0.5, -3.7, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glPopMatrix();



	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPopMatrix();
}

bool Map::checkCollision(float x, float y, float sizeX,float sizeY)
{
	for (int i = 0; i < this->positions.size(); i++)
	{
		if (this->positions[i]->x == x + sizeX && this->positions[i]->y == y + sizeY)
		{
			return false;
		}
	}
	return true;
}
