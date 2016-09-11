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

#include "board.h"
#include <QDebug>
#include <QMessageBox>

Board::Board(int numOfRows, int numOfColumns, int numOfMines, QWidget *parent = 0 ) :
    QWidget( parent )
{
    this->numOfRowsInBoard = numOfRows;
    this->numOfColumnsInBoard = numOfColumns;
    this->numOfMinesInBoard = numOfMines;

    constructBoard();
}

void Board::constructBoard( /*const int numOfRowsInBoard, const int numOfColumnsInBoard */)
{
    boardWidget = new QWidget();
    boardLayout = new QGridLayout();
    boardLayout->setSpacing(0);

    isBlankSquare = false;
    isMineSquare = false;
    isFirstPressedButton = true;
    isEndOfGame = false;

    for( int row = 0; row < numOfRowsInBoard; ++row )
    {
        for( int column = 0; column < numOfColumnsInBoard; ++column )
        {
            temporaryColumnBoardSqaures.append( new QMouseClickButtons(this) );
            temporaryColumnBoardSqaures.at( column )->setFixedSize( 25, 25 );
            temporaryColumnBoardSqaures.at( column )->setStyleSheet( "background-color: #66BDE5;"
                                                "border-radius: 2;"
                                                "border-left: 1px solid white;"
                                                "border-top: 1px solid white;"
                                                "border-right: 1px solid grey;"
                                                "border-bottom: 1px solid grey;" );

                QObject::connect( temporaryColumnBoardSqaures.at( column ),
                                  SIGNAL( rightClicked( QMouseClickButtons* ) ),
                                  this,
                                  SLOT( onRightClicked(QMouseClickButtons*) ) );

                QObject::connect( temporaryColumnBoardSqaures.at( column ),
                                  SIGNAL( leftClicked( QMouseClickButtons* ) ),
                                  this,
                                  SLOT( onLeftClicked(QMouseClickButtons*) ) );

            boardLayout->addWidget( temporaryColumnBoardSqaures.at( column ), row, column );
        }

        boardSquares2dArrayList.append( temporaryColumnBoardSqaures );
        temporaryColumnBoardSqaures.clear();
    }

    boardWidget->setLayout( boardLayout );
}

void Board::continueConstructingBoard( QString firstClickedButtonIndex )
{
    mineSweeperConstruction =
            new MineSweeperConstruction( numOfRowsInBoard, numOfColumnsInBoard, numOfMinesInBoard, firstClickedButtonIndex, this );

    solvingMineSweeper = new SolvingMineSweeper
            ( mineSweeperConstruction->solvingOfBoard2DArray, &mineSweeperConstruction->indecesOfMines, this );

    connect( this, SIGNAL( onChangeOfNumOfMines(int) ), this, SLOT( winGame(int) ) );
}

void Board::onRightClicked( QMouseClickButtons *rightButton )
{
    int indexOfRow = boardLayout->indexOf( rightButton ) / numOfColumnsInBoard ;
    int indexOfColumn = boardLayout->indexOf( rightButton ) - ( numOfColumnsInBoard * indexOfRow );

    QString mineIndex = QString::number(indexOfRow) + ' ' + QString::number(indexOfColumn);

    if( !rightButton->isClicked && numOfMinesInBoard > 0 && !isFirstPressedButton && !isEndOfGame )
    {
        rightButton->setIcon( QIcon( ":/icons/flag" ) );

        rightButton->setIconSize( QSize( 17, 17 ) );

        --numOfMinesInBoard;

        flagIndeces.push_back( mineIndex );
        numOfMinesEmition( numOfMinesInBoard );

        rightButton->isClicked = true;
        rightButton->isRightClicked = true;
    }

    else if( rightButton->isRightClicked && numOfMinesInBoard >= 0 && !isEndOfGame )
    {
        rightButton->setIcon( QIcon() );

        ++numOfMinesInBoard;

        numOfMinesEmition( numOfMinesInBoard );

        rightButton->isClicked = false;
        rightButton->isRightClicked = false;

        std::vector<QString>::iterator it = flagIndeces.end() - 1;

        while( it != flagIndeces.begin() && flagIndeces.size() != 0 )
        {
            if( *it == mineIndex )
                flagIndeces.erase( it );

            else
                --it;
        }
    }
}

void Board::onLeftClicked(QMouseClickButtons *leftButton )
{
    QString styleSheet;

    if( !leftButton->isClicked /*&& !isendOfGame*/ )
    {
        int indexOfRow = boardLayout->indexOf( leftButton ) / numOfColumnsInBoard ;
        int indexOfColumn = boardLayout->indexOf( leftButton ) - ( numOfColumnsInBoard * indexOfRow );

        styleSheet = "background-color: #EEEFF2;"
                     "border-radius: 1;"
                     "font: bold 16pt;"
                     "border-left: 1px solid grey;"
                     "border-top: 1px solid grey;"
                     "border-right: 1px solid white;"
                     "border-bottom: 1px solid white;";

        if( isFirstPressedButton )
        {
            QString firstClickedButtonIndex = QString::number(indexOfRow) + ' ' + QString::number(indexOfColumn);

            leftButton->setStyleSheet( styleSheet );
            leftButton->setText( "" );

            leftButton->isClicked = true;
            isFirstPressedButton = false;

            continueConstructingBoard( firstClickedButtonIndex );
            flipUpBlankedSquares( leftButton, indexOfRow, indexOfColumn );

            startPlayingGame();

            return;
        }

        QString valueOfSquare = QString(
                    mineSweeperConstruction->solvingOfBoard2DArray->at( indexOfRow ).at( indexOfColumn ) );


        if( valueOfSquare == "*" )
        {
            if( isMineSquare == false )
            {

                isMineSquare = true;
                mineSquares();
                checkWrongFlagedSquares();

                isEndOfGame = true;

                emit gameLost();

                QMessageBox::warning( this, "OPS...", "<b>You Lost :(<\b>" );
            }

// This is done if after lost or win you want to explore the undercover squares
            else
            {
                styleSheet = "background-color: #EEEFF2;"
                             "border-radius: 1;"
                             "border: 2px dashed red;"
                             "font: 16pt;"
                             /*"border: 1px solid white;"*/;

                leftButton->setIcon( QIcon( ":/icons/small_mine" ) );
                leftButton->setIconSize( QSize( 17, 17 ) );

                leftButton->setStyleSheet( styleSheet );
                leftButton->isClicked = true;
            }
        }

        else
        {
            if( valueOfSquare == "0" )
            {
                valueOfSquare = "";

                if( isBlankSquare == false )
                {
                    isBlankSquare = true;
                    flipUpBlankedSquares( leftButton, indexOfRow, indexOfColumn );
                }
            }

            else if( valueOfSquare == "1")
            {
                styleSheet += "color: " + ONE_COLOR + ";";
            }

            else if( valueOfSquare == "2")
            {
                styleSheet += "color: " + TWO_COLOR + ";";
            }

            else if( valueOfSquare == "3")
            {
                styleSheet += "color: " + THREE_COLOR + ";";
            }

            else if( valueOfSquare == "4")
            {
                styleSheet += "color: " + FOUR_COLOR + ";";
            }

            else if( valueOfSquare == "5")
            {
                styleSheet += "color: " + FIVE_COLOR + ";";
            }

            else if( valueOfSquare == "6")
            {
                styleSheet += "color: " + SIX_COLOR + ";";
            }

            else if( valueOfSquare == "7")
            {
                styleSheet += "color: " + SEVEN_COLOR + ";";
            }

            else if( valueOfSquare == "8")
            {
                styleSheet += "color: " + EIGHT_COLOR + ";";
            }


            leftButton->setStyleSheet( styleSheet );
            leftButton->setText( valueOfSquare );
        }

        leftButton->isClicked = true;
    }
}

void Board::flipUpBlankedSquares( QMouseClickButtons* button, int indexOfRowOfButton, int indexOfColumnOfButton )
{

    QString valueOfSquare;

        for( int row = indexOfRowOfButton - 1; row <= indexOfRowOfButton + 1; ++row )
        {
            for( int column = indexOfColumnOfButton - 1; column <= indexOfColumnOfButton + 1; ++column  )
            {
                if( ( row < 0 || column < 0 ) ||
                        ( row >= numOfRowsInBoard || column >= numOfColumnsInBoard ) )
                {
                    continue;
                }

                else
                {
                    if( row != indexOfRowOfButton || column != indexOfColumnOfButton )
                    {
                        button = boardSquares2dArrayList.at( row ).at( column );

                        valueOfSquare = QString(
                                        mineSweeperConstruction->solvingOfBoard2DArray->
                                            at( row ).at( column ) );

                        if( valueOfSquare == "0" )
                        {
                            if( button->isClicked == false )
                            {
                                onLeftClicked( button );

                                flipUpBlankedSquares( button, row, column );
                            }
                        }

                        else if( valueOfSquare != "*" )
                        {
                            onLeftClicked( button );
                        }
                    }
                }
            }
        }

        isBlankSquare = false;
//    }
}

void Board::mineSquares()
{
    QString styleSheet = "background-color: #EEEFF2;"
                 "border-radius: 1;"
                 "border: 2px dashed red;"
                 "font: 16pt;";

    int indexOfRowHasMine = 0;
    int indexOfColumnHasMine = 0;

    QMouseClickButtons *mine;

    QStringList mineRowColumnIndex;


    for( QString indexOfMine : mineSweeperConstruction->indecesOfMines )
    {
        mineRowColumnIndex = ( indexOfMine.split( " " ) );

        indexOfRowHasMine = ( mineRowColumnIndex.at( 0 ) ).toInt();
        indexOfColumnHasMine = mineRowColumnIndex.at( 1 ).toInt();

        mine = boardSquares2dArrayList.at(indexOfRowHasMine).at(indexOfColumnHasMine);

        if( !mine->isClicked )
        {
            mine->isClicked = true;
            mine->setIconSize( QSize( 17, 17 ) );
            mine->setIcon( QIcon( ":/icons/small_mine" ) );
            mine->setStyleSheet( styleSheet );
        }
    }
}

void Board::checkWrongFlagedSquares()
{
    if( flagIndeces.size() != 0 )
    {
        QString styleSheet = "background-color: #EEEFF2;"
                     "border-radius: 1;"
                     "border: 2px dashed DarkRed;"
                     "font: 16pt;";

        int indexOfRowMayHasMine = 0;
        int indexOfColumnMayHasMine = 0;

        QStringList mayBeMineRowColumnIndex;

        QMouseClickButtons *wrongMine;

        for( QString IndexOfSquareMayHaveMine : flagIndeces )
        {

            mayBeMineRowColumnIndex = ( IndexOfSquareMayHaveMine.split( " " ) );

            indexOfRowMayHasMine = ( mayBeMineRowColumnIndex.at( 0 ) ).toInt();
            indexOfColumnMayHasMine = mayBeMineRowColumnIndex.at( 1 ).toInt();

            wrongMine = boardSquares2dArrayList.at( indexOfRowMayHasMine ).at( indexOfColumnMayHasMine );

            if( mineSweeperConstruction->solvingOfBoard2DArray->at( indexOfRowMayHasMine ).
                                     at( indexOfColumnMayHasMine ) != '*' )
            {
                wrongMine->setText( "" );
                wrongMine->setIcon( QIcon( ":/icons/wrong_mine" ) );
                wrongMine->setIconSize( QSize( 17, 17 ) );
                wrongMine->setStyleSheet( styleSheet );
            }
        }
    }
}

void Board::numOfMinesEmition( int numOfMines )
{
    emit onChangeOfNumOfMines( numOfMines );
}

void Board::winGame( int numOfMines )
{

    if( numOfMines == 0 )
    {
        int indexOfRowHasMine;
        int indexOfColumnHasMine;

        QStringList flagRowColumnIndex;

        for( QString flagIndex : flagIndeces )
        {
            flagRowColumnIndex = ( flagIndex.split( " " ) );

            indexOfRowHasMine = ( flagRowColumnIndex.at( 0 ) ).toInt();
            indexOfColumnHasMine = flagRowColumnIndex.at( 1 ).toInt();

            if ( solvingMineSweeper->solvingOfBoard2DArray->
                    at( indexOfRowHasMine ).at( indexOfColumnHasMine ) != '*' )
            {
                return;
            }

        }

        isEndOfGame = true;
        emit gameWon();

    }
}

void Board::startPlayingGame()
{
    emit onStartingPlayingGame();
}

Board::~Board()
{
    for( int iii = 0; iii < boardSquares2dArrayList.size(); ++iii )
    {
        for( int jjj = 0; jjj < boardSquares2dArrayList.at(iii).size(); ++jjj )
        {
            delete boardSquares2dArrayList.at(iii).at(jjj);
        }
    }

    if( !isFirstPressedButton )
    {
        delete mineSweeperConstruction;
        delete solvingMineSweeper;
    }

    flagIndeces.clear();

//    delete this;
}
