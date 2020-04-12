#include "header/obstacle.h"
#include "header/player.h"
#include <QGraphicsScene>

Obstacle::Obstacle(int speed)
{
	_speed = speed;
	init();
}

void Obstacle::init()
{
	//setRect(0, 0, width, height);
	QPixmap imageCactus("assets/Cactus1.png");
	//QPixmap playerSized = imagePlayer.scaled(width, height);
	setPixmap(imageCactus);

}

void Obstacle::move()
{
	//verify a collision between obstacle and player
		//list of collinding items
	QList<QGraphicsItem *> collidingObstacles = collidingItems();

	// if it's the player destroy player and remove obstacle from scene
	for (int i = 0, n = collidingObstacles.size(); i < n; ++i) {
		if (typeid(*(collidingObstacles[i])) == typeid(Player)) {
			scene()->removeItem(collidingObstacles[i]);
			scene()->removeItem(this);

			delete collidingObstacles[i];
		}
	}
	setPos(x() - _speed, y());
}

void Obstacle::pushBack(Obstacle* element)
{
	Obstacle* lastObstacle = this;
	while (lastObstacle->next != nullptr) lastObstacle = lastObstacle->next;

	element->previous = lastObstacle;
	lastObstacle->next = element;
}