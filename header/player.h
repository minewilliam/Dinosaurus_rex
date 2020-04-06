#ifndef PLAYER_H
#define PLAYER_H

#include <thread>
#include "game2d.h"
#include "controller.h"
#define MAX_JUMP_HEIGHT 12

class Player
{
    private:
    Texture Player_Texture = Texture((char*)"assets/playerTexture.txt",{19,9});
    Texture Player_Ducked = Texture((char*)"assets/playerDucked.txt",{23,6});
    Texture _texture = Player_Texture;
    thread _playerThread;
    Controller _Controller=Controller();

    public:
    Player();
    ~Player();

    static void run(Player *p);
    void jump();
    void duck();
    void shoot();

	Coord getSize();
    Coord getPos();
    void setPos(Coord pos);

    bool draw(char** buffer, Coord bufferSize);
};

#endif