#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>

#include "game2d.h"
#define MAX_JUMP_HEIGHT 12

class Player : public QObject, public QGraphicsRectItem
{
public:
    Player(QGraphicsItem* parent = 0);

	void keyPressEvent(QKeyEvent* event);

	void spawn();

    void jump();
    void duck();
    void shoot();

private:
	Texture Player_Texture = Texture((char*)"assets/playerTexture.txt", { 19,9 });
	Texture Player_Ducked = Texture((char*)"assets/playerDucked.txt", { 23,6 });
	Texture _texture = Player_Texture;
};

#endif