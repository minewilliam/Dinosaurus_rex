#include "header/player.h"
#include "header/bullet.h"
#include"header/level.h"

Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent)
{
	_jumpAnimTimer = new QTimer();
	_fireReloadTimer = new QTimer();
	_playerImage = new QPixmap("assets/Dino.png");
	_height = _playerImage->height();
	_width = _playerImage->width();
	_playerImageSized = new QPixmap(_playerImage->scaled(QSize(_width, _duckedHeight)));

	connect(_jumpAnimTimer, SIGNAL(timeout()), this, SLOT(jump()));
	connect(_fireReloadTimer, SIGNAL(timeout()), this, SLOT(reloadGun()));

	_yOriginDucked = _yOrigin + _height - _duckedHeight;

	setPixmap(*_playerImage);
}

void Player::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Up || event->key() == Qt::Key_W)
	{
		if (_state == ducking)
		{
			resize();
		}
		_jumpAnimTimer->start(PLAYER_JUMP_REFRESHRATE);
	}
	else if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
	{
		if(_state == walking || _state == ducking)
		{
			duck();
		}
	}
	else if (event->key() == Qt::Key_Space)
	{
		shoot();
	}
}

void Player::keyReleaseEvent(QKeyEvent * event)
{
	if (event->key() == Qt::Key_Down || event->key() == Qt::Key_S)
	{
		if (_state == ducking)
		{
			resize();
		}
	}
}

void Player::setFloorHeight(int floorHeight)
{
	_floorHeight = floorHeight;
	_yOrigin = _floorHeight - _height;
	_yOriginDucked = _yOrigin + _height - _duckedHeight;
};

void Player::jump()
{
	if (_state != jumping) //Initialy on the floor
	{
		_state = jumping;
		_yVector = _jumpImpulse;
		_jumpFrameCount = 0;
	}

	//In the air
	_yVector -= _gravity * _jumpFrameCount * PLAYER_JUMP_REFRESHRATE / 1000;
	setPos(x(), y() - _yVector);
	_jumpFrameCount += PLAYER_JUMP_REFRESHRATE / 2;

	if (y() > _yOrigin) //Landed on the floor
	{
		_yVector = 0;
		_jumpFrameCount = 0;
		setPos(x(), _yOrigin);
		_jumpAnimTimer->stop();
		_state = walking;
	}
}

void Player::duck()
{
	setPos(x(), _yOriginDucked);
	this->setPixmap(*_playerImageSized);	
	_state = ducking;
}

void Player::shoot()
{
	if (_canFire)
	{
		scene()->addItem(new Bullet(x() + _width, y()));
		_canFire = false;
		_fireReloadTimer->start(_reloadTime);
	}
}

void Player::reloadGun()
{
	_canFire = true;
}

void Player::resize()
{
	setPos(x(), _yOrigin);
	this->setPixmap(*_playerImage);
	_state = walking;
}
