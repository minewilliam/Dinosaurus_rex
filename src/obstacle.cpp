#include "header/obstacle.h"
#include "header/player.h"
#include <QGraphicsScene>

Obstacle::Obstacle(int speed)
{
	_imageFile = "assets/Cactus1.png";
	_speed = speed;
 	setPixmap(_imageFile);
}

void Obstacle::move()
{
	//verify a collision between obstacle and player
	//list of colliding items
	QList<QGraphicsItem *> collidingObstacles = collidingItems();

	// if it's the player destroy player and remove obstacle from scene
	for (int i = 0, n = collidingObstacles.size(); i < n; ++i) {
		if (typeid(*(collidingObstacles[i])) == typeid(Player)) 
		{	
			//scene()->removeItem(collidingObstacles[i]);
			//scene()->removeItem(this);
	
			//delete collidingObstacles[i];
			playerCollision();
			return;
			
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