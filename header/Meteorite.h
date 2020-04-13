#ifndef METEORITE_H
#define METEORITE_H

#include "header/obstacle.h"

class Meteorite : public Obstacle
{
	Q_OBJECT
public:
	Meteorite(int speed = 0) : Obstacle(speed) {};
public slots:
	void move();

protected:
	void init();
};
#endif