#ifndef TERRAIN_H
#define TERRAIN_H

#include <QObject>
#include "game2d.h"

class Terrain : public QObject
{
public:
    Terrain();
    Terrain(Coord size, char* textureName);
    ~Terrain() {}

    Coord getSize();
    void transform(Coord v);
    void draw(char** stream);
    void setPos(Coord pos);

private:
    Texture _BackgroundTexture = Texture((char*)" ",{0,0});
    Sprite2D _sprite2D;
};

#endif