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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QTextStream>
#include <QFile>
#include <QApplication>

#include "newgame.h"
#include "impfiles.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWidget *constructionOfCentralWidget;
    QWidget *mainWidget;
    QGridLayout *mainLayout;

    NewGame *newGame;
    QObject object;
    ImpFiles *settingsFile;

    const int CUSTOM = 0;
    const int BEGINNER = 1;
    const int INTERMEDIATE = 2;
    const int EXPERT = 3;

public slots:
    void onRemovingBoardWidget();
    void onAddingBoardWidget();

private:
    void loadSettings();
    void createNewSettingsFile();

public:
    MainWindow(QWidget *parent = 0);
    void construct();
    ~MainWindow();
};

#endif // MAINWINDOW_H
