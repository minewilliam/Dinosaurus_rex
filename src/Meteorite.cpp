#include "header/obstacle.h"
#include "header/level.h"
#include "header/Meteorite.h"
#include <fstream>
#include <iostream>
#include <string>

Meteorite::Meteorite(int speed)
{
	_speed = speed;
	init();
}
Meteorite::Meteorite(Texture texture, int speed)
{
	_speed = speed;
	_texture = texture;
	init();
}
void Meteorite::init()
{
	QPixmap imageCactus("Cactus1.png");
	setPixmap(imageCactus);
}
void Meteorite::move() 
{
	QList<QGraphicsItem *> collidingObstacles = collidingItems();

	// if it's the player destroy player and remove obstacle from scene
	for (int i = 0, n = collidingObstacles.size(); i < n; ++i) {
		if (typeid(*(collidingObstacles[i])) == typeid(Player)) {
			scene()->removeItem(collidingObstacles[i]);
			scene()->removeItem(this);

			delete collidingObstacles[i];
		}
	}
	setPos(x() - _speed, y()+ _speed*(0.57f));
}
void Meteorite::pushBack(Meteorite* element)
{
	Obstacle* lastObstacle = this;
	while (lastObstacle->next != nullptr) lastObstacle = lastObstacle->next;

	element->previous = lastObstacle;
	lastObstacle->next = element;
}