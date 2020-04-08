#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

enum etats {Nothing, Jump, Duck, Quit};

class Controller
{
    private:
    int etatTouche;
    char PhonemeActif;
    public:
    Controller();
    ~Controller();

    void ReadPhoneme();
    void resetPhoneme();
    int getEtat();

    int _kbhit();
};
#endif