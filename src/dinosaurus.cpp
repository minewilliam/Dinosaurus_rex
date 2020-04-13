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
	MyPregameSetUP = new PregameSetUP();
	//setwindowtitle
	_mainWindow->setStyleSheet("background-image:url(backgroundControl.png);");
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
	_mainWindow->setStyleSheet("background-image:url(backgroundmainmenu1.png);");
}
void DinosaurusApp::SetUpGame() 
{

	_level = new Level();
	_level->_name = MyPregameSetUP->username->text();
	_mainWindow->setStyleSheet("background-image:url(background1.png);");
	_mainWindow->setCentralWidget(_level);
	connect(_level, SIGNAL(gameOver()), this, SLOT(GameOverScreen()));
}
void DinosaurusApp::GameOverScreen()
{
	int finalscore = _level->getScore();
	QString playerName = _level->_name;
	QString tmp = QString::number(finalscore);
	delete _level;
	_level = nullptr;
	_mainWindow->setStyleSheet("background-image:url(assets/GameOverScreen.png)");
	MonGameOverScreen *MyGameOverScreen = new MonGameOverScreen();
	MyGameOverScreen->Score->setText(tmp);
	_mainWindow->setCentralWidget(MyGameOverScreen);
	connect(MyGameOverScreen->MainMenu, SIGNAL(clicked()), this, SLOT(SetUpMenu()));
	LeaderboardEntry newEntry;
	newEntry.score = finalscore;
	newEntry.name = playerName;
	_leaderboard->insert(newEntry);
	
}
void DinosaurusApp::ActivateLeaderBoard() 
{
	MonLeaderboard *lead = new	MonLeaderboard();
	lead->_theleaderboard = _leaderboard;
	lead->setLeaderboard();
	_mainWindow->setCentralWidget(lead);
	_mainWindow->setStyleSheet("background-image:url(assets/LeaderboardBackGround.png)");
	connect(lead->mainmenu, SIGNAL(clicked()), this, SLOT(SetUpMenu()));
}