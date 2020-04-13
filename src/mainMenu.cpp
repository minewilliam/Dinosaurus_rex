#include "header/mainMenu.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QtWidgets>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

/*************************************************************************************/
/*********************** Main application window for QSimulate ***********************/
/*************************************************************************************/

/************************************ constuctor *************************************/

MonLeaderboard::MonLeaderboard(QWidget *parent) : QWidget(parent)
{
	_leaderboard = new LeaderboardTable();

	layout = new QVBoxLayout();

	_leaderboard->setFixedSize(250, 300);

	Title = new QLabel();
	Title->setText("Leaderboard");
	QFont font;
	font.setPointSize(20);
	Title->setFont(font);

	mainMenuButton = new QPushButton("Main Menu");

	layout->addWidget(Title, 0, Qt::AlignCenter);
	layout->addWidget(_leaderboard, 0, Qt::AlignCenter);
	layout->addWidget(mainMenuButton, 0, Qt::AlignCenter);
	setLayout(layout);
}

PregameSetUP::PregameSetUP(QWidget *parent) : QWidget(parent)
{
	QLabel *EmptyLabel = new QLabel();
	EmptyLabel->setText("");
	username = new QLineEdit();
	username->setText("write username");
	
	Play = new QPushButton("play");
	Cancel = new QPushButton("cancel");
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
	font.setPointSize(20);
	ScoreLabel->setFont(font);
	Score = new QLabel();
	Score->setFont(font);
	QVBoxLayout * layout1 = new QVBoxLayout();
	QHBoxLayout * layout2 = new QHBoxLayout();
	QHBoxLayout * layout3 = new QHBoxLayout();
	QHBoxLayout * layout4 = new QHBoxLayout();
	MainMenu = new QPushButton("Main Menu");
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
MonGameOverScreen::~MonGameOverScreen()
{
	delete MainMenu;
	delete Score;
}

