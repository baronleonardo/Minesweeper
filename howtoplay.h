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

#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QScrollArea>

class HowToPlay : public QWidget
{
    Q_OBJECT

public:
    QWidget *howToPlayMainWidget;
    QGridLayout *howToPlayMainGLayout;
    QLabel *howToPlayVideoLabel;

    QScrollArea *scrollArea;
        QLabel *toolBarDescriptionLabel;

public:
    explicit HowToPlay(QWidget *parent = 0);
    void construct();

signals:

public slots:

};

#endif // HOWTOPLAY_H
