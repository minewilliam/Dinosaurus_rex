#include "header/obstacle.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Texture randomCactus()
{
    return cactusTextures[rand()%(cactusTexturesAmount)];
}

Obstacle::Obstacle()
{

}

Obstacle::Obstacle(Texture texture)
{
    _texture = texture;
}

Obstacle::~Obstacle()
{

}