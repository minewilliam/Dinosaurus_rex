
#include "header/Bullet.h"
#include"header/obstacle.h"
#include "header/Meteorite.h"
#include"header/level.h"
#include <QTimer>

Bullet::Bullet(int x, int y) {
	// drew the rect
	//setRect(x, y, 50, 10);

	QPixmap imageBullet("fireball.png");
	//QPixmap playerSized = imagePlayer.scaled(width, height);
	setPos(x, y);
	setPixmap(imageBullet);

	// connect timeout to move
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

	timer->start(50);
}

void Bullet::move() {
	//verify a collision between bullet and obstacle
		//list of collinding items
	QList<QGraphicsItem *> collidingObstacles = collidingItems();

	// if it's an enemy remove both from scene but delete bullet
	for (int i = 0, n = collidingObstacles.size(); i < n; ++i) {
		if (typeid(*(collidingObstacles[i])) == typeid(Meteorite)) {
			scene()->removeItem(collidingObstacles[i]);
			scene()->removeItem(this);

			delete this;

			return;
		}
	}

	// move bullet to the right and to the ground
	setPos(x() + 10, y() + 1);

	//delete bullet if it goes off screen
	if (pos().y() > SCREEN_HEIGHT) {
		scene()->removeItem(this);
		delete this;
	}
}