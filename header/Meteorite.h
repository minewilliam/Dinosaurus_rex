#ifndef METEORITE_H
#define METEORITE_H

#include "header/game2d.h"
#include "header/list.h"
#include "header/obstacle.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Meteorite : public Obstacle
{
	Q_OBJECT
public:
	Meteorite(int speed = 0);
	Meteorite(Texture texture, int speed = 0);
	void setSpeed(int speed) { _speed = speed; };
	void pushBack(Meteorite* element);
	int width = 50;
	int height = 100;
public slots:
	void move();

private:
	void init();
	Texture _texture = cactusTextures[0];
	int _speed;
};
#endif