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

#ifndef NEWGAMEWINDOW_H
#define NEWGAMEWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

class NewGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow *mainWindow;

public:
    explicit NewGameWindow(QWidget *parent = 0);
    void construct();

signals:

public slots:
    void closeAndRestartGame();

};

#endif // NEWGAMEWINDOW_H
