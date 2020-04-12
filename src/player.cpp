#include "header/player.h"
#include "header/bullet.h"
#include"header/level.h"

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent)
{
	_jumpAnimTimer = new QTimer();

	//setRect(0, 0, width, height);
	QPixmap imagePlayer("assets/Dino.png");
	//QPixmap playerSized = imagePlayer.scaled(width, height);

	setPixmap(imagePlayer);
	

	connect(_jumpAnimTimer, SIGNAL(timeout()), this, SLOT(jump()));
	
}

void Player::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
	{
		_jumpAnimTimer->start(PLAYER_JUMP_REFRESHRATE);
	}
	else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
	{
		isDucked = true;
		duck();
	}
	
	else if (event->key() == Qt::Key_Space)
	{
		shoot();
	}
}

void Player::keyReleaseEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
		resize();
}


void Player::jump()
{
	if (y() == 500) //On the floor
	{
		_yVector = _jumpImpulse;
		_jumpFrameCount = 0;
	}

	if (y() > 500)
	{
		_yVector = 0;
		_jumpFrameCount = 0;
		setPos(x(), 500);
		_jumpAnimTimer->stop();
	}
	else
	{
		_yVector -= _gravity * _jumpFrameCount * PLAYER_JUMP_REFRESHRATE / 1000;
		setPos(x(), y() - _yVector);
		_jumpFrameCount += PLAYER_JUMP_REFRESHRATE / 2;
	}
}

void Player::duck()
{
	int xCoord = this->x();
	int yCoord = this->y();
	//this->setRect(0, 100-duckedHeight, width, duckedHeight);
	QPixmap imagePlayer("assets/Dino.png");
	QPixmap playerSized = imagePlayer.scaled(QSize(width, duckedHeight));

	setPos(x(),y()+(height-duckedHeight));


	this->setPixmap(playerSized);
	
}

void Player::shoot()
{
	int temp = 0;

	if (isDucked)
		temp = height - duckedHeight;

	Bullet * bullet = new Bullet(this->x() + width, this->y());
	scene()->addItem(bullet);
}

void Player::resize()
{
	//this->setRect(0, 0, width, height);
	QPixmap imagePlayer("assets/Dino.png");
	QPixmap playerSized = imagePlayer.scaled(QSize(width, height));


	setPos(x(), y() - (height - duckedHeight));

	this->setPixmap(playerSized);
	
	
	isDucked = false;

}
