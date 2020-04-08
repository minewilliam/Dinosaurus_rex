#include "header/controller.h"
//Joakim, utiliser les inputs de Qt.

Controller::Controller()
{
    resetPhoneme();
    etatTouche=Nothing;
}

Controller::~Controller()
{
    resetPhoneme();
}

int Controller::getEtat()
{
    return etatTouche;
}

void Controller::ReadPhoneme()
{
    if(_kbhit())
    {
        cin >> PhonemeActif;
        cin.clear();
        if(PhonemeActif=='s')
        {
            etatTouche=Duck;
        }
        if(PhonemeActif=='w')
        {
            etatTouche = Jump;
        }
    }

}
void Controller::resetPhoneme()
{
    PhonemeActif = 0;
    etatTouche = Nothing;
}

//regarde si il y a une touche qui a ete pesee au clavier
int Controller::_kbhit()
{
	return 0;
}