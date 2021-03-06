#include "header/level.h"
#include <QFont>
#include <QBrush>
#include <QImage>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
	setPlainText(QString("Score: ") + QString::number(_score));
	setDefaultTextColor(Qt::black);
	setFont(QFont("arial", 16));

	_scoreCounter = new QTimer();
	connect(_scoreCounter, SIGNAL(timeout()), this, SLOT(incrementScore()));
	_scoreCounter->start(50);
}

void Score::incrementScore()
{

	_score++;
	setPlainText(QString("Score: ") + QString::number(_score));
}

Level::Level()
{
	_scene = new QGraphicsScene();
	_score = new Score();
	_player = new Player();
	_spawnRate = new QTimer();
	_spawnCloud = new QTimer();
	_scrollSpeed = new QTimer();
	_spawnRateMeteorite = new QTimer();
	_player->setFlag(QGraphicsItem::ItemIsFocusable);
	_player->setPos(50, SCREEN_HEIGHT - _player->getHeight());
	_player->setFloorHeight(SCREEN_HEIGHT-2);

	connect(_spawnRate, SIGNAL(timeout()), this, SLOT(spawnObstacle()));
	_spawnRate->start(rand() % OBSTACLE_SPAWN_TIME + OBSTACLE_MIN_SPAWN_TIME);
	
	connect(_spawnRateMeteorite, SIGNAL(timeout()), this, SLOT(spawnMeteorite()));
	_spawnRateMeteorite->start(rand() % METEORITE_SPAWN_TIME + METEORITE_MIN_SPAWN_TIME);
	
	connect(_spawnCloud, SIGNAL(timeout()), this, SLOT(spawnCloud()));
	_spawnCloud->start(2000);

	_scrollSpeed->start(OBSTACLE_DEFAULT_SPEED);
	_scene->addItem(_score);
	_scene->addItem(_player);
	_scene->setSceneRect(0, 0, SCREEN_WIDTH-2, SCREEN_HEIGHT-2);

	//add a background
	setBackgroundBrush(QBrush(QImage("assets/background1.png")));

	setScene(_scene);
	setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	_player->setFocus();
}

Level::~Level()
{
	delete _score;
	delete _player;
	delete _obstacle;
	delete _meteorite;
	delete _spawnRate;
	delete _scrollSpeed;
	delete _spawnRateMeteorite;
	delete _spawnCloud;
}

void Level::spawnMeteorite()
{
	Meteorite* newMeteorite = new Meteorite();
	connect(newMeteorite, SIGNAL(playerCollision()), this, SLOT(checkCollision()));
	if (_meteorite == nullptr)
	{
		_meteorite = newMeteorite;
	}
	else
	{
		if (_meteorite->x() < 0)
		{
			delete _meteorite;
			_meteorite = newMeteorite;
		}
		else
		{
			_meteorite->pushBack(newMeteorite);
		}
	}

	newMeteorite->setSpeed(5);
	newMeteorite->setPos(SCREEN_WIDTH, rand() % (SCREEN_HEIGHT / 4));

	connect(_scrollSpeed, SIGNAL(timeout()), newMeteorite, SLOT(move()));
	_scene->addItem(newMeteorite);
	_spawnRateMeteorite->setInterval(rand() % METEORITE_SPAWN_TIME + METEORITE_MIN_SPAWN_TIME);
}
void Level::spawnCloud()
{
	Cloud * newCloud = new Cloud();
	scene()->addItem(newCloud);
}
void Level::spawnObstacle()
{
		Obstacle* newObstacle = new Obstacle();

		connect(newObstacle, SIGNAL(playerCollision()), this, SLOT(checkCollision()));
		
		if (_obstacle == nullptr)
		{
			_obstacle = newObstacle;
		}
		else
		{
			if (_obstacle->x() < 0)
			{
				delete _obstacle;
				_obstacle = newObstacle;
			}
			else
			{
				_obstacle->pushBack(newObstacle);
			}
		}
		

		newObstacle->setSpeed(5);
		newObstacle->setPos(SCREEN_WIDTH, SCREEN_HEIGHT - 100);
		connect(_scrollSpeed, SIGNAL(timeout()), newObstacle, SLOT(move()));
		_scene->addItem(newObstacle);
		_spawnRate->setInterval(rand() % OBSTACLE_SPAWN_TIME + OBSTACLE_MIN_SPAWN_TIME);
}

void Level::checkCollision()
{
	
	_spawnRateMeteorite->stop();
	_spawnRate->stop();
	_spawnCloud->stop();
	_scrollSpeed->stop();
	gameOver();
}