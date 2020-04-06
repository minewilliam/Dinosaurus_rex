#include "header/level.h"

Level::Level()
{
    init();
}

Level::Level(Coord size)
{
    _size = size;

    _screenBuffer = new char*[_size.x];
    for(int i = 0; i < _size.x; i++)
    {
        _screenBuffer[i] = new char[_size.y];
    }

    for(int i = 0; i < _size.y; i++)
    {
        for(int j = 0; j < _size.x; j++)
        {
            _screenBuffer[j][i] = ' ';
        }
    }
    
    init();
    
}

Level::~Level()
{
    destroyBuffer();
}

void Level::init()
{
    _score = 0;
    _lastObstacle = 0;
    _terrain = Terrain({_size.x,1},(char*)("assets/groundTexture.txt"));
    _terrain.setPos({0,_size.y});
    _obstacle = new Obstacle(cactusTextures[0]);
    _obstacle->setPos({_size.x,_size.y-_obstacle->getSize().y+1});
    _player.setPos({10,_size.y-_player.getSize().y+1});
}

void Level::destroyBuffer()
{
    for(int i = 0; i < _size.y; i++)
    {
        delete[] _screenBuffer[i];
    }
    delete[] _screenBuffer;
}

void Level::setSize(Coord size)
{
    if(_size.x != 0 && _size.y != 0)
    {
        destroyBuffer();
    }

    _size = size;

    _screenBuffer = new char*[_size.x];
    for(int i = 0; i < _size.x; i++)
    {
        _screenBuffer[i] = new char[_size.y];
    }

    for(int i = 0; i < _size.y; i++)
    {
        for(int j = 0; j < _size.x; j++)
        {
            _screenBuffer[j][i] = ' ';
        }
    }

    _terrain.setPos({0,_size.y-1});
}

Coord Level::getSize()
{
    return _size;
}

void Level::start()
{
    _loop = true;
    run();
}

void Level::stop()
{
    _loop = false;
    char c;
    cin >> c;
    exit(0);
}

void Level::run()
{
    while(_loop)
    {
        draw();
        usleep(10000/(1+_score*LEVEL_ACCEL)); //Update for Qt
        _score++;
        transformTerrain({1,0});
    }
}

void Level::draw()
{
    bool alive = true;
    //Resets screen
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);

    //Draw terrain
    _terrain.draw(_screenBuffer);

    if(_obstacle->getSize().x+_obstacle->getPos().x < 0)
    {
        if(_obstacle->next != NULL)
        {
            _obstacle = _obstacle->next;
            delete _obstacle->previous;
        }
    }

    Obstacle* obstacleList = _obstacle;
    do
    {
        obstacleList->draw(_screenBuffer,_size);
    } while ((obstacleList = obstacleList->next) != NULL);

    alive = _player.draw(_screenBuffer,_size);

    if(_score-_lastObstacle > 60+30*(1+_score*LEVEL_ACCEL))
    {
        if((rand()%40) == 0)
        {
            _lastObstacle = _score-rand()%20;
            obstacleList = _obstacle;
            while(obstacleList->next != NULL) obstacleList = obstacleList->next;
            Obstacle* newObstacle = new Obstacle(randomCactus());
            if(newObstacle->isFlying())
            {
                newObstacle->setPos({_size.x,_size.y-newObstacle->getSize().y-5});
            }
            else
            {
                newObstacle->setPos({_size.x,_size.y-newObstacle->getSize().y+1});
            }
            
            obstacleList->addInPlace(newObstacle);
        }
    } 

    drawScore();

    //Top left corner
    Coord pos;
    for(pos.y = 0; pos.y < _size.y; pos.y++)
    {
        for(pos.x = 0; pos.x < _size.x; pos.x++)
        {
            cout << _screenBuffer[pos.x][pos.y];
            _screenBuffer[pos.x][pos.y] = ' ';
        }
        cout << endl;
    }

    if(!alive) stop();
}

void Level::transformTerrain(Coord v)
{
    _terrain.transform(v);

    Obstacle* obstacleList = _obstacle;
    do
    {
        obstacleList->transform({v.x,0});
    } while ((obstacleList = obstacleList->next) != NULL);
}

void Level::drawScore()
{
    char scoreCounter[16] = {" "}; 
    sprintf(scoreCounter, "Score: %d", _score);
    
    for(int i = 0; i < (int)sizeof(scoreCounter); i++)
    {
        _screenBuffer[_size.x-sizeof(scoreCounter)+i][1] = scoreCounter[i];
    }
}