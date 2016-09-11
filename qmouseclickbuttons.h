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

#ifndef QRIGHTCLICKBUTTON_H
#define QRIGHTCLICKBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QMouseEvent>

class QMouseClickButtons : public QPushButton
{
    Q_OBJECT
public:
    explicit QMouseClickButtons( QWidget *parent = 0 );

public:
    bool isClicked;
    bool isRightClicked;

protected:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked( QMouseClickButtons * );
    void leftClicked( QMouseClickButtons * );

public slots:

};

#endif // QRIGHTCLICKBUTTON_H
