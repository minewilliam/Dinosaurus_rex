#include "header/meteorite.h"
#include "header/player.h"
#include <QGraphicsScene>

Meteorite::Meteorite(int speed)
{
	_imageFile = "assets/meteorite.png";
	_speed = speed;
	setPixmap(_imageFile);
}

void Meteorite::move() 
{
	//verify a collision between obstacle and player
	//list of colliding items
	QList<QGraphicsItem *> collidingObstacles = collidingItems();

	// if it's the player destroy player and remove obstacle from scene
	for (int i = 0, n = collidingObstacles.size(); i < n; ++i) {
		if (typeid(*(collidingObstacles[i])) == typeid(Player)) {
			playerCollision();
			return;
		}
	}
	setPos(x() - _speed, y()+ _speed*(0.57f));
}