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

#include "howtoplay.h"

HowToPlay::HowToPlay(QWidget *parent) :
    QWidget(parent)
{
    construct();
}

void HowToPlay::construct()
{
    howToPlayMainWidget = new QWidget( this );
    howToPlayMainWidget->setVisible( false );
    howToPlayMainGLayout = new QGridLayout( this );

    howToPlayVideoLabel = new QLabel( this );
    howToPlayVideoLabel->setAlignment( Qt::AlignCenter );
    howToPlayVideoLabel->setText( "<a href=\"https://www.youtube.com/watch?v=Z0EAysRluJk\">"
                             "How To Play MineSweeper</a>"
                             "<br />" );
    howToPlayVideoLabel->setToolTip( "https://www.youtube.com/watch?v=Z0EAysRluJk - YouTube" );
    howToPlayVideoLabel->setTextFormat( Qt::RichText );
    howToPlayVideoLabel->setTextInteractionFlags( Qt::TextBrowserInteraction );
    howToPlayVideoLabel->setOpenExternalLinks( true );

    scrollArea = new QScrollArea( this );
    scrollArea->setAlignment( Qt::AlignCenter );
        toolBarDescriptionLabel = new QLabel( this );
        toolBarDescriptionLabel->setText( "<img src=\":/icons/howtoplay\""
                                          "/*height=\"300\"*/ />" );

    scrollArea->setWidget( toolBarDescriptionLabel );

    howToPlayMainGLayout->addWidget( howToPlayVideoLabel, 0, 0 );
    howToPlayMainGLayout->addWidget( scrollArea, 1, 0 );

    howToPlayMainWidget->setLayout( howToPlayMainGLayout );
}
