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

#include "toolbar.h"

ToolBar::ToolBar( Board *board, int numOfMinesInBoard, QWidget *parent ) :
    QWidget(parent)
{


    this->board = board;
    this->numOfMinesInBoard = numOfMinesInBoard;

    construct();
}

void ToolBar::construct()
{
        space1 = new QSpacerItem( 40, 40, QSizePolicy::Expanding, QSizePolicy::Ignored );
        space2 = new QSpacerItem( 40, 40, QSizePolicy::Expanding, QSizePolicy::Ignored );

        toolBar = new QToolBar( this );
        toolBar->setMovable( false );


        toolBarWidget = new QWidget( this );
        toolBarWidget->setContentsMargins( 0, -10, 0, -10 );

        toolBarLayout = new QHBoxLayout( this );
        toolBarLayout->setAlignment( Qt::AlignCenter );

        newGameButton = new QPushButton( this );
        newGameButton->setVisible( false );
        newGameButton->setFixedSize( 27, 27 );
        newGameButton->setFlat( true );
        newGameButton->setIcon( QIcon( ":/icons/restart" ) );
        newGameButton->setIconSize( QSize( 20, 20 ) );

        logoButton = new QPushButton( this );
        logoButton->setToolTip( "Restart or Settings" );
        logoButton->setFocusPolicy( Qt::NoFocus );
        logoButton->setCheckable(true);
        logoButton->setFixedSize( 27, 27 );
        logoButton->setFlat( true );
        logoButton->setIcon( QIcon( ":/icons/big_mine" ) );
        logoButton->setIconSize( QSize( 27,27 ) );

        settingsButton = new QPushButton( this );
        settingsButton->setToolTip( "Settings" );
        settingsButton->setFixedSize( 27, 27 );
        settingsButton->setVisible( false );
        settingsButton->setFlat( true );
        settingsButton->setIcon( QIcon( ":/icons/settings" ) );
        settingsButton->setIconSize( QSize( 27, 27 ) );

        preferenceWindow = new Preference( this );

        QObject::connect( settingsButton, SIGNAL( clicked() ), preferenceWindow->settingsTab, SLOT( loadSettings() ) );
        QObject::connect( settingsButton, SIGNAL( clicked() ), preferenceWindow->constructPreferenceWindow, SLOT( exec() ) );

        QObject::connect( logoButton, SIGNAL( toggled(bool) ), newGameButton, SLOT( setVisible(bool) ) );
        QObject::connect( logoButton, SIGNAL( toggled(bool) ), settingsButton, SLOT( setVisible(bool) ) );
        QObject::connect( newGameButton, SIGNAL( clicked() ), logoButton, SLOT( toggle() ) );
        QObject::connect( settingsButton, SIGNAL( clicked() ), logoButton, SLOT( toggle() ) );

        numOfMinesLabel = new QLabel( this );
        mineIconLabel = new QLabel(this);
        mineIconLabel->setFixedSize( 15, 15 );

        numOfMinesLabel->setText( QString::number( numOfMinesInBoard ) );
        numOfMinesLabel->setStyleSheet( "font: 16pt;" );
        mineIconLabel->setStyleSheet( "image: url(\":/icons/small_mine\");" );
        mineIconLabel->setToolTip( "Number Of Mines" );

        timerButton = new QPushButton( "0", this );
        timerButton->setToolTip( "Timer" );
        timerButton->setMaximumSize( 30, 20 );
        timerButton->setCheckable( true );
        timerButton->setChecked( false );

        timer = new Timer( this );

        QObject::connect( board, SIGNAL( onChangeOfNumOfMines(int) ), this, SLOT( numOfMinesChanged( int ) ) );

        toolBarLayout->addWidget( mineIconLabel );
        toolBarLayout->addWidget( numOfMinesLabel );
        toolBarLayout->addItem( space1 );
        toolBarLayout->addWidget( newGameButton );
        toolBarLayout->addWidget( logoButton );
        toolBarLayout->addWidget( settingsButton );
        toolBarLayout->addItem( space2 );
        toolBarLayout->addWidget( timerButton );

        toolBarWidget->setLayout( toolBarLayout );
        toolBar->addWidget( toolBarWidget );
}

void ToolBar::numOfMinesChanged( int newNumOfMines )
{
    numOfMinesLabel->setText( QString::number( newNumOfMines ) );
}

void ToolBar::timerChange( int second )
{
    timerButton->setText( QString::number( second ) );
}
