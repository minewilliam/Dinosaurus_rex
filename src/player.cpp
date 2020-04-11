#include "header/player.h"

Player::Player(QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
	_jumpAnimTimer = new QTimer();
	setRect(0, 0, 50, height);
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
		duck();
	}
	else if (event->key() == Qt::Key_Space)
	{
		shoot();
	}
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

}

void Player::shoot()
{

}