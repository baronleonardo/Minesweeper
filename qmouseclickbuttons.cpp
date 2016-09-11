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

#include "qmouseclickbuttons.h"


QMouseClickButtons::QMouseClickButtons(QWidget *parent):
    QPushButton(parent)
{
    this->setFocusPolicy( Qt::NoFocus );
    isClicked = false;
    isRightClicked = false;
}

void QMouseClickButtons::mousePressEvent(QMouseEvent *e)
{
    if( e->button() == Qt::RightButton )
    {
        emit rightClicked( this );
    }

    else if( e->button() == Qt::LeftButton )
    {
        emit leftClicked( this );
    }
}
