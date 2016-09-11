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

NewGameWindow::NewGameWindow(QWidget *parent) :
    QMainWindow(parent)
{
}

void NewGameWindow::construct()
{
    mainWindow = new MainWindow;
    mainWindow->show();

    QObject::connect( mainWindow->newGame->toolBar->preferenceWindow->saveButton,
                        SIGNAL(clicked()), this, SLOT(closeAndRestartGame()) );
}

void NewGameWindow::closeAndRestartGame()
{
    if( mainWindow->newGame->toolBar->preferenceWindow->isSaveButtonClicked == true )
    {
        delete mainWindow;
        mainWindow = new MainWindow( this );
        mainWindow->show();

        QObject::connect( mainWindow->newGame->toolBar->preferenceWindow->saveButton,
                            SIGNAL(clicked()), this, SLOT(closeAndRestartGame()) );
    }
}
