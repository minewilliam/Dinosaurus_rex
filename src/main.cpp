#include "header/dinosaurus.h"

int main(int argc, char** argv)
{
	srand(time(NULL));
	DinosaurusApp* Dino = new DinosaurusApp(argc, argv);

    return 0;
}