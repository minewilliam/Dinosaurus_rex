#include "header/dinosaurus.h"
#include "header/mainMenu.h"

DinosaurusApp::DinosaurusApp(int &argc, char** argv) : QApplication(argc, argv)
{
	_mainWindow = new QMainWindow();
	_leaderboard = new LeaderboardTable();
	// set up mainmenu
	MainMenuWidget* mainmenu = new MainMenuWidget();
	_mainWindow->setCentralWidget(mainmenu);
	
	connect(mainmenu->buttonPlay, SIGNAL(clicked()), this, SLOT(Play()));
	connect(mainmenu->buttonLeaderBoard, SIGNAL(clicked()), this, SLOT(ActivateLeaderBoard()));
	connect(mainmenu->buttonQuit, SIGNAL(clicked()), this, SLOT(Quit()));
	
	_mainWindow->setFixedSize(800, 600);
	_mainWindow->setStyleSheet("background-image:url(backgroundmainmenu1.png);");

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
	//setwindowtitle
	_mainWindow->setStyleSheet("background-image:url(backgroundControl.png);");
	_mainWindow->setCentralWidget(MyPregameSetUP);
	connect(MyPregameSetUP->Play, SIGNAL(clicked()), this, SLOT(SetUpGame()));
	connect(MyPregameSetUP->Cancel, SIGNAL(clicked()), this, SLOT(SetUpMenu()));
}
void DinosaurusApp::SetUpMenu() 
{
	delete _level;
	_level = nullptr;
	MainMenuWidget* mainmenu = new MainMenuWidget();
	_mainWindow->setCentralWidget(mainmenu);
	connect(mainmenu->buttonPlay, SIGNAL(clicked()), this, SLOT(Play()));
	connect(mainmenu->buttonLeaderBoard, SIGNAL(clicked()), this, SLOT(ActivateLeaderBoard()));
	connect(mainmenu->buttonQuit, SIGNAL(clicked()), this, SLOT(Quit()));
	_mainWindow->setStyleSheet("background-image:url(backgroundmainmenu1.png);");
}
void DinosaurusApp::SetUpGame() 
{
	_level = new Level();
	_mainWindow->setStyleSheet("background-image:url(background1.png);");
	_mainWindow->setCentralWidget(_level);
	connect(_level, SIGNAL(gameOver()), this, SLOT(SetUpMenu()));
}
void DinosaurusApp::ActivateLeaderBoard() 
{
	MonLeaderboard *newLeaderBoard = new MonLeaderboard();
	_mainWindow->setCentralWidget(newLeaderBoard);
}