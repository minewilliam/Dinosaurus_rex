
#include "Bullet.h"
#include"header/obstacle.h"
#include"header/level.h"
#include <QTimer>

Bullet::Bullet(int x, int y) {
	// drew the rect
	setRect(x, y, 50, 10);

	// connect timeout to move
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

	timer->start(50);
}

void Bullet::move() {
	//verify a collision between bullet and obstacle
		//list of collinding items
	QList<QGraphicsItem *> collidingObstacles = collidingItems();

	// if it's an enemy destroy both
	for (int i = 0, n = collidingObstacles.size(); i < n; ++i) {
		if (typeid(*(collidingObstacles[i])) == typeid(Obstacle)) {
			scene()->removeItem(collidingObstacles[i]);
			scene()->removeItem(this);

			delete this;

			return;
		}
	}

	// move bullet to the right and to the ground
	setPos(x() + 10, y() + 1);
}