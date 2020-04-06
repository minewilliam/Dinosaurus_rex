#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "game2d.h"

Texture randomCactus();

Texture const cactusTextures[] {
	{(char*)"assets/cactusTexture.txt",{11,8}},
	{(char*)"assets/cactusTexture1.txt",{12,8}},
	{(char*)"assets/cactusTexture2.txt",{8,7}},
	{(char*)"assets/cactusTexture3.txt",{15,4}},
	{(char*)"assets/batTexture.txt",{15,4}}};

const int cactusTexturesAmount = sizeof(cactusTextures)/sizeof(Texture);

class Obstacle : public List<Obstacle>
{
private:
	Texture _texture = cactusTextures[0];
public:
	Obstacle();
	Obstacle(Texture texture);
	~Obstacle();

	bool isFlying();
	Coord getSize();
	Coord getPos();
	void addInPlace(Obstacle* obs);
	void setPos(Coord pos);
	void transform(Coord newposition);
	void draw(char** buffer, Coord bufferSize);
};

#endif