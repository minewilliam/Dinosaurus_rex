#include "header/controller.h"

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
    //https://www.flipcode.com/archives/_kbhit_for_Linux.shtml source

    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN,FIONREAD, &bytesWaiting);
    return bytesWaiting;
}