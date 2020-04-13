#ifndef METEORITE_H
#define METEORITE_H

#include "header/obstacle.h"

class Meteorite : public Obstacle
{
	Q_OBJECT
public:
	Meteorite(int speed = 0);
public slots:
	void move();
};
#endif