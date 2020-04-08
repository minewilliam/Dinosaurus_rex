#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "game2d.h"
#include <QGraphicsRectItem>

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
class Obstacle : public ListElement<Obstacle>, public QGraphicsRectItem
{
private:
	Texture _texture = cactusTextures[0];
public:
	Obstacle();
	Obstacle(Texture texture);
	~Obstacle();
};

#endif