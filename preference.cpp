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

#include "preference.h"

Preference::Preference( QWidget *parent ) :
    QWidget( parent )
{
    this->board = board;
    isSaveButtonClicked = false;
    construct();
}

void Preference::construct()
{
    constructPreferenceWindow  = new QDialog( this );
    constructPreferenceWindow->setWindowTitle( "Preference" );
    constructPreferenceWindow->setFixedSize( 375, 300 );

    mainGridLayout = new QGridLayout( this );
        settingsTab = new Settings( this );
        highScoresTab = new HighScores( this );
        howToPlayTab = new HowToPlay( this );
        aboutTab = new About( this );

    hLayout = new QHBoxLayout( this );
        preferenceButtonsGroup = new QButtonGroup( this );
            settingsButton = new QPushButton( "Settings",  this );
                settingsButton->setFocusPolicy( Qt::NoFocus );
                settingsButton->setMaximumSize( 90, 20 );

            highScoresButton = new QPushButton( "High Scores", this );
                highScoresButton->setMaximumSize( 90, 20 );
                highScoresButton->setFocusPolicy( Qt::NoFocus );

            howToPlayButton = new QPushButton( "How to play", this );
                howToPlayButton->setMaximumSize( 90, 20 );
                howToPlayButton->setFocusPolicy( Qt::NoFocus );

            aboutButton = new QPushButton( "About", this );
                aboutButton->setMaximumSize( 90, 20 );
                aboutButton->setFocusPolicy( Qt::NoFocus );;

        preferenceButtonsGroup->addButton( settingsButton, 1 );
        preferenceButtonsGroup->addButton( highScoresButton, 2 );
        preferenceButtonsGroup->addButton( howToPlayButton, 3 );
        preferenceButtonsGroup->addButton( aboutButton, 4 );

        connect( preferenceButtonsGroup, SIGNAL( buttonClicked( QAbstractButton* ) ),
                 this , SLOT( onTabsClicked( QAbstractButton* ) ) );

    hLayout->addWidget( settingsButton );
    hLayout->addWidget( highScoresButton );
    hLayout->addWidget( howToPlayButton );
    hLayout->addWidget( aboutButton );

    mainGridLayout->addLayout( hLayout, 0, 0 );

    mainGridLayout->addWidget( settingsTab->settingsMainWidget, 1, 0 );
    mainGridLayout->addWidget( howToPlayTab->howToPlayMainWidget, 1, 0 );
    mainGridLayout->addWidget( highScoresTab->highScoresMainWidget, 1, 0 );
    mainGridLayout->addWidget( aboutTab->aboutMainWidget, 1, 0 );

    hLayout2 = new QHBoxLayout( this );
        space = new QSpacerItem( 40, 40, QSizePolicy::Expanding, QSizePolicy::Ignored );
        saveButton = new QPushButton( "Save" ,this );
            saveButton->setMaximumSize( 80, 30 );
            saveButton->setFocusPolicy( Qt::NoFocus );
        cancelButton = new QPushButton( "Cancel", this );
            cancelButton->setMaximumSize( 80, 30 );
            cancelButton->setFocusPolicy( Qt::StrongFocus );
    hLayout2->addItem( space );
    hLayout2->addWidget( saveButton );
    hLayout2->addWidget( cancelButton );

    connect( saveButton, SIGNAL( clicked() ), this, SLOT( onSave() ) );
    connect( cancelButton, SIGNAL( clicked() ), constructPreferenceWindow, SLOT( close() ) );

    mainGridLayout->addLayout( hLayout2, 2, 0 );

    constructPreferenceWindow->setLayout( mainGridLayout );
}

void Preference::onSave( )
{
    settingsFile = new ImpFiles();
    settingsFile->saveSettings();

    if( settingsTab->beginnerRadioButton->isChecked() )
    {

        *settingsFile->textStream << "###BEGINNER###" << endl;

        isSaveButtonClicked = true;
    }

    else if( settingsTab->intermediateRadioButton->isChecked() )
    {

        *settingsFile->textStream << "###INTERMEDIATE###" << endl;

        isSaveButtonClicked = true;
    }

    else if( settingsTab->expertRadioButton->isChecked() )
    {

        *settingsFile->textStream << "###EXPERT###" << endl;

        isSaveButtonClicked = true;
    }

    else if( settingsTab->customRadioButton->isChecked() )
    {
        if( !( settingsTab->numOfRowsLineEdit->text() ).compare( "" ) )
        {
            QMessageBox::information( this, "Warning", "<b>Rows #</b> is empty" );
            return;
        }

        if( !( settingsTab->numOfColumnsLineEdit->text() ).compare( "" ) )
        {
            QMessageBox::information( this, "Warning", "<b>Columns #</b> is empty" );
            return;
        }

        if( !( settingsTab->numOfMinesLineEdit->text() ).compare( "" ) )
        {
            QMessageBox::information( this, "Warning", "<b>Mines #</b> is empty" );
            return;
        }

        settingsFile->settingsFile->resize( 0 );
        *settingsFile->textStream << "###CUSTOM###" << endl;
        *settingsFile->textStream << settingsTab->numOfRowsLineEdit->text() << "#"
                                  << settingsTab->numOfColumnsLineEdit->text()  << "#"
                                  << settingsTab->numOfMinesLineEdit->text() << endl;

        isSaveButtonClicked = true;
    }

    settingsFile->closeSettingsFile();
}

void Preference::onTabsClicked(QAbstractButton *button)
{
    if( button == settingsButton )
    {
        settingsTab->settingsMainWidget->setVisible( true );
        howToPlayTab->howToPlayMainWidget->setVisible( false );
        highScoresTab->highScoresMainWidget->setVisible( false );
        aboutTab->aboutMainWidget->setVisible( false );

        saveButton->setVisible( true );
    }

    else if( button == highScoresButton )
    {
        highScoresTab->highScoreTextBrowser->clear();
        highScoresTab->loadHighScores();

        settingsTab->settingsMainWidget->setVisible( false );
        howToPlayTab->howToPlayMainWidget->setVisible( false );
        highScoresTab->highScoresMainWidget->setVisible( true );
        aboutTab->aboutMainWidget->setVisible( false );

        saveButton->setVisible( false );
    }

    else if( button == howToPlayButton )
    {
        aboutTab->aboutMainWidget->setVisible( false );
        howToPlayTab->howToPlayMainWidget->setVisible( true );
        highScoresTab->highScoresMainWidget->setVisible( false );
        settingsTab->settingsMainWidget->setVisible( false );

        saveButton->setVisible( false );
    }

    else if( button == aboutButton )
    {
        settingsTab->settingsMainWidget->setVisible( false );
        howToPlayTab->howToPlayMainWidget->setVisible( false );
        highScoresTab->highScoresMainWidget->setVisible( false );
        aboutTab->aboutMainWidget->setVisible( true );

        saveButton->setVisible( false );
    }
}
