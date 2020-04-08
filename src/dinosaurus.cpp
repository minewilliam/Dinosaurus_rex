#include "header/dinosaurus.h"

DinosaurusApp::DinosaurusApp(int &argc, char** argv) : QApplication(argc, argv)
{
	mainWindow->menuBar()->addMenu("&Files");
	scene->addWidget(scoreLabel);
	mainWindow->setCentralWidget(view);
	mainWindow->show();

	exec();
}