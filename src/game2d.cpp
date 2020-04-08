#include "header/game2d.h"
//Changer texture load pour image Qt

Texture::Texture(char* name, Coord Size)
{
    _name = name;
    size = Size;

    if(size.x || size.y)
    {
        map = new char*[size.x];
        for(int i = 0; i < size.x; i++)
        {
            map[i] = new char[size.y];
        }

        for(int i = 0; i < size.x; i++)
            for(int j = 0; j < size.y; j++)
                map[i][j] = ' ';
        load();
    }
}

void Texture::load()
{
    if(size.y != 0 && size.x != 0)
    {
        ifstream ifs(_name);
        string c;
        Coord pos = {0,0};
    }
}