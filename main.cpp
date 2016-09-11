//=========================================
//
// Made by : Baron Leonardo
// E-mail  : mohamedayman.fcis@zoho.com
//
// This work is done under GPL licence
// to read Licence's terms read licence file
// wich indecates :
// ***the freedom to use the software for any purpose,
// ***the freedom to change the software to suit your needs,
// ***the freedom to share the software with your friends and neighbors, and
// ***the freedom to share the changes you make.
//
//=========================================

#include "newgamewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    NewGameWindow newGameWindow;
    newGameWindow.construct();

    return a.exec();
}
