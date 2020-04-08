#pragma once

#ifndef H_DINOSAURUS
#define H_DINOSAURUS
#include "level.h"
#include "controller.h"
#include <QApplication.h>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QLayout>

class DinosaurusApp : public QApplication
{
public:
	DinosaurusApp(int &argc, char** argv);
	~DinosaurusApp() {};
	QMainWindow& getMainWindow() { return *mainWindow; };
	void setMainWindow(QMainWindow& window) { mainWindow = new QMainWindow(mainWindow); };
private:
	QMainWindow* mainWindow = new QMainWindow();
	QLabel* scoreLabel = new QLabel("Score: ");
	QGraphicsScene* scene = new QGraphicsScene();
	QGraphicsView* view = new QGraphicsView(scene);

};

#endif // !H_DINOSAURUS