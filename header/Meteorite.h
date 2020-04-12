#ifndef METEORITE_H
#define METEORITE_H

#include "header/obstacle.h"

class Meteorite : public Obstacle
{
	Q_OBJECT
public:
	Meteorite(int speed = 0);
	void setSpeed(int speed) { _speed = speed; };
	void pushBack(Meteorite* element);
	int width = 50;
	int height = 100;
public slots:
	void move();

private:
	void init();
	int _speed;
};
#endif