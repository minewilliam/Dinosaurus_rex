#include "header/dinosaurus.h"
#include "header/mainMenu.h"

// Ici nous avons l'instanciation de la fenêtre principal 
DinosaurusApp::DinosaurusApp(int &argc, char** argv) : QApplication(argc, argv)
{
	_mainWindow = new QMainWindow();
	// set up menu principal
	SetUpMenu();
	_mainWindow->setFixedSize(800, 600);
	_mainWindow->setStyleSheet("background-image:url(backgroundmainmenu1.png)");

	_mainWindow->show();
	
	exec();
	
}
// Ce qui suit sont les différentes slot de DinosaurusApp elles permettent de changer entre les différents menu 
// chacune d'entre elle instancie proprement la classe nécessaire pour avoir l'affichage désirer et crée les connection nécessaire entre les boutons de la fenêtre et les slot 
//DinosaurusApp pour passer au affichage disponible
void DinosaurusApp::Quit() 
{
	QCoreApplication::quit();
}
void DinosaurusApp::Play()
{
	MyPregameSetUP = new PregameSetUP();
	connect(MyPregameSetUP->Play, SIGNAL(clicked()), this, SLOT(SetUpGame()));
	connect(MyPregameSetUP->Cancel, SIGNAL(clicked()), this, SLOT(SetUpMenu()));
	//setwindowtitle
	_mainWindow->setStyleSheet("background-image:url(backgroundControl.png)");
	_mainWindow->setCentralWidget(MyPregameSetUP);
	
}
void DinosaurusApp::SetUpMenu() 
{
	_mainmenu = new MainMenuWidget();
	connect(_mainmenu->buttonPlay, SIGNAL(clicked()), this, SLOT(Play()));
	connect(_mainmenu->buttonLeaderBoard, SIGNAL(clicked()), this, SLOT(ActivateLeaderBoard()));
	connect(_mainmenu->buttonQuit, SIGNAL(clicked()), this, SLOT(Quit()));

	_mainWindow->setCentralWidget(_mainmenu);
	
	_mainWindow->setStyleSheet("background-image:url(backgroundmainmenu1.png)");
}
void DinosaurusApp::SetUpGame() 
{

	_level = new Level();
	_level->_name = MyPregameSetUP->username->text();
	_mainWindow->setStyleSheet("background-image:url(background1.png)");
	_mainWindow->setCentralWidget(_level);
	connect(_level, SIGNAL(gameOver()), this, SLOT(GameOverScreen()));
}
void DinosaurusApp::GameOverScreen()
{
	_myGameOverScreen = new MonGameOverScreen();
	_leaderBoardWidget = new MonLeaderboard();
	int finalscore = _level->getScore();
	QString playerName = _level->_name;
	QString tmp = QString::number(finalscore);
	delete _level;
	_level = nullptr;
	_mainWindow->setStyleSheet("background-image:url(assets/GameOverScreen.png)");
	_myGameOverScreen->Score->setText(tmp);
	_mainWindow->setCentralWidget(_myGameOverScreen);
	connect(_myGameOverScreen->MainMenu, SIGNAL(clicked()), this, SLOT(SetUpMenu()));
	LeaderboardEntry newEntry;
	newEntry.score = finalscore;
	newEntry.name = playerName;
	_leaderBoardWidget->insert(newEntry);
	
}
void DinosaurusApp::ActivateLeaderBoard() 
{
	_leaderBoardWidget = new MonLeaderboard();
	_mainWindow->setCentralWidget(_leaderBoardWidget);
	_mainWindow->setStyleSheet("background-image:url(assets/LeaderboardBackGround.png)");
	connect(_leaderBoardWidget->mainMenuButton, SIGNAL(clicked()), this, SLOT(SetUpMenu()));
}