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

#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QToolBar>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include <QObject>

#include "board.h"
#include "timer.h"
#include "preference.h"

class ToolBar : public QWidget
{
    Q_OBJECT

public:
    explicit ToolBar( Board *board, int numOfMinesInBoard, QWidget *parent = 0 );
    Board *board;
    Timer *timer;

    QToolBar *toolBar;
    QWidget *toolBarWidget;
    QHBoxLayout *toolBarLayout;

    QLabel *numOfMinesLabel;
    QLabel *mineIconLabel;
    QSpacerItem *space1;
        QPushButton *logoButton;
        QPushButton *settingsButton;
        QPushButton *newGameButton;
    QSpacerItem *space2;
//    QLabel *timerLabel;
    QPushButton *timerButton;

    Preference *preferenceWindow;

    int numOfMinesInBoard;

public:
    void construct();

public slots:
    void timerChange( int );

public slots:
    void numOfMinesChanged( int );

};

#endif // TOOLBAR_H
