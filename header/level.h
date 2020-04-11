#ifndef LEVEL_H
#define LEVEL_H
#define OBSTACLE_DEFAULT_SPEED 19
#define OBSTACLE_SPAWN_TIME 2500
#define OBSTACLE_MIN_SPAWN_TIME 1000

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
	Q_OBJECT
public:
	Score(QGraphicsItem* parent = 0);

public slots:
	void incrementScore();

private:
	QTimer* _scoreCounter;
	int _score = 0;
};

class Level : public QGraphicsView
{
	Q_OBJECT
public:
    Level();
    ~Level();

public slots:
	void spawnObstacle();

private:
	QGraphicsScene* _scene;
	Score* _score;
    Player* _player;

	QTimer* _spawnRate;
	QTimer* _scrollSpeed;
	Obstacle* _obstacle = nullptr;

    //Terrain* _terrain;
};

#endif