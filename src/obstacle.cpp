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
    if(next != NULL)
    {
        if(previous != NULL)
        {
            next->previous = previous;
            previous->next = next;
        }
        else
        {
            next->previous = NULL;
        }
    }
}

bool Obstacle::isFlying()
{
    Texture t = cactusTextures[4];
    return (_texture.getName() == t.getName());
}

void Obstacle::addInPlace(Obstacle* obs)
{
    if(next != NULL)
    {
        next->previous = obs;
        obs->next = next;
    }

    obs->previous = this;
    next = obs;
}

//changer char** et coord par Qwindow&
void Obstacle::draw(char** buffer, Coord bufferSize)
{
    Coord pos;
    Coord tranformedPos = _texture.position+_texture.size;

    for(pos.y = _texture.position.y; pos.y < tranformedPos.y; pos.y++)
    {
        for(pos.x = _texture.position.x; pos.x < tranformedPos.x; pos.x++)
        {
            int textureX = pos.x-_texture.position.x;
            int textureY = pos.y-_texture.position.y;

            if(textureX >= 0 && textureY >= 0)
            {
                char c = _texture.map[textureX][textureY];

                if(c != ' ')
                {
                    if(pos.x <= bufferSize.x && pos.y <= bufferSize.y && pos.x > 0 && pos.y > 0)
                    {
                        buffer[pos.x-1][pos.y-1] = c;
                    }
                }
            }
        }
    }
}

Coord Obstacle::getSize()
{
    return _texture.size;
}

Coord Obstacle::getPos()
{
    return _texture.position;
}

void Obstacle::setPos(Coord pos)
{
    _texture.position = pos;
}

void Obstacle::transform(Coord newposition)
{
    _texture.position -= newposition;
}