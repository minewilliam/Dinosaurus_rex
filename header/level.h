#ifndef LEVEL_H
#define LEVEL_H
#define LEVEL_ACCEL 0.00002

#include "game2d.h"
#include "terrain.h"
#include "player.h"
#include "obstacle.h"

class Level
{
    public:
    Level();
    Level(Coord size);
    ~Level();

    void start();
    void stop();
    void setSize(Coord size);
    Coord getSize();

    void transformTerrain(Coord v);

    private:
    Obstacle* _obstacle;
    Player _player;
    Terrain _terrain;
    Coord _size;
    int _score;
    int _lastObstacle;
    char** _screenBuffer;
    bool _loop;
    void run();
    void draw();
    void init();
    void destroyBuffer();
    void drawScore();
};

#endif