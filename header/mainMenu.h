#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>

class MonLeaderboard : public QWidget
{
	Q_OBJECT
public:
	MonLeaderboard(QWidget *parent = 0);
	//~MonLeaderboard();
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