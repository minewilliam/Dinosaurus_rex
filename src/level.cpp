#include "header/level.h"
#include <QFont>
//Se débarasser de screen buffer. Remplacer par une fonction d'affichage succéssive.
//Changer Usleep() par un Thread.sleep()

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent)
{
	setPlainText(QString("Score: ") + QString::number(_score));
	setDefaultTextColor(Qt::black);
	setFont(QFont("arial", 16));
}

Level::Level()
{
	_scene = new QGraphicsScene();
	_score = new Score();
	_player = new Player();

	_scene->addItem(_score);
	_scene->addItem(_player);
	_scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	setScene(_scene);
	setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    init();
}

Level::~Level()
{

}

void Level::init()
{

}

void Level::run()
{

}

void Level::draw()
{

}

void Level::transformTerrain(Coord v)
{
	
}