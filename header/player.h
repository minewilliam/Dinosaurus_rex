#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_JUMP_REFRESHRATE 20 //20ms

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>

enum playerState{walking, ducking, jumping};

class Player : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
    Player(QGraphicsItem* parent = 0);
	
	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);
	void setFloorHeight(int floorHeight) { _floorHeight = floorHeight; };
	int height = 100;
	int duckedHeight = 40;
	int width = 50;
	bool isDucked = false;

public slots:
    void jump();
    void duck();
    void shoot();
	void resize();

private:
	int _floorHeight = 0;
	float _yVector = 0.0f;
	int _jumpFrameCount = 0;

	const float _gravity = 1.0f;
	const float _jumpImpulse = 24.0f;
	QTimer* _jumpAnimTimer;
};

#endif