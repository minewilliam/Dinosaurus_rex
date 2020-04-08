#include "header/player.h"

Player::Player()
{
    _playerThread = std::thread(run,this);
}

Player::~Player()
{

}

//Thread
void Player::run(Player *p)
{
    while(1)
    {
        int etatTemp = Nothing;

        p->_Controller.ReadPhoneme();
        etatTemp=p->_Controller.getEtat();
        p->_Controller.resetPhoneme();

        switch (etatTemp){
            case Nothing: 
                p->_texture = p->Player_Texture;
                Sleep(50000);
                break;
            case Jump: p->jump();
                break;
            case Duck: p->duck();
                break;
            case Quit: exit(0);
                break;
            default:
                break;
            }
    }
}

void Player::jump()
{
    int positionY = _texture.position.y;
    for(; _texture.position.y > positionY-MAX_JUMP_HEIGHT; --_texture.position.y)
    {
        float accel = (float)(_texture.position.y)/(positionY-MAX_JUMP_HEIGHT);
        std::this_thread::sleep_for(std::chrono::microseconds((int)(35000/accel)));
    }

    for(; _texture.position.y < positionY; ++_texture.position.y)
    {
        float accel = (float)(_texture.position.y)/(positionY)+0.15;
        std::this_thread::sleep_for(std::chrono::microseconds((int)(25000/accel)));
    }
}

void Player::duck()
{
    _texture = Player_Ducked;
    std::this_thread::sleep_for(std::chrono::microseconds(500000));
}

//Changer char** et coord par Qwindow&
bool Player::draw(char** buffer, Coord bufferSize)
{
    bool collisionFree = true;
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
                        if(buffer[pos.x-1][pos.y-1] != ' ' && pos.y != bufferSize.y) collisionFree = false;
                        buffer[pos.x-1][pos.y-1] = c;
                    }
                }
            }
        }
    }
    return collisionFree;
}

Coord Player::getSize()
{
    return _texture.size;
}

void Player::setPos(Coord pos)
{
    Player_Texture.position = pos;
    Player_Ducked.position = {pos.x, pos.y+(Player_Texture.size.y-Player_Ducked.size.y)};
}

Coord Player::getPos()
{
    return _texture.position;
}