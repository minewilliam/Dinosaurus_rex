#include "header/meteorite.h"
#include "header/player.h"
#include "header/level.h"
#include <QGraphicsScene>

void Meteorite::init()
{
	QPixmap imageCactus("assets/meteorite.png");
	setPos(SCREEN_WIDTH, (SCREEN_HEIGHT / 8));
	setPixmap(imageCactus);
}

void Meteorite::move() 
{
	QList<QGraphicsItem *> collidingObstacles = collidingItems();

	// if it's the player destroy player and remove obstacle from scene
	for (int i = 0, n = collidingObstacles.size(); i < n; ++i) {
		if (typeid(*(collidingObstacles[i])) == typeid(Player)) {
			playerCollision();
			//scene()->removeItem(collidingObstacles[i]);
			//scene()->removeItem(this);
			//delete collidingObstacles[i];
		}
	}
	setPos(x() - _speed, y()+ _speed*(0.57f));
}