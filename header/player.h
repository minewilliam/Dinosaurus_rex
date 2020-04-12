#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_JUMP_REFRESHRATE 20 //20ms

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>

#include "game2d.h"
#define MAX_JUMP_HEIGHT 12

class Player : public QObject, public QGraphicsRectItem
{
	Q_OBJECT
public:
    Player(QGraphicsItem* parent = 0);

	void keyPressEvent(QKeyEvent* event);
	void setFloorHeight(int floorHeight) { _floorHeight = floorHeight; };
	int height = 100;

public slots:
    void jump();
    void duck();
    void shoot();

private:
	QTimer* _jumpAnimTimer;
	Texture Player_Texture = Texture((char*)"assets/playerTexture.txt", { 19,9 });
	Texture Player_Ducked = Texture((char*)"assets/playerDucked.txt", { 23,6 });
	Texture _texture = Player_Texture;
	int _floorHeight = 0;
	float _yVector = 0.0f;
	int _jumpFrameCount = 0;
	char* _name;
	const float _gravity = 1.0f;
	const float _jumpImpulse = 24.0f;
};

#endif