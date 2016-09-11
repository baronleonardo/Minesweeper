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

#ifndef NEWGAME_H
#define NEWGAME_H

#include <QWidget>

#include "board.h"
#include "toolbar.h"
#include "newscore.h"
#include "impfiles.h"

class NewGame : public QWidget
{
    Q_OBJECT

public:
    Board *board = NULL;
    ToolBar *toolBar = NULL;

    const int CUSTOM = 0;
    const int BEGINNER = 1;
    const int INTERMEDIATE = 2;
    const int EXPERT = 3;

    int numOfColumnsInBoard;
    int numOfRowsInBoard;
    int numOfMinesInBoard;

    NewScore *newScore;
    ImpFiles *settingsFile;
public:
    explicit NewGame( QWidget *parent = 0 );
    void numOfSquaresInBoard( int difficultyOfGame );

signals:
    void removeBoardWidget();
    void addBoardWidget();

public slots:
    void newGame();
    void newGame( int numOfRows, int numOfColumns, int numOfMines );
    void loadSettings();
    void pauseAndResumeTimer(bool);

private slots:
    void onGameEnd();
};

#endif // NEWGAME_H
