#include "header/cloud.h"
#include "header/level.h"
#include <QTimer>

Cloud::Cloud()
{
	QTimer * timer = new QTimer();
	QPixmap imageCloud("assets/cloud.png");

	// connect timeout to move
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));
	timer->start(50);

	setPos(SCREEN_WIDTH, rand() % (SCREEN_HEIGHT / 4) + (SCREEN_HEIGHT / 8));
	setPixmap(imageCloud);
}

void Cloud::move()
{
	// move Cloud to the left
	setPos(x() - 5, y());

	//delete Cloud if it goes off screen
	if (pos().y() > SCREEN_HEIGHT) {
		scene()->removeItem(this);
		delete this;
	}
}