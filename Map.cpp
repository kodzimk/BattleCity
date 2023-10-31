#include "Map.h"

Map::Map()
{
	ResourceManager manage;
	this->texture = manage.LoadFromFile("res/textures/map_8x8.png", 1);

	texCoord[0] = 0;
	texCoord[1] = 1;

	texCoord[2] = 1;
	texCoord[3] = 1;

	texCoord[4] = 1;
	texCoord[5] = 0;

	texCoord[6] = 0;
	texCoord[7] = 0;
}

Map::~Map()
{

}

void Map::render(float vertex[])
{
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->texture);
	glVertexPointer(2, GL_FLOAT, 0, vertex);
	glTexCoordPointer(2, GL_FLOAT, 0, &this->texCoord);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glBindTexture(GL_TEXTURE_2D, 0);
}
