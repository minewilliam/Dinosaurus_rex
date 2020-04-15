#ifndef CLOUD_H
#define CLOUD_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Cloud : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Cloud();
public slots:
	void move();
};

#endif // CLOUD_H