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

#include "highscores.h"

HighScores::HighScores(QWidget *parent) :
    QWidget(parent)
{
    construct();
}

void HighScores::construct()
{
    highScoresMainWidget = new QWidget( this );
    highScoresMainWidget->setVisible( false );
    highScoresMainGridLayout = new QGridLayout( this );

    highScoreTextBrowser = new QTextBrowser( this );
    highScoreTextBrowser->setLineWrapMode( QTextEdit::NoWrap );

    highScoresMainGridLayout->addWidget( highScoreTextBrowser );
    highScoresMainWidget->setLayout( highScoresMainGridLayout );
}

void HighScores::loadHighScores()
{
    highScoresFile = new ImpFiles();

    highScoresFile->loadHighScores();


    int counter = 0;

    while( !highScoresFile->textStream->atEnd() )
    {
        if( counter < 4 )
        {
            highScoreTextBrowser->append( highScoresFile->textStream->readLine() );
        }

        else
        {
            highScoreTextBrowser->append( QString::number( counter - 3 ) + "- " + highScoresFile->textStream->readLine() );
        }

        ++counter;
    }

    highScoresFile->closeHighScoresFile();
}
