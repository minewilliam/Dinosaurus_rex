#include "header/terrain.h"

Terrain::Terrain()
{

}

Terrain::Terrain(Coord size, char* textureName)
{
    _sprite2D.size = size;
    _sprite2D.position = {0,0};
    _BackgroundTexture = Texture(textureName,{99,1});
}

Coord Terrain::getSize()
{
    return _sprite2D.size;
}

void Terrain::draw(char** buffer)
{
    Coord pos;
    
    for(pos.y = 0; pos.y < _sprite2D.size.y; pos.y++)
    {
        for(pos.x = 0; pos.x < _sprite2D.size.x; pos.x++)
        {
            //Scrolling
            int textureX = (pos.x+_BackgroundTexture.position.x)%_BackgroundTexture.size.x;
            //Vertical offset
            int levelY = (pos.y+_sprite2D.position.y-1);
            buffer[pos.x][levelY] = _BackgroundTexture.map[textureX][pos.y];
        }
    }
}

//Level-location transform.
void Terrain::setPos(Coord pos)
{
    _sprite2D.position = pos;
}

//Texture-location transform, enables scrolling.
void Terrain::transform(Coord pos)
{
    _BackgroundTexture.position += pos;
}