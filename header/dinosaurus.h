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

class DinosaurusApp : public QApplication
{
	Q_OBJECT
public:
	DinosaurusApp(int &argc, char** argv);
	~DinosaurusApp() {};
	QMainWindow& getMainWindow() { return *_mainWindow; };
public slots:
	void Play();
	void SetUpGame();
	void SetUpMenu();
	void Quit();
	void ActivateLeaderBoard();
private:
	QMainWindow* _mainWindow;
	Level* _level;
	LeaderboardTable* _leaderboard;
};

#endif // !H_DINOSAURUS