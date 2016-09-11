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

#include "solvingminesweeper.h"


SolvingMineSweeper::SolvingMineSweeper( std::vector< std::vector< char > > *solvingOfBoard2DArray,
                                        std::vector< QString > *indecesOfMines,
                                        QObject *parent = 0 ) :
    QObject(parent)
{
    this->solvingOfBoard2DArray = solvingOfBoard2DArray;
    this->indecesOfMines = indecesOfMines;

    numOfRowsInSolvedBoard = solvingOfBoard2DArray->size();
    numOfColumnsInEachRowInSolvedBoard = solvingOfBoard2DArray->at(0).size();

    core();
}

void SolvingMineSweeper::core()
{
    for( unsigned int row = 0; row < solvingOfBoard2DArray->size(); ++row )
    {
        for( unsigned int column = 0; column < solvingOfBoard2DArray->at(row).size(); ++column )
        {
            if( solvingOfBoard2DArray->at(row).at(column) != '*' )
                solvingOfBoard2DArray->at(row).at(column) = boardSolving( row, column ) ;
        }
    }
}

char SolvingMineSweeper::boardSolving( int rowIndex, int columnIndex )
{
    int minesCounter = 0;

    for( int row = rowIndex - 1; row <= rowIndex + 1; ++row )
    {
        for( int column = columnIndex - 1; column <= columnIndex + 1; ++column )
        {
            if( ( row < 0 || column < 0 ) ||
                    ( row >= numOfRowsInSolvedBoard || column >= numOfColumnsInEachRowInSolvedBoard ) )
            {
                continue;
            }

            else
            {
                if( row != rowIndex || column != columnIndex )
                {
                    if( solvingOfBoard2DArray->at( row ).at( column ) == '*' )
                        ++minesCounter;
                }
            }
        }
    }

    return (char)( (int)'0' + minesCounter);
}
