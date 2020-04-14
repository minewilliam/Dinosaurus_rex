#include "header/mainMenu.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QtWidgets>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>



/************************************ constuctor *************************************/
// Dans les constructeur suivant on voit le placement ainsi que l'instanciation des éléments nécessaire pour créé nos pages.
MonLeaderboard::MonLeaderboard(QWidget *parent) : QWidget(parent)
{
	_leaderboard = new LeaderboardTable();

	layout = new QVBoxLayout();

	_leaderboard->setFixedSize(250, 300);

	Title = new QLabel();
	Title->setText("");
	QFont font;
	font.setPointSize(24);
	Title->setFont(font);

	mainMenuButton = new QPushButton("Main Menu");
	
	font.setPointSize(14);
	mainMenuButton->setFont(font);
	mainMenuButton->setFixedSize(QSize(200, 40));
	mainMenuButton->setStyleSheet("background-color: red");
	layout->addWidget(Title, 0, Qt::AlignLeft);
	layout->addWidget(_leaderboard, 0, Qt::AlignCenter);
	layout->addWidget(mainMenuButton, 0, Qt::AlignCenter);
	setLayout(layout);
}

PregameSetUP::PregameSetUP(QWidget *parent) : QWidget(parent)
{
	QLabel *EmptyLabel = new QLabel();
	EmptyLabel->setText("");
	username = new QLineEdit();
	QFont font;
	font.setPointSize(14);
	username->setText("write username");
	username->setFont(font);
	username->setStyleSheet("background-color: red");
	username->setFixedSize(200, 50);
	
	Play = new QPushButton("Play");
	Play->setFont(font);
	Play->setStyleSheet("background-color: red");
	Play->setFixedSize(QSize(200, 40));
	Cancel = new QPushButton("Cancel");
	Cancel->setFont(font);
	Cancel->setStyleSheet("background-color: red");
	Cancel->setFixedSize(QSize(200, 40));
	QVBoxLayout * layout1 = new QVBoxLayout();
	QHBoxLayout * layout2 = new QHBoxLayout();
	layout1->addWidget(EmptyLabel, 0, Qt::AlignLeft);
	layout1->addWidget(EmptyLabel, 0, Qt::AlignLeft);
	layout1->addWidget(username, 0, Qt::AlignHCenter);
	layout2->addWidget(Play, 0, Qt::AlignBottom);
	layout2->addWidget(Cancel, 0, Qt::AlignBottom);
	layout1->addLayout(layout2);
	layout1->addWidget(EmptyLabel, 0, Qt::AlignLeft);
	setLayout(layout1);
}
MainMenuWidget::MainMenuWidget(QWidget *parent) : QWidget(parent)
{
	EmptyLabel = new QLabel();
	EmptyLabel->setText("");
	//set up play button
	buttonPlay = new QPushButton("Play");
	buttonPlay->setStyleSheet("background-color: red");
	QFont font;
	font.setPointSize(14);
	buttonPlay->setFont(font);
	//set up leaderboard button
	buttonLeaderBoard = new QPushButton("Leaderboard");
	buttonLeaderBoard->setStyleSheet("background-color: red");
	buttonLeaderBoard->setFont(font);
	// set up Quit button
	buttonQuit = new QPushButton("Quit");
	buttonQuit->setStyleSheet("background-color: red");
	buttonQuit->setFont(font);

	//
	buttonPlay->setFixedSize(QSize(200, 40));
	buttonQuit->setFixedSize(QSize(200, 40));
	buttonLeaderBoard->setFixedSize(QSize(200, 40));
	layout2 = new QVBoxLayout;

	layout3 = new QVBoxLayout;
	layout2->addWidget(EmptyLabel,0,Qt::AlignLeft);
	layout2->addLayout(layout3);
	layout3->addWidget(buttonPlay, 0, Qt::AlignCenter);
	layout3->addWidget(buttonLeaderBoard, 0, Qt::AlignCenter);
	layout3->addWidget(buttonQuit, 0, Qt::AlignCenter);
	layout2->addWidget(EmptyLabel, 0, Qt::AlignCenter);
	setLayout(layout2);
	
}
MonGameOverScreen::MonGameOverScreen(QWidget *parent) : QWidget(parent)
{
	QLabel *EmptyLabel = new QLabel();
	QLabel *ScoreLabel = new QLabel();
	ScoreLabel->setText("Your Score:");
	QFont font;
	font.setPointSize(14);
	ScoreLabel->setFont(font);
	Score = new QLabel();
	Score->setFont(font);
	QVBoxLayout * layout1 = new QVBoxLayout();
	QHBoxLayout * layout2 = new QHBoxLayout();
	QHBoxLayout * layout3 = new QHBoxLayout();
	QHBoxLayout * layout4 = new QHBoxLayout();
	MainMenu = new QPushButton("Main Menu");
	font.setPointSize(14);
	MainMenu->setFont(font);
	MainMenu->setFixedSize(QSize(200, 40));
	layout3->addWidget(EmptyLabel, 0, Qt::AlignLeft);
	layout2->addWidget(EmptyLabel, 0, Qt::AlignLeft);
	layout2->addWidget(EmptyLabel, 0, Qt::AlignLeft);
	layout2->addWidget(ScoreLabel, 0, Qt::AlignHCenter);
	layout2->addWidget(Score, 0, Qt::AlignHCenter);
	layout2->addWidget(EmptyLabel, 0, Qt::AlignLeft);
	layout2->addWidget(EmptyLabel, 0, Qt::AlignLeft);
	

	layout1->addLayout(layout3);
	layout1->addLayout(layout2);
	layout1->addWidget(MainMenu, 0, Qt::AlignCenter);

	setLayout(layout1);
}
/****************Destructor**************/
//ici nous avons les destructeurs des différentes classes

MonGameOverScreen::~MonGameOverScreen()
{
	delete MainMenu;
	delete Score;
}
/* il y a une erreur generer avec ces constructeurs
MonLeaderboard::~MonLeaderboard()
{
	delete _leaderboard;
	delete mainMenuButton;
	delete layout;
	delete Title;
}
MainMenuWidget::~MainMenuWidget()
{
	delete EmptyLabel;
	delete buttonPlay;
	delete buttonLeaderBoard;
	delete buttonQuit;
	delete layout2;
	delete layout3;
}
PregameSetUP::~PregameSetUP()
{
	delete username;
	delete Play;
	delete Cancel;
}
*/

