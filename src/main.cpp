#include "header/level.h"
#include "header/controller.h"
#include <QtWidgets>

int main(int argc, char** argv)
{
    srand(time(NULL));
    Level level({150,25});
    level.start();
    return 0;
}

