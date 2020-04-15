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
	QMainWindow& getMainWindow() { return *_mainWindow; };

public slots:
	void play();
	void setupGame();
	void setupMenu();
	void quit();
	void activateLeaderBoard();
	void activateGameOver();

private:
	Level* _level;
	QMainWindow* _mainWindow;
	PreGameSetupWidget* _preGameSetupWidget;
	GameOverWidget* _gameOverWidget;
	MainMenuWidget* _mainMenuWidget;
	Leaderboard* _leaderBoardWidget;
};

#endif // !H_DINOSAURUS