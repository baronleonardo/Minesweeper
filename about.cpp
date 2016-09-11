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

#include "about.h"

About::About(QWidget *parent) :
    QWidget(parent)
{
    construct();
}

void About::construct()
{
    aboutMainWidget = new QWidget(this);
    aboutMainWidget->setVisible( false );
    aboutMainGridLayout = new QGridLayout( this );

    aboutLabel = new QLabel( this );
        aboutLabel->setAlignment( Qt::AlignHCenter | Qt::AlignVCenter );
        aboutQString = "This game done by <b><u>Baron Leonardo</b></u>"
                      "<br />"
                      "<u>mail:</u> mohamedayman.fcis@zoho.com"
                      "<br />"
                      "Under <b>GPL</b> Licence";
    aboutLabel->setText( aboutQString );

    aboutMainGridLayout->addWidget( aboutLabel, 0 , 0 );

    aboutMainWidget->setLayout( aboutMainGridLayout );
}
