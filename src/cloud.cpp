#include "header/cloud.h"
#include"header/level.h"
#include <QTimer>


Cloud::Cloud() {
	// drew the rect
	//setRect(x, y, 50, 10);

	QPixmap imageCloud("assets/cloud.png");
	//QPixmap playerSized = imagePlayer.scaled(width, height);
	setPos(SCREEN_WIDTH, rand() % (SCREEN_HEIGHT / 4) + (SCREEN_HEIGHT / 8));
	setPixmap(imageCloud);

	// connect timeout to move
	QTimer * timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(move()));

	timer->start(50);
}

void Cloud::move() {
	

	// move Cloud to the left
	setPos(x() - 5, y());

	//delete Cloud if it goes off screen
	if (pos().y() > SCREEN_HEIGHT) {
		scene()->removeItem(this);
		delete this;
	}
}