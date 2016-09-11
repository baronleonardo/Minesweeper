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

#include "minesweeperconstruction.h"
#include <QMessageBox>
#include <QTextStream>

MineSweeperConstruction::MineSweeperConstruction
    ( int numOfRowsInBoard, int numOfColumnsInBoard,
      int numOfMinesInBoard, QString firstClickedButtonIndex, QObject *parent ) :
        QObject( parent )
{
    this->numOfRowsInBoard = numOfRowsInBoard;
    this->numOfColumnsInBoard = numOfColumnsInBoard;
    this->numOfMinesInBoard = numOfMinesInBoard;
    this->firstClickedButtonIndex = firstClickedButtonIndex;

    generateRandomNumersforRowsColumns();
}

void MineSweeperConstruction::generateRandomNumersforRowsColumns()
{
    std::uniform_int_distribution<int> randomRowGeneration( 0, numOfRowsInBoard - 1 );
    std::uniform_int_distribution<int> randomColumnGeneration( 0, numOfColumnsInBoard - 1 );

    constructSolvedBoard2DArray( numOfRowsInBoard , numOfColumnsInBoard );

    int randomRowIndex;
    int randomColumnIndex;

    QString rowColumnIndeces;

    int minesCounter = 0;

    bool foundDublication = false;

    firstClickedRowIndex = ( firstClickedButtonIndex.left( firstClickedButtonIndex.indexOf( ' ' ) ) ).toInt();
    firstClickedColumnIndex = ( firstClickedButtonIndex.right( firstClickedButtonIndex.indexOf( ' ' ) ) ).toInt();


    while( minesCounter != numOfMinesInBoard )
    {
        randomRowIndex = randomRowGeneration( generator );
        randomColumnIndex = randomColumnGeneration( generator );

        rowColumnIndeces = QString::number(randomRowIndex) + ' ' + QString::number(randomColumnIndex);

        if( minesCounter != 0 )
        {
            if( firstClickedSquare( randomRowIndex, randomColumnIndex ) )
            {
                continue;
            }

            for( unsigned int iii = 0; iii < indecesOfMines.size(); ++iii )
            {

                if( rowColumnIndeces.compare( indecesOfMines.at( iii ) ) != 0  )
                {
                    continue;
                }

                else
                {
                    foundDublication = true;
                    break;
                }
            }
        }

        if( foundDublication )
        {
            foundDublication = false;
            continue;
        }

        generateRandomMines( randomRowIndex, randomColumnIndex );


        indecesOfMines.push_back( rowColumnIndeces );

        ++minesCounter;
    }
}

void MineSweeperConstruction::generateRandomMines( int indexOfRowInBoard, int indexOfColumnInBoard )
{
    solvingOfBoard2DArray->at( indexOfRowInBoard ).at( indexOfColumnInBoard ) = '*';
}

void MineSweeperConstruction::constructSolvedBoard2DArray(int numOfRows , int numOfColumns)
{
    solvingOfBoard2DArray = new
            std::vector< std::vector<char> >( numOfRows, std::vector<char>( numOfColumns ) );
}

bool MineSweeperConstruction::firstClickedSquare( int rowIndex, int columnIndex )
{
        for( int row = firstClickedRowIndex - 1; row <= firstClickedRowIndex + 1; ++row )
        {
            for( int column = firstClickedColumnIndex - 1; column <= firstClickedColumnIndex + 1; ++column )
            {
                if( row == rowIndex && column == columnIndex )
                {
                    return false;
                }
            }

            return false;
    }

    return true;
}

MineSweeperConstruction::~MineSweeperConstruction()
{
    indecesOfMines.clear();
}
