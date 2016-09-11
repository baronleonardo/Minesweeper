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

#ifndef MINESWEEPERCONSTRUCTION_H
#define MINESWEEPERCONSTRUCTION_H

#include <QObject>
#include <random>
#include <iostream>


class MineSweeperConstruction : public QObject
{
    Q_OBJECT

public:
    explicit MineSweeperConstruction( int numOfRowsInBoard, int numOfColumnsInBoard,
                                      int numOfMinesInBoard, QString firstClickedButtonIndex, QObject * );
    ~MineSweeperConstruction();

    std::random_device randomDevice;

    std::default_random_engine generator{ randomDevice() };

    int numOfColumnsInBoard;
    int numOfRowsInBoard;
    int numOfMinesInBoard;

    std::vector< std::vector<char> > *solvingOfBoard2DArray;
    std::vector< QString > indecesOfMines;

    QString firstClickedButtonIndex;

    int firstClickedRowIndex;
    int firstClickedColumnIndex;

public:

    void generateRandomNumersforRowsColumns();
    void generateRandomMines( int, int );
    void constructSolvedBoard2DArray( int, int );
    bool firstClickedSquare( int rowIndex, int columnIndex );

signals:

public slots:

};

#endif // MINESWEEPERCONSTRUCTION_H
