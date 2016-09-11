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

#include "newgame.h"

NewGame::NewGame(QWidget *parent) :
    QWidget(parent)
{
}

void NewGame::newGame()
{

    if( board == NULL )
    {
        board = new Board( numOfRowsInBoard, numOfColumnsInBoard, numOfMinesInBoard, this );
        toolBar = new ToolBar( board, numOfMinesInBoard, this );

        connect( toolBar->newGameButton, SIGNAL( clicked() ), this, SLOT( newGame() ) );
        connect( board, SIGNAL( onChangeOfNumOfMines(int) ), toolBar, SLOT( numOfMinesChanged(int) ) );
        connect( board, SIGNAL( onStartingPlayingGame() ), toolBar->timer, SLOT( timerConstruction() ) );
        QObject::connect( toolBar->settingsButton, SIGNAL( pressed() ), toolBar->timer, SLOT(pauseTimer()) );
        QObject::connect( toolBar->preferenceWindow->cancelButton, SIGNAL( clicked() ), toolBar->timer, SLOT(resumeTimer()) );
        QObject::connect( toolBar->timerButton, SIGNAL(toggled(bool)), this, SLOT(pauseAndResumeTimer(bool)) );
        connect( toolBar->timer, SIGNAL(onTimerChanged(int)), toolBar, SLOT(timerChange(int)) );
        connect( board, SIGNAL(gameWon()), toolBar->timer, SLOT(pauseTimer()) );
        connect( board, SIGNAL(gameLost()), toolBar->timer, SLOT(pauseTimer()) );
        connect( board, SIGNAL(gameWon()), this, SLOT(onGameEnd()) );
    }

    else
    {
        disconnect( board, SIGNAL( onChangeOfNumOfMines(int) ), toolBar, SLOT( numOfMinesChanged(int) ) );
        disconnect( board, SIGNAL( onStartingPlayingGame() ), toolBar->timer, SLOT( timerConstruction() ) );
        disconnect( board, SIGNAL(gameWon()), toolBar->timer, SLOT(pauseTimer()) );
        disconnect( board, SIGNAL(gameLost()), toolBar->timer, SLOT(pauseTimer()) );
        disconnect( board, SIGNAL(gameWon()), this, SLOT(onGameEnd()) );
        delete board;

        emit removeBoardWidget();

        Board *newBoard = new Board( numOfRowsInBoard, numOfColumnsInBoard, numOfMinesInBoard , this );
        board = newBoard;

        emit addBoardWidget();

        toolBar->board = board;
        toolBar->numOfMinesInBoard = numOfMinesInBoard;
        toolBar->numOfMinesLabel->setText( QString::number( numOfMinesInBoard ) );

        connect( board, SIGNAL( onChangeOfNumOfMines(int) ), toolBar, SLOT( numOfMinesChanged(int) ) );

        toolBar->timer->stopTimer();
        toolBar->timerButton->setText( "0" );

        connect( board, SIGNAL( onStartingPlayingGame() ), toolBar->timer, SLOT( timerConstruction() ) );
        connect( toolBar->timer, SIGNAL(onTimerChanged(int)), toolBar, SLOT(timerChanged(int)) );
        connect( board, SIGNAL(gameWon()), toolBar->timer, SLOT(pauseTimer()) );
        connect( board, SIGNAL(gameLost()), toolBar->timer, SLOT(pauseTimer()) );
        connect( board, SIGNAL(gameWon()), this, SLOT(onGameEnd()) );

        window()->setMaximumSize( board->boardWidget->sizeHint() );

        toolBar->timer->restartTimer();
    }


}

void NewGame::newGame( int numOfRows, int numOfColumns, int numOfMines )
{
    if( board == NULL )
    {
        board = new Board( numOfRows, numOfColumns, numOfMines, this );
        toolBar = new ToolBar( board, numOfMines, this );

        connect( toolBar->newGameButton, SIGNAL( clicked() ), this, SLOT( loadSettings() ) );
        connect( board, SIGNAL( onChangeOfNumOfMines(int) ), toolBar, SLOT( numOfMinesChanged(int) ) );
        connect( board, SIGNAL( onStartingPlayingGame() ), toolBar->timer, SLOT( timerConstruction() ) );
        QObject::connect( toolBar->settingsButton, SIGNAL( pressed() ), toolBar->timer, SLOT(pauseTimer()) );
        QObject::connect( toolBar->preferenceWindow->cancelButton, SIGNAL( clicked() ), toolBar->timer, SLOT(resumeTimer()) );
        QObject::connect( toolBar->timerButton, SIGNAL(toggled(bool)), this, SLOT(pauseAndResumeTimer(bool)) );
        connect( toolBar->timer, SIGNAL(onTimerChanged(int)), toolBar, SLOT(timerChange(int)) );
        connect( board, SIGNAL(gameLost()), toolBar->timer, SLOT(pauseTimer()) );
        connect( board, SIGNAL(gameWon()), this, SLOT(onGameEnd()) );
    }

    else
    {
        disconnect( board, SIGNAL( onChangeOfNumOfMines(int) ), toolBar, SLOT( numOfMinesChanged(int) ) );
        disconnect( board, SIGNAL( onStartingPlayingGame() ), toolBar->timer, SLOT( timerConstruction() ) );
        disconnect( board, SIGNAL(gameWon()), toolBar->timer, SLOT(pauseTimer()) );
        disconnect( board, SIGNAL(gameLost()), toolBar->timer, SLOT(pauseTimer()) );
        disconnect( board, SIGNAL(gameWon()), this, SLOT(onGameEnd()) );
        delete board;

        emit removeBoardWidget();

        Board *newBoard = new Board( numOfRows, numOfColumns, numOfMines , this );
        board = newBoard;

        emit addBoardWidget();

        toolBar->board = board;
        toolBar->numOfMinesInBoard = numOfMines;
        toolBar->numOfMinesLabel->setText( QString::number( numOfMines ) );

        connect( this, SIGNAL( onChangeOfNumOfMines(int) ), toolBar, SLOT( numOfMinesChanged(int) ) );

        toolBar->timer->stopTimer();
        toolBar->timerButton->setText( "0" );

        connect( board, SIGNAL( onStartingPlayingGame() ), toolBar->timer, SLOT( timerConstruction() ) );
        connect( toolBar->timer, SIGNAL(onTimerChanged(int)), toolBar, SLOT(timerChanged(int)) );
        connect( board, SIGNAL(gameWon()), toolBar->timer, SLOT(pauseTimer()) );
        connect( board, SIGNAL(gameLost()), toolBar->timer, SLOT(pauseTimer()) );
        connect( board, SIGNAL(gameWon()), this, SLOT(onGameEnd()) );

        window()->setMaximumSize( board->boardWidget->sizeHint() );

        toolBar->timer->restartTimer();
    }

}

void NewGame::numOfSquaresInBoard( int difficultyOfGame )
{
    if( difficultyOfGame == BEGINNER )
    {
        numOfRowsInBoard = 9;
        numOfColumnsInBoard = 9;
        numOfMinesInBoard = 10;
    }

    else if( difficultyOfGame == INTERMEDIATE )
    {
        numOfRowsInBoard = 16;
        numOfColumnsInBoard = 16;
        numOfMinesInBoard = 40;
    }

    else if( difficultyOfGame == EXPERT )
    {
        numOfRowsInBoard = 16;
        numOfColumnsInBoard = 30;
        numOfMinesInBoard = 99;
    }
}

void NewGame::loadSettings()
{
    settingsFile = new ImpFiles();

    settingsFile->loadSettings();

    QString settings = settingsFile->textStream->readLine();

    QString difficulyOfGame = ( settings.left( settings.size() - 3 ) ).right( settings.size() - 6 );

    if( difficulyOfGame.compare( "BEGINNER" ) == 0 )
    {
        numOfSquaresInBoard( BEGINNER );
        newGame();
    }

    else if( difficulyOfGame.compare( "INTERMEDIATE" ) == 0 )
    {
        numOfSquaresInBoard( INTERMEDIATE );
        newGame();
    }

    else if( difficulyOfGame.compare( "EXPERT" ) == 0 )
    {
        numOfSquaresInBoard( EXPERT );
        newGame();
    }

    else if( difficulyOfGame.compare( "CUSTOM" ) == 0 )
    {
        QString settingsString = settingsFile->textStream->readLine();

        QString numOfRows = ( settingsString.left( settingsString.indexOf( "#" ) ) );
        QString numOfColumns = settingsString.mid( settingsString.indexOf( "#" ) + 1,
                                                   settingsString.lastIndexOf( "#" ) - settingsString.indexOf( "#" ) - 1 );
        QString numOfMines = settingsString.mid( settingsString.lastIndexOf( "#" ) + 1, settings.size() );

        newGame( numOfRows.toInt(), numOfColumns.toInt(), numOfMines.toInt() );
    }

    settingsFile->closeSettingsFile();
}

void NewGame::pauseAndResumeTimer( bool buttonStatus )
{
    if( buttonStatus )
    {
        toolBar->timer->pauseTimer();
    }

    else if( !buttonStatus )
    {
        toolBar->timer->resumeTimer();
    }
}

void NewGame::onGameEnd()
{
    newScore = new NewScore( toolBar->timer->secondCounting, this );
    newScore->construct();
}
