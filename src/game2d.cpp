#include "header/game2d.h"

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
        while(getline(ifs, c))
        {
            for(pos.x = 0; pos.x < size.x && pos.x < (int)c.length(); pos.x++)
            {
                if(c[pos.x] == '\r') c[pos.x] = ' ';
                map[pos.x][pos.y] = c[pos.x];
            }
            pos.y++;

            // if(pos.x >= size.x)
            // {
            //     pos.x = 0;
            //     pos.y++;
            // }

            // if(pos.y <= size.y)
            // {
            //     map[pos.x][pos.y] = c[pos.x];
            // }
            // pos.x++;
        }
    }
}