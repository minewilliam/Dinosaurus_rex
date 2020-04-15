#include "header/dinosaurus.h"
#include "header/mainMenu.h"

// Ici nous avons l'instanciation de la fenêtre principal 
DinosaurusApp::DinosaurusApp(int &argc, char** argv) : QApplication(argc, argv)
{
	_mainWindow = new QMainWindow();
	// set up menu principal
	setupMenu();
	_mainWindow->setFixedSize(800, 600);
	_mainWindow->setStyleSheet("background-image:url(backgroundmainmenu1.png)");

	_mainWindow->show();
	
	exec();
	
}

// Ce qui suit sont les différentes slots de DinosaurusApp elles permettent de changer entre les différents menu 
// chacune d'entre elle instancie proprement la classe nécessaire pour avoir l'affichage désirer et crée les
// connection nécessaire entre les boutons de la fenêtre et les slot 
// DinosaurusApp pour passer au affichage disponible
void DinosaurusApp::play()
{
	_preGameSetupWidget = new PreGameSetupWidget();
	connect(_preGameSetupWidget->Play, SIGNAL(clicked()), this, SLOT(setupGame()));
	connect(_preGameSetupWidget->Cancel, SIGNAL(clicked()), this, SLOT(setupMenu()));
	//setwindowtitle
	_mainWindow->setStyleSheet("background-image:url(backgroundControl.png)");
	_mainWindow->setCentralWidget(_preGameSetupWidget);
	
}

void DinosaurusApp::setupMenu()
{
	_mainMenuWidget = new MainMenuWidget();
	_mainWindow->setCentralWidget(_mainMenuWidget);
	_mainWindow->setStyleSheet("background-image:url(backgroundmainmenu1.png)");
	connect(_mainMenuWidget->buttonPlay, SIGNAL(clicked()), this, SLOT(play()));
	connect(_mainMenuWidget->buttonLeaderBoard, SIGNAL(clicked()), this, SLOT(activateLeaderBoard()));
	connect(_mainMenuWidget->buttonQuit, SIGNAL(clicked()), this, SLOT(quit()));

}

void DinosaurusApp::setupGame() 
{

	_level = new Level();
	_level->_name = _preGameSetupWidget->username->text();
	_mainWindow->setCentralWidget(_level);
	_mainWindow->setStyleSheet("background-image:url(background1.png)");
	connect(_level, SIGNAL(gameOver()), this, SLOT(activateGameOver()));
}

void DinosaurusApp::activateGameOver()
{
	_gameOverWidget = new GameOverWidget();
	_leaderBoardWidget = new Leaderboard();
	int finalscore = _level->getScore();
	QString playerName = _level->_name;
	QString tmp = QString::number(finalscore);
	delete _level;
	_level = nullptr;
	_mainWindow->setStyleSheet("background-image:url(assets/GameOverScreen.png)");
	_gameOverWidget->Score->setText(tmp);
	_mainWindow->setCentralWidget(_gameOverWidget);
	connect(_gameOverWidget->MainMenu, SIGNAL(clicked()), this, SLOT(setupMenu()));

	LeaderboardEntry newEntry;
	newEntry.score = finalscore;
	newEntry.name = playerName;
	_leaderBoardWidget->insert(newEntry);
	
}

void DinosaurusApp::activateLeaderBoard() 
{
	_leaderBoardWidget = new Leaderboard();
	_mainWindow->setCentralWidget(_leaderBoardWidget);
	_mainWindow->setStyleSheet("background-image:url(assets/LeaderboardBackGround.png)");
	connect(_leaderBoardWidget->_mainMenuButton, SIGNAL(clicked()), this, SLOT(setupMenu()));
}

void DinosaurusApp::quit()
{
	QCoreApplication::quit();
}