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

#include "newscore.h"

NewScore::NewScore( int timerValue, QWidget *parent) :
    QWidget(parent)
{
    this->timerValue = timerValue;
}

void NewScore::construct()
{
    newScoreDialog = new QDialog();
    newScoreDialog->setWindowTitle( "Congratulations" );
    newScoreMainVLayout = new QVBoxLayout( this );

    newScoreDialog->setMaximumSize( newScoreMainVLayout->sizeHint() );

    congratulationsLabel = new QLabel( "<b>You are a Winner!<b>", this );
    congratulationsLabel->setStyleSheet( "color: blue;" );
    congratulationsLabel->setAlignment( Qt::AlignCenter );

    hLayout = new QHBoxLayout( this );
        newScoreLabel = new QLabel( "Name :", this );
        newScoreLineEdit = new QLineEdit( this );
        newScoreLineEdit->setMaximumWidth( 125 );
        space = new QSpacerItem( 40, 60, QSizePolicy::Expanding, QSizePolicy::Fixed );
    hLayout->addWidget( newScoreLabel );
    hLayout->addWidget( newScoreLineEdit );
    hLayout->addItem( space );

    timeScoreLabel = new QLabel( this );
    timeScoreLabel->setAlignment( Qt::AlignCenter );
    timeScoreLabel->setText( "Your Time : <b>" + QString::number( timerValue ) + " sec</b>" );

    hLayout2 = new QHBoxLayout( this );
        space2 = new QSpacerItem( 40, 30, QSizePolicy::Expanding, QSizePolicy::Fixed );
        saveButton = new QPushButton( "Save Score", this );
        cancelButton = new QPushButton( "Cancel", this );
    hLayout2->addItem( space2 );
    hLayout2->addWidget( saveButton );
    hLayout2->addWidget( cancelButton );

    connect( saveButton, SIGNAL(clicked()), this, SLOT(onSave()) );
    connect( cancelButton, SIGNAL(clicked()), newScoreDialog, SLOT(close()) );

    newScoreMainVLayout->addWidget( congratulationsLabel );
    newScoreMainVLayout->addLayout( hLayout );
    newScoreMainVLayout->addWidget( timeScoreLabel );
    newScoreMainVLayout->addLayout( hLayout2 );

    newScoreDialog->setLayout( newScoreMainVLayout );
    newScoreDialog->exec();
}

void NewScore::onSave()
{
    newScoreFile = new ImpFiles();

    newScoreFile->saveNewScores();

    *newScoreFile->textStream << left << qSetFieldWidth( 40 ) << newScoreLineEdit->text();
    *newScoreFile->textStream << qSetFieldWidth( 0 ) << timerValue;
    *newScoreFile->textStream << qSetFieldWidth( 0 ) << " sec" << endl;

    newScoreFile->closeHighScoresFile();

    newScoreDialog->close();
}
