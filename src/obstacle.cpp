#include "header/obstacle.h"
#include <fstream>
#include <iostream>
#include <string>

Texture randomCactus()
{
    return cactusTextures[rand()%(cactusTexturesAmount)];
}

Obstacle::Obstacle(int speed)
{
	_speed = speed;
	init();
}

Obstacle::Obstacle(Texture texture, int speed)
{
	_speed = speed;
    _texture = texture;
	init();
}

void Obstacle::init()
{
	setRect(0, 0, 50, 100);
}

void Obstacle::move()
{
	setPos(x() - _speed, y());
}

void Obstacle::pushBack(Obstacle* element)
{
	Obstacle* lastObstacle = this;
	while (lastObstacle->next != nullptr) lastObstacle = lastObstacle->next;

	element->previous = lastObstacle;
	lastObstacle->next = element;
}