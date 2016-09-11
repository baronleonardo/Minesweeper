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

#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QDesktopWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    constructionOfCentralWidget = new QWidget( parent );
    construct();
}

void MainWindow::construct()
{
    window()->setWindowIcon( QIcon( ":/icons/big_mine" ) );
    mainWidget = new QWidget( this );
    mainLayout = new QGridLayout( this );

    loadSettings();

    mainLayout->setAlignment(newGame->board->boardWidget, Qt::AlignCenter);
    window()->setMaximumSize(newGame->board->boardLayout->sizeHint());

    setCentralWidget( constructionOfCentralWidget );

    mainLayout->addWidget( newGame->toolBar->toolBar, 0, 0 );
    mainLayout->addWidget( newGame->board->boardWidget, 1, 0 );

    connect( newGame, SIGNAL( removeBoardWidget() ), this, SLOT( onRemovingBoardWidget() ) );
    connect( newGame, SIGNAL( addBoardWidget() ), this, SLOT( onAddingBoardWidget() ) );

    constructionOfCentralWidget->setLayout( mainLayout );
}

void MainWindow::onRemovingBoardWidget()
{
    mainLayout->removeWidget( newGame->board->boardWidget );
}

void MainWindow::onAddingBoardWidget()
{
    mainLayout->addWidget( newGame->board->boardWidget );

    window()->setMaximumSize( newGame->board->boardWidget->sizeHint() );

    QRect desktopRect = QApplication::desktop()->screenGeometry(this);
    QPoint center = desktopRect.center();
    this->move(center.x()-width()*0.5, center.y()-height()*0.5);
}

void MainWindow::loadSettings()
{
    settingsFile = new ImpFiles();

    settingsFile->loadSettings();

    QString settings = settingsFile->textStream->readLine();

    QString difficulyOfGame = ( settings.left( settings.size() - 3 ) ).right( settings.size() - 6 );

    if( difficulyOfGame.compare( "BEGINNER" ) == 0 )
    {
        newGame = new NewGame( this );
        newGame->numOfSquaresInBoard( BEGINNER );
        newGame->newGame();
    }

    else if( difficulyOfGame.compare( "INTERMEDIATE" ) == 0 )
    {
        newGame = new NewGame( this );
        newGame->numOfSquaresInBoard( INTERMEDIATE );
        newGame->newGame();
    }

    else if( difficulyOfGame.compare( "EXPERT" ) == 0 )
    {
        newGame = new NewGame( this );
        newGame->numOfSquaresInBoard( EXPERT );
        newGame->newGame();
    }

    else if( difficulyOfGame.compare( "CUSTOM" ) == 0 )
    {
        QString settingsString = settingsFile->textStream->readLine();

        QString numOfRows = ( settingsString.left( settingsString.indexOf( "#" ) ) );
        QString numOfColumns = settingsString.mid( settingsString.indexOf( "#" ) + 1,
                                                   settingsString.lastIndexOf( "#" ) - settingsString.indexOf( "#" ) - 1 );
        QString numOfMines = settingsString.mid( settingsString.lastIndexOf( "#" ) + 1, settings.size() );

        newGame = new NewGame( this );
        newGame->newGame( numOfRows.toInt(), numOfColumns.toInt(), numOfMines.toInt() );
    }

    settingsFile->closeSettingsFile();
}

MainWindow::~MainWindow()
{

}
