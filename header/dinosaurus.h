#ifndef H_DINOSAURUS
#define H_DINOSAURUS

#include "level.h"
#include <QApplication.h>
#include <QtWidgets>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QLayout>

class DinosaurusApp : public QApplication
{
public:
	DinosaurusApp(int &argc, char** argv);
	~DinosaurusApp() {};
	QMainWindow& getMainWindow() { return *_mainWindow; };
private:
	QMainWindow* _mainWindow;
	Level* _level;
};

#endif // !H_DINOSAURUS