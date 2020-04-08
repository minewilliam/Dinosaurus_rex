#ifndef LEVEL_H
#define LEVEL_H
#define LEVEL_ACCEL 0.00002

#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include <QTimer>
#include "game2d.h"
#include "terrain.h"
#include "player.h"
#include "obstacle.h"

class Score : public QGraphicsTextItem
{
public:
	Score(QGraphicsItem* parent = 0);
	
	void addScore(int scoreadd = 1) { _score += scoreadd; };
	void resetScore(int scoreval = 0) { _score = scoreval; };
	int getScore() { return _score; };
private:
	int _score = 0;
};

class Level : public QGraphicsView
{
public:
    Level();
    ~Level();

	void run();

    void transformTerrain(Coord v);

private:
	QGraphicsScene* _scene;
	Score* _score;
    Obstacle* _obstacle;
    Player* _player;

    //Terrain* _terrain;
    int _lastObstacle;
    void draw();
    void init();
};

#endif