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

#ifndef SOLVINGMINESWEEPER_H
#define SOLVINGMINESWEEPER_H

#include <QObject>
#include <vector>
#include <QString>

class SolvingMineSweeper : public QObject
{
    Q_OBJECT
public:
    explicit SolvingMineSweeper( std::vector< std::vector< char > > *solvingOfBoard2DArray,
                                 std::vector< QString > *indecesOfMines,
                                 QObject *);

    std::vector< std::vector< char > > *solvingOfBoard2DArray;
    std::vector< QString > *indecesOfMines;

    int numOfRowsInSolvedBoard;
    int numOfColumnsInEachRowInSolvedBoard;

public:
    void core();
    char boardSolving( int rowIndex, int columnIndex );

signals:

public slots:

};

#endif // SOLVINGMINESWEEPER_H
