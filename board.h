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

#ifndef BOARD_H
#define BOARD_H

#include <QList>
#include <QWidget>
#include <QGridLayout>
#include <QString>

#include "qmouseclickbuttons.h"
#include "minesweeperconstruction.h"
#include "solvingminesweeper.h"


class Board : public QWidget
{

    Q_OBJECT

public:
    Board( int numOfRows, int numOfColumns, int numOfMines, QWidget * );
    ~Board();

public:
    int difficultyOfGame  = 0;

    const int CUSTOM = 0;
    const int BEGINNER = 1;
    const int INTERMEDIATE = 2;
    const int EXPERT = 3;

    QList< QList< QMouseClickButtons * > > boardSquares2dArrayList;
    QList<QMouseClickButtons *> temporaryColumnBoardSqaures;

    int numOfColumnsInBoard;
    int numOfRowsInBoard;
    int numOfMinesInBoard;

    QWidget *boardWidget;
    QGridLayout *boardLayout;
    MineSweeperConstruction *mineSweeperConstruction;
    SolvingMineSweeper *solvingMineSweeper;

    bool isBlankSquare;
    bool isMineSquare;
    bool isFirstPressedButton;
    bool isEndOfGame;

    std::vector<QString> flagIndeces;

public:
    const QString ONE_COLOR = "blue";
    const QString TWO_COLOR = "green";
    const QString THREE_COLOR = "red";
    const QString FOUR_COLOR = "DarkBlue";
    const QString FIVE_COLOR = "brown";
    const QString SIX_COLOR = "cyan";
    const QString SEVEN_COLOR = "black";
    const QString EIGHT_COLOR = "grey";

public:
    void constructBoard();
    void continueConstructingBoard( QString firstClickedButtonIndex );
    void numOfSquaresInBoard( int difficultyOfGame );
    void flipUpBlankedSquares( QMouseClickButtons *button, int indexOfRowOfButton, int indexOfColumnOfButton );
    void mineSquares();
    void checkWrongFlagedSquares();

public slots:
    void onRightClicked( QMouseClickButtons * );
    void onLeftClicked( QMouseClickButtons * );
    void winGame( int numOfMines );

protected:
    void numOfMinesEmition( int );
    void startPlayingGame();

signals:
    void onChangeOfNumOfMines( int );
    void onStartingPlayingGame();
    void gameWon();
    void gameLost();
};

#endif // BOARD_H
