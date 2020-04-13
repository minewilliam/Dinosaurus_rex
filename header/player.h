#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_JUMP_REFRESHRATE 20 //20ms

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>

enum playerStateEnum{walking, ducking, jumping};

class Player : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
    Player(QGraphicsItem* parent = 0);
	
	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);

	void setFloorHeight(int floorHeight);
	int getHeight() { return _height; };

public slots:
    void jump();
    void duck();
    void shoot();
	void resize();
	void reloadGun();

private:
	playerStateEnum _state = walking;
	int _height;
	int _width;
	int _duckedHeight = 40;
	int _floorHeight = 0;
	int _yOrigin; //y coord based on floor height
	int _yOriginDucked; 
	int _jumpFrameCount = 0;
	float _yVector = 0.0f;
	bool _canFire = true;

	QTimer* _jumpAnimTimer;
	QTimer* _fireReloadTimer;
	QPixmap* _playerImage;
	QPixmap* _playerImageSized;
	const int _reloadTime = 200; //ms
	const float _gravity = 1.0f;
	const float _jumpImpulse = 24.0f;
};

#endif