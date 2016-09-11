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

#include "settings.h"


Settings::Settings(QWidget *parent) :
    QWidget(parent)
{
    construct();
}

void Settings::construct()
{
    settingsMainWidget = new QWidget( this );
    settingsMainGridLayout = new QGridLayout( this );

    diffcultyOfGameGroupBox = new QGroupBox( this );
    diffcultyOfGameGroupBox->setTitle( "Game difficulty :" );
        diffcultyOfGameLayout = new QVBoxLayout( this );
            beginnerRadioButton = new QRadioButton( "Beginner", this );
            intermediateRadioButton = new QRadioButton( "Intermediate", this );
            expertRadioButton = new QRadioButton( "Expert", this );
            customRadioButton = new QRadioButton( "Custom...", this );

        diffcultyOfGameLayout->addWidget( beginnerRadioButton );
        diffcultyOfGameLayout->addWidget( intermediateRadioButton );
        diffcultyOfGameLayout->addWidget( expertRadioButton );
        diffcultyOfGameLayout->addWidget( customRadioButton );
    diffcultyOfGameGroupBox->setLayout( diffcultyOfGameLayout );
        hLayout1 = new QHBoxLayout( this );
            space1 = new QSpacerItem( 30, 40, QSizePolicy::Fixed, QSizePolicy::Ignored );
            numOfRowsLabel = new QLabel( "Rows #      ", this );
            numOfRowsLabel->setEnabled( false );
            numOfRowsLineEdit = new QLineEdit( this );
            numOfRowsLineEdit->setEnabled( false );
            numOfRowsLineEdit->setMaximumSize( 35, 20 );
            numOfRowsLineEdit->setValidator( new QIntValidator( 10, 30, this ) );
            space2 = new QSpacerItem( 40, 40, QSizePolicy::Expanding, QSizePolicy::Ignored );

        hLayout1->addItem( space1 );
        hLayout1->addWidget( numOfRowsLabel );
        hLayout1->addWidget( numOfRowsLineEdit );
        hLayout1->addItem( space2 );
    diffcultyOfGameLayout->addLayout( hLayout1 );

        connect( customRadioButton, SIGNAL( toggled(bool) ), numOfRowsLineEdit, SLOT( setEnabled(bool) ) );
        connect( customRadioButton, SIGNAL( toggled(bool) ), numOfRowsLabel, SLOT( setEnabled(bool) ) );

        hLayout2 = new QHBoxLayout( this );
            space3 = new QSpacerItem( 30, 40, QSizePolicy::Fixed, QSizePolicy::Ignored );
            numOfColumnsLabel = new QLabel( "Columns #", this );
            numOfColumnsLabel->setEnabled( false );
            numOfColumnsLineEdit = new QLineEdit( this );
            numOfColumnsLineEdit->setEnabled( false );
            numOfColumnsLineEdit->setMaximumSize( 35, 20 );
            numOfColumnsLineEdit->setValidator( new QIntValidator( 10, 50, this ) );
            space4 = new QSpacerItem( 40, 40, QSizePolicy::Expanding, QSizePolicy::Ignored );
        hLayout2->addItem( space3 );
        hLayout2->addWidget( numOfColumnsLabel );
        hLayout2->addWidget( numOfColumnsLineEdit );
        hLayout2->addItem( space4 );
    diffcultyOfGameLayout->addLayout( hLayout2 );

        connect( customRadioButton, SIGNAL( toggled(bool) ), numOfColumnsLineEdit, SLOT( setEnabled(bool) ) );
        connect( customRadioButton, SIGNAL( toggled(bool) ), numOfColumnsLabel, SLOT( setEnabled(bool) ) );

        hLayout3 = new QHBoxLayout( this );
            space5 = new QSpacerItem( 30, 40, QSizePolicy::Fixed, QSizePolicy::Fixed );
            numOfMinesLabel = new QLabel( "Mines #     " );
            numOfMinesLabel->setEnabled( false );
            numOfMinesLineEdit = new QLineEdit( this );
            numOfMinesLineEdit->setEnabled( false );
            numOfMinesLineEdit->setFixedSize( 35, 20 );
            numOfMinesHintLabel = new QLabel( this );
            numOfMinesHintLabel->setText( "Max Mines# = Row# x Col#" );
            numOfMinesHintLabel->setStyleSheet( "font: 8pt;" );
            space6 = new QSpacerItem( 40, 40, QSizePolicy::Expanding, QSizePolicy::Fixed );

        hLayout3->addItem( space5 );
        hLayout3->addWidget( numOfMinesLabel );
        hLayout3->addWidget( numOfMinesLineEdit );
        hLayout3->addWidget( numOfMinesHintLabel );
        hLayout3->addItem( space6 );
    diffcultyOfGameLayout->addLayout( hLayout3 );

        connect( customRadioButton, SIGNAL( toggled(bool) ), numOfMinesLabel, SLOT( setEnabled(bool) ) );
        connect( customRadioButton, SIGNAL( toggled(bool) ), numOfMinesLineEdit, SLOT( setEnabled(bool) ) );

    settingsMainGridLayout->addWidget( diffcultyOfGameGroupBox, 0, 0 );

    settingsMainWidget->setLayout( settingsMainGridLayout );
}

void Settings::loadSettings()
{

    settingsFile = new ImpFiles();
    settingsFile->loadSettings();

    QString settings = settingsFile->textStream->readLine();

    QString difficulyOfGame = ( settings.left( settings.size() - 3 ) ).right( settings.size() - 6 );

    if( difficulyOfGame.compare( "BEGINNER" ) == 0 )
    {
        beginnerRadioButton->setChecked(true);
    }

    else if( difficulyOfGame.compare( "INTERMEDIATE" ) == 0 )
    {
        intermediateRadioButton->setChecked(true);
    }

    else if( difficulyOfGame.compare( "EXPERT" ) == 0 )
    {
        expertRadioButton->setChecked(true);
    }

    else if( difficulyOfGame.compare( "CUSTOM" ) == 0 )
    {
        customRadioButton->setChecked(true);

        QString settingsString = settingsFile->textStream->readLine();

        QString numOfRows = ( settingsString.left( settingsString.indexOf( "#" ) ) );
        QString numOfColumns = settingsString.mid( settingsString.indexOf( "#" ) + 1,
                                                   settingsString.lastIndexOf( "#" ) - settingsString.indexOf( "#" ) - 1 );
        QString numOfMines = settingsString.mid( settingsString.lastIndexOf( "#" ) + 1, settings.size() );

        numOfRowsLineEdit->setText( numOfRows );
        numOfColumnsLineEdit->setText( numOfColumns );
        numOfMinesLineEdit->setText( numOfMines );

    }

    settingsFile->closeSettingsFile();
}

