#ifndef MAINMENU_H
#define MAINMENU_H

#include "leaderboard.h"
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

// Ici sont pr�sent� les diff�rente classes pour construire nos menus

// GameOverWidget est la classe qui permet de cr�er la page d'affichage de fin de partie
class GameOverWidget :public QWidget
{
	Q_OBJECT
public:
	GameOverWidget(QWidget *parent = 0);

	QPushButton *MainMenu;
	QLabel *Score;
};

//MainMenuWidget est la classe qui permet de cr�er l'affichage du menu principal
class MainMenuWidget : public QWidget
{
	Q_OBJECT
public:
	MainMenuWidget(QWidget *parent = 0);

	QLabel *EmptyLabel;
	QPushButton *buttonPlay;
	QPushButton *buttonLeaderBoard;
	QPushButton *buttonQuit;
private:	
	QVBoxLayout *layout2;
	QVBoxLayout *layout3;
};

// PregameSetUP est la classe qui permet de cr�er l'affichage du pr�-jeu
class PreGameSetupWidget : public QWidget
{
	Q_OBJECT
public:
	PreGameSetupWidget(QWidget *parent =0);
	
	QLineEdit *username;
	QPushButton * Play;
	QPushButton * Cancel;
};
#endif