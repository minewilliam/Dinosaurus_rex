#include "header/dinosaurus.h"
#include "header/mainMenu.h"

DinosaurusApp::DinosaurusApp(int &argc, char** argv) : QApplication(argc, argv)
{
	_mainWindow = new QMainWindow();
	_level = new Level();
	// set up mainmenu
	MainMenuWidget* mainmenu = new MainMenuWidget();
	_mainWindow->setCentralWidget(mainmenu);
	connect(mainmenu->buttonPlay, SIGNAL(clicked()), this, SLOT(Play()));
	connect(mainmenu->buttonLeaderBoard, SIGNAL(clicked()), this, SLOT(ActivateLeaderBoard()));
	connect(mainmenu->buttonQuit, SIGNAL(clicked()), this, SLOT(Quit()));
	_mainWindow->setStyleSheet("background-image:url(background.png);");
	//_mainWindow->setFixedSize();
	//MainWindow setup:
	/*
	_mainWindow->menuBar()->addMenu("&Files");
	_mainWindow->setCentralWidget(_level);
	*/
	_mainWindow->show();
	
	exec();
	
}
void DinosaurusApp::Quit() 
{
	QCoreApplication::quit();
}
void DinosaurusApp::Play()
{
	PregameSetUP *MyPregameSetUP = new PregameSetUP();
	_mainWindow->setCentralWidget(MyPregameSetUP);
	connect(MyPregameSetUP->Play, SIGNAL(clicked()), this, SLOT(SetUpGame()));
	connect(MyPregameSetUP->Cancel, SIGNAL(clicked()), this, SLOT(SetUpMenu()));
}
void DinosaurusApp::SetUpMenu() 
{
	MainMenuWidget* mainmenu = new MainMenuWidget();
	_mainWindow->setCentralWidget(mainmenu);
	connect(mainmenu->buttonPlay, SIGNAL(clicked()), this, SLOT(Play()));
	connect(mainmenu->buttonLeaderBoard, SIGNAL(clicked()), this, SLOT(ActivateLeaderBoard()));
	connect(mainmenu->buttonQuit, SIGNAL(clicked()), this, SLOT(Quit()));
	_mainWindow->setStyleSheet("background-image:url(background.png);");
}
void DinosaurusApp::SetUpGame() 
{
	_mainWindow->menuBar()->addMenu("&Files");
	_mainWindow->setFixedSize(1000, 800);
	_mainWindow->setCentralWidget(_level);
}
void DinosaurusApp::ActivateLeaderBoard() 
{
	MonLeaderboard *newLeaderBoard = new MonLeaderboard();
	_mainWindow->setCentralWidget(newLeaderBoard);
}