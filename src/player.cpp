#include "header/player.h"

Player::Player(QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
	setRect(50, 520, 50, 100);
}

void Player::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Up)
	{
		jump();
	}
	else if (event->key() == Qt::Key_Down)
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

}

void Player::duck()
{

}

void Player::shoot()
{

}

void Player::spawn()
{

}