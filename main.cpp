#include "Controlleur/Controlleur_hpp/MainControlleur.h"
#include <QApplication>
#include <QDebug>
//#include <string>
//#include <map>

int main(int argc, char *argv[])
{
    
    QApplication app(argc, argv);

    MainControlleur controlleur;
    controlleur.demarrerApplication();

    return app.exec();

}

