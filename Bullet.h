#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsRectItem {
	Q_OBJECT
public:
	Bullet(int x, int y);
public slots:
	void move();
};

#endif // BULLET_H