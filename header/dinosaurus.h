#ifndef H_DINOSAURUS
#define H_DINOSAURUS

#include "level.h"
#include "leaderboard.h"
#include <QApplication.h>
#include <QtWidgets>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QLayout>
#include <QObject>
#include <QString>
#include "mainMenu.h"

class DinosaurusApp : public QApplication
{
	Q_OBJECT
public:
	DinosaurusApp(int &argc, char** argv);
	~DinosaurusApp() {};
	QMainWindow& getMainWindow() { return *_mainWindow; };
	PregameSetUP *MyPregameSetUP;
public slots:
	void Play();
	void SetUpGame();
	void SetUpMenu();
	void Quit();
	void ActivateLeaderBoard();
	void GameOverScreen();
private:
	QMainWindow* _mainWindow;
	MonGameOverScreen* _myGameOverScreen;
	MainMenuWidget* _mainmenu;
	Level* _level;
	MonLeaderboard* _leaderBoardWidget;
};

#endif // !H_DINOSAURUS