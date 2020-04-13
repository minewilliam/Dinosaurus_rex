#ifndef LEVEL_H
#define LEVEL_H

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

#define OBSTACLE_DEFAULT_SPEED 19
#define OBSTACLE_SPAWN_TIME 2500
#define OBSTACLE_MIN_SPAWN_TIME 1000
#define METEORITE_SPAWN_TIME 4000
#define METEORITE_MIN_SPAWN_TIME 2000

#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtWidgets>
#include <QTimer>
#include "player.h"
#include "obstacle.h"
#include "meteorite.h"
#include "cloud.h"

class Score : public QGraphicsTextItem
{
	Q_OBJECT
public:
	Score(QGraphicsItem* parent = 0);
	int getScore() { return _score; };
	void stop() { _scoreCounter->stop(); };

public slots:
	void incrementScore();

private:
	int _score = 0;
	QTimer* _scoreCounter;
};

class Level : public QGraphicsView
{
	Q_OBJECT
public:
    Level();
    ~Level();
	QGraphicsScene* _scene;
	int getScore() { return _score->getScore(); };

signals:
	void gameOver();

public slots:
	void spawnObstacle();
	void spawnMeteorite();
	void checkCollision();
	void spawnCloud();

private:
	Score* _score;
    Player* _player;
	Obstacle* _obstacle = nullptr;
	Meteorite* _Meteorite = nullptr;

	QTimer* _spawnRate;
	QTimer* _scrollSpeed;
	QTimer* _spawnRateMeteorite;
	QTimer* _spawnCloud;
};

#endif