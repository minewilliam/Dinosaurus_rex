#include "header/dinosaurus.h"


int main(int argc, char** argv)
{
	DinosaurusApp* Dino = new DinosaurusApp(argc, argv);
	//QLayout* widgetLayout = new Q

    srand(time(NULL));
    Level level({150,25});
    //level.start();

    return 0;
}