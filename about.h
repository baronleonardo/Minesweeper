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

#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>
#include <QLayout>
#include <QLabel>

class About : public QWidget
{
    Q_OBJECT

public:
    QWidget *aboutMainWidget;
    QGridLayout *aboutMainGridLayout;
    QLabel *aboutLabel;
    QString aboutQString;

public:
    explicit About(QWidget *parent = 0);
    void construct();

signals:

public slots:

};

#endif // ABOUT_H
