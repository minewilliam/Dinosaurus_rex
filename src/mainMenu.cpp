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
	username = new QLineEdit();
	username->setText("write username");
	Play = new QPushButton("play");
	Cancel = new QPushButton("cancel");
	QVBoxLayout * layout1 = new QVBoxLayout();
	QHBoxLayout * layout2 = new QHBoxLayout();
	layout1->addWidget(username, 0, Qt::AlignHCenter);
	layout2->addWidget(Play, 0, Qt::AlignHCenter);
	layout2->addWidget(Cancel, 0, Qt::AlignHCenter);
	layout1->addLayout(layout2);
	setLayout(layout1);
}
MainMenuWidget::MainMenuWidget(QWidget *parent) : QWidget(parent)
{
	QSize MaxSize(400, 500);
	QSize MinSize(400, 400);
	QSize MaxSizeTitle(700, 200);
	QSize MinSizeTitle(635, 100);
	QSize MinSizeEmpty(900, 100);
	QSize MaxSizeEmpty(1000, 200);
	// set up main title
	QLabel *Title = new QLabel();
	QPixmap TitleImage("Title.png");
	Title->setPixmap(TitleImage);
	Title->setMinimumSize(MinSizeTitle);
	Title->setMaximumSize(MaxSizeTitle);
	//set up sun
	QLabel *sun = new QLabel();
	QPixmap SunImage("sun.png");
	sun->setPixmap(SunImage);
	sun->setMinimumSize(MinSize);
	sun->setMaximumSize(MaxSize);
	//set up nothing
	QLabel *background = new QLabel();
	QPixmap BackgroundImage("background.png");
	background->setPixmap(BackgroundImage);
	background->setMinimumSize(MinSizeTitle);
	background->setMaximumSize(MaxSizeTitle);
	// set up signature
	QLabel *label = new QLabel();
	QPixmap Signature("Signature.png");
	label->setPixmap(Signature);
	label->setMinimumSize(MinSizeEmpty);
	label->setMaximumSize(MaxSizeEmpty);
	// set up side pictures
	QLabel *RexImage = new QLabel();
	QLabel *ControlImage = new QLabel();
	QPixmap Rexpixmap("REX.png");
	QPixmap ControlPixmap("fourth control.png");
	RexImage->setPixmap(Rexpixmap);
	RexImage->setMinimumSize(MinSize);
	RexImage->setMaximumSize(MaxSize);
	ControlImage->setPixmap(ControlPixmap);
	ControlImage->setMinimumSize(MinSize);
	ControlImage->setMaximumSize(MaxSize);
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
	const QSize MaxButtonSize = QSize(300, 50);
	buttonPlay->setFixedSize(MaxButtonSize);
	buttonLeaderBoard->setFixedSize(MaxButtonSize);
	buttonQuit->setFixedSize(MaxButtonSize);
	QHBoxLayout *layout0 = new QHBoxLayout;
	QHBoxLayout *layout1 = new QHBoxLayout;
	QVBoxLayout *layout2 = new QVBoxLayout;
	QVBoxLayout *layout3 = new QVBoxLayout;
	layout0->addWidget(sun, 0, Qt::AlignHCenter);
	layout0->addWidget(Title, 0, Qt::AlignHCenter);
	layout0->addWidget(background, 0, Qt::AlignHCenter);
	layout2->addLayout(layout0);
	layout2->addLayout(layout1);
	layout2->addWidget(label, 0, Qt::AlignHCenter);
	layout1->addWidget(RexImage, 0, Qt::AlignHCenter);
	layout1->addLayout(layout3);
	layout3->addWidget(buttonPlay, 0, Qt::AlignCenter);
	layout3->addWidget(buttonLeaderBoard, 0, Qt::AlignCenter);
	layout3->addWidget(buttonQuit, 0, Qt::AlignCenter);
	layout1->addWidget(ControlImage, 0, Qt::AlignHCenter);
	setLayout(layout2);
}
