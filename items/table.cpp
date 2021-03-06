#include "table.h"
#include "window.h"

#include <qgl.h>
#include <QPoint>

Table::Table(float x, float y, float z, float r, float l, float w, float h, const Texture &t) : Item (x, y, z, r) , length(l), texture(t), height(h), collisionMatrix(), width(w)
{
	collisionMatrix.rotate(-r);
	collisionMatrix.translate(-x, -z);
}

Table::~Table()
{
}

void Table::generateList()
{
	glBindTexture(GL_TEXTURE_2D, texture.texture);
	glBegin(GL_QUADS);

		// Top Edge
		quickpoint(0.0f, height, 0.0f);
		quickpoint(0.0f, height, -width);
		quickpoint(length, height, -width);
		quickpoint(length, height, 0.0f);

		quickpoint(0.0f, height - 0.2f, 0.0f);
		quickpoint(0.0f, height - 0.2f, -width);
		quickpoint(length, height - 0.2f, -width);
		quickpoint(length, height - 0.2f, 0.0f);
		

		//Sides covering the top two edges of the table
		quickpoint(0.0f, height, 0.0f);
		quickpoint(0.0f, height - 0.2f, 0.0f);
		quickpoint(length, height - 0.2f, 0.0f);
		quickpoint(length, height, 0.0f);

		quickpoint(0.0f, height, 0.0f);
		quickpoint(0.0f, height - 0.2f, 0.0f);
		quickpoint(0.0f, height -0.2f, -width);
		quickpoint(0.0f, height, -width);

		quickpoint(0.0f, height, -width);
		quickpoint(0.0f, height - 0.2f, -width);
		quickpoint(length, height, -width);
		quickpoint(length, height - 0.2f, -width);

		quickpoint(length, height, -width);
		quickpoint(length, height - 0.2f, -width);
		quickpoint(length, height, 0.0f);
		quickpoint(length, height - 0.2f, 0.0f);
		
		//Leg 1
		quickpoint(0.0f, height - 0.2f, 0.0f);
		quickpoint(0.0f, 0.0f, 0.0f);
		quickpoint(0.2f, 0.0f, 0.0f);
		quickpoint(0.2f, height - 0.2f, 0.0f);

		quickpoint(0.0f, height - 0.2f, 0.0f);
		quickpoint(0.0f, 0.0f, 0.0f);
		quickpoint(0.0f, 0.0f, -0.2f);
		quickpoint(0.0f, height - 0.2f, -0.2f);

		quickpoint(0.0f, height - 0.2f, -0.2f);
		quickpoint(0.0f, 0.0f, -0.2f);
		quickpoint(0.2f, 0.0f, -0.2f);
		quickpoint(0.2f, height - 0.2f, -0.2f);

		quickpoint(0.2f, height - 0.2f, -0.2f);
		quickpoint(0.2f, 0.0f, -0.2f);
		quickpoint(0.2f, 0.0f, 0.0f);
		quickpoint(0.2f, height - 0.2f, 0.0f);
		
		//Leg 2
		quickpoint(0.0f, height - 0.2f, -width + 0.2f);
		quickpoint(0.0f, 0.0f, -width + 0.2f);
		quickpoint(0.2f, 0.0f, -width + 0.2f);
		quickpoint(0.2f, height - 0.2f, -width + 0.2f);

		quickpoint(0.0f, height - 0.2f, -width + 0.2f);
		quickpoint(0.0f, 0.0f, -width + 0.2f);
		quickpoint(0.0f, 0.0f, -width);
		quickpoint(0.0f, height - 0.2f, -width);

		quickpoint(0.0f, height - 0.2f, -width);
		quickpoint(0.0f, 0.0f, -width);
		quickpoint(0.2f, 0.0f, -width);
		quickpoint(0.2f, height - 0.2f, -width);

		quickpoint(0.2f, height - 0.2f, -width);
		quickpoint(0.2f, 0.0f, -width);
		quickpoint(0.2f, 0.0f, -width + 0.2f);
		quickpoint(0.2f, height - 0.2f, -width + 0.2f);

		//Leg 3
		quickpoint(length - 0.2f, height - 0.2f, -width + 0.2f);
		quickpoint(length - 0.2f, 0.0f, -width + 0.2f);
		quickpoint(length, 0.0f, -width + 0.2f);
		quickpoint(length, height - 0.2f, -width + 0.2f);

		quickpoint(length - 0.2f, height - 0.2f, -width + 0.2f);
		quickpoint(length - 0.2f, 0.0f, -width + 0.2f);
		quickpoint(length - 0.2f, 0.0f, -width);
		quickpoint(length - 0.2f, height - 0.2f, -width);

		quickpoint(length - 0.2f, height - 0.2f, -width);
		quickpoint(length - 0.2f, 0.0f, -width);
		quickpoint(length, 0.0f, -width);
		quickpoint(length, height - 0.2f, -width);

		quickpoint(length, height - 0.2f, -width);
		quickpoint(length, 0.0f, -width);
		quickpoint(length, 0.0f, -width + 0.2f);
		quickpoint(length, height - 0.2f, -width + 0.2f);

		//Leg 4
		quickpoint(length - 0.2f, height - 0.2f, 0.0f);
		quickpoint(length - 0.2f, 0.0f, 0.0f);
		quickpoint(length, 0.0f, 0.0f);
		quickpoint(length, height - 0.2f, 0.0f);

		quickpoint(length - 0.2f, height - 0.2f, 0.0f);
		quickpoint(length - 0.2f, 0.0f, 0.0f);
		quickpoint(length - 0.2f, 0.0f, -0.2f);
		quickpoint(length - 0.2f, height - 0.2f, -0.2f);

		quickpoint(length - 0.2f, height - 0.2f, -0.2f);
		quickpoint(length - 0.2f, 0.0f, -0.2f);
		quickpoint(length, 0.0f, -0.2f);
		quickpoint(length, height - 0.2f, -0.2f);

		quickpoint(length, height - 0.2f, -0.2f);
		quickpoint(length, 0.0f, -0.2f);
		quickpoint(length, 0.0f, 0.0f);
		quickpoint(length, height - 0.2f, 0.0f);

	glEnd();
}

bool Table::isCollision(float x, float y, float z)
{
	if (y < posy || y > posy + height)
		return false;

	qreal newx, newz;

	collisionMatrix.map(x, z, &newx, &newz);

	if (newx >= -1.0 && newx <= length + 1.0 && newz >= -1.0 && newz <= width + 1.0)
		return true;
	return false;
}
