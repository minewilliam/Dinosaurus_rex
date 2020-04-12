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
	QLabel *EmptyLabel = new QLabel();
	EmptyLabel->setText("");
	//set up play button
	buttonPlay = new QPushButton("Play");
	buttonPlay->setStyleSheet("background-color: red;");
	QFont font;
	font.setPointSize(14);
	buttonPlay->setFont(font);
	//set up leaderboard button
	buttonLeaderBoard = new QPushButton("Leaderboard");
	buttonLeaderBoard->setStyleSheet("background-color: red;");
	buttonLeaderBoard->setFont(font);
	// set up Quit button
	buttonQuit = new QPushButton("Quit");
	buttonQuit->setStyleSheet("background-color: red;");
	buttonQuit->setFont(font);
	buttonQuit->setFont(font);
	//
	const QSize MinButtonSize = QSize(4, 2);
	const QSize MaxButtonSize = QSize(200, 40);
	buttonPlay->setFixedSize(MaxButtonSize);
	buttonLeaderBoard->setFixedSize(MaxButtonSize);
	buttonQuit->setFixedSize(MaxButtonSize);
	QHBoxLayout *layout0 = new QHBoxLayout;
	QHBoxLayout *layout1 = new QHBoxLayout;
	QVBoxLayout *layout2 = new QVBoxLayout;
	QVBoxLayout *layout3 = new QVBoxLayout;
	layout2->addWidget(EmptyLabel,0,Qt::AlignLeft);
	layout2->addLayout(layout3);
	layout3->addWidget(buttonPlay, 0, Qt::AlignCenter);
	layout3->addWidget(buttonLeaderBoard, 0, Qt::AlignCenter);
	layout3->addWidget(buttonQuit, 0, Qt::AlignCenter);
	layout2->addWidget(EmptyLabel, 0, Qt::AlignCenter);
	setLayout(layout2);
	
}
