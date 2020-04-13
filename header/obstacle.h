#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "list.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>

class Obstacle : public QObject, public List<Obstacle>, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Obstacle(int speed = 0);
	void setSpeed(int speed) { _speed = speed; };
	void pushBack(Obstacle* element);
	int width = 50;
	int height = 100;

signals:
	void playerCollision();

public slots:
	void move();

protected:
	int _speed;
	QString _imageFile;
};
#endif