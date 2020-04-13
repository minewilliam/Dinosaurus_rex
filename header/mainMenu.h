#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include "leaderboard.h"
#include <qlabel.h>

class MonLeaderboard : public QWidget
{
	Q_OBJECT
public:
	MonLeaderboard(QWidget *parent = 0);
	~MonLeaderboard();
	LeaderboardTable *_theleaderboard;
	void setLeaderboard();
	QPushButton *mainmenu;
	QLabel *Title;

};
class MonGameOverScreen :public QWidget
{
	Q_OBJECT
public:
	MonGameOverScreen(QWidget *parent = 0);
	~MonGameOverScreen();
	QPushButton *MainMenu;
	QLabel *Score;
};
class MainMenuWidget : public QWidget
{
	Q_OBJECT
public:
	MainMenuWidget(QWidget *parent = 0);
	//~MainMenuWidget();
	QGridLayout *layout;
	QPushButton *buttonPlay;
	QPushButton *buttonLeaderBoard;
	QPushButton *buttonQuit;
};

class PregameSetUP : public QWidget
{
	Q_OBJECT
public:
	PregameSetUP(QWidget *parent =0);
	//~PregameSetUP();
	QLineEdit *username;
	QPushButton * Play;
	QPushButton * Cancel;
};
#endif