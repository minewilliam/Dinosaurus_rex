#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include "leaderboard.h"
#include <qlabel.h>
// Ici sont présenté les différente class pour construire nos menu
//MonLeaderboard est la classe qui permet de créer la page d'affichage du tableau de pointage
class MonLeaderboard : public QWidget
{
	Q_OBJECT
public:
	
	MonLeaderboard(QWidget *parent = 0);
	~MonLeaderboard();
	void insert(LeaderboardEntry entry) { _leaderboard->insert(entry); };

	LeaderboardTable* _leaderboard;
	QPushButton *mainMenuButton;
	QVBoxLayout *layout;
	QLabel *Title;

};
// MonGameOverScreen est la classe qui permet de créer la page d'affichage de fin de partie
class MonGameOverScreen :public QWidget
{
	Q_OBJECT
public:

	MonGameOverScreen(QWidget *parent = 0);
	
	~MonGameOverScreen();

	QPushButton *MainMenu;
	QLabel *Score;
};
//MainMenuWidget est la classe qui permet de créer l'affichage du menu principal
class MainMenuWidget : public QWidget
{
	Q_OBJECT
public:
	MainMenuWidget(QWidget *parent = 0);
	~MainMenuWidget();

	QLabel *EmptyLabel;
	QPushButton *buttonPlay;
	QPushButton *buttonLeaderBoard;
	QPushButton *buttonQuit;
private:	
	QVBoxLayout *layout2;
	QVBoxLayout *layout3;
};
// PregameSetUP est la classe qui permet de créer l'affichage du pré-jeu
class PregameSetUP : public QWidget
{
	Q_OBJECT
public:
	PregameSetUP(QWidget *parent =0);
	~PregameSetUp();
	QLineEdit *username;
	QPushButton * Play;
	QPushButton * Cancel;
};
#endif