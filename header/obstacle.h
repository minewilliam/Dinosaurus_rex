#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "game2d.h"
#include "list.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>

Texture randomCactus();

//Changer char** par image* dans Texture. et .txt par .png, .jpeg, .bitmap, etc.
//à voir, si Qt permet de connaitre les dimensions des images importées.
Texture const cactusTextures[] {
	{(char*)"assets/cactusTexture.txt",{11,8}},
	{(char*)"assets/cactusTexture1.txt",{12,8}},
	{(char*)"assets/cactusTexture2.txt",{8,7}},
	{(char*)"assets/cactusTexture3.txt",{15,4}},
	{(char*)"assets/batTexture.txt",{15,4}}};

const int cactusTexturesAmount = sizeof(cactusTextures)/sizeof(Texture);

//draw(char** ,Coord size) Changer char**. Probablement par une référence à la fenêtre Qt. draw(Qwindow& window)
class Obstacle : public QObject, public List<Obstacle>, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Obstacle(int speed = 0);
	Obstacle(Texture texture, int speed = 0);
	void setSpeed(int speed) { _speed = speed; };
	void pushBack(Obstacle* element);
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