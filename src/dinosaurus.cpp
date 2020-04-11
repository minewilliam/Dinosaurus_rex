#include "header/dinosaurus.h"

DinosaurusApp::DinosaurusApp(int &argc, char** argv) : QApplication(argc, argv)
{
	_mainWindow = new QMainWindow();
	_level = new Level();
	_leaderboard = new Leaderboard();

	//MainWindow setup:
	_mainWindow->menuBar()->addMenu("&Files");
	_mainWindow->setCentralWidget(_level);
	_mainWindow->show();
	exec();
}