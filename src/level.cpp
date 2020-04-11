#include "header/level.h"
#include <QFont>
//Se débarasser de screen buffer. Remplacer par une fonction d'affichage succéssive.
//Changer Usleep() par un Thread.sleep()

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
	_scrollSpeed = new QTimer();

	_player->setFlag(QGraphicsItem::ItemIsFocusable);
	_player->setPos(50, SCREEN_HEIGHT - _player->height);

	connect(_spawnRate, SIGNAL(timeout()), this, SLOT(spawnObstacle()));
	_spawnRate->start(rand() % OBSTACLE_SPAWN_TIME + OBSTACLE_MIN_SPAWN_TIME);
	_scrollSpeed->start(OBSTACLE_DEFAULT_SPEED);

	_scene->addItem(_score);
	_scene->addItem(_player);
	_scene->setSceneRect(0, 0, SCREEN_WIDTH-2, SCREEN_HEIGHT-2);

	setScene(_scene);
	setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	_player->setFocus();
}

Level::~Level()
{

}

void Level::spawnObstacle()
{
	Obstacle* newObstacle = new Obstacle();
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
	newObstacle->setPos(SCREEN_WIDTH, SCREEN_HEIGHT-100);

	connect(_scrollSpeed, SIGNAL(timeout()), newObstacle, SLOT(move()));
	_scene->addItem(newObstacle);
	_spawnRate->setInterval(rand() % OBSTACLE_SPAWN_TIME + OBSTACLE_MIN_SPAWN_TIME);
}