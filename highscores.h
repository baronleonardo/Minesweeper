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

#ifndef HIGHSCORES_H
#define HIGHSCORES_H

#include <QWidget>
#include <QGridLayout>
#include <QTextBrowser>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>

#include "impfiles.h"

class HighScores : public QWidget
{
    Q_OBJECT

public:
    QWidget *highScoresMainWidget;
    QGridLayout *highScoresMainGridLayout;

    QTextBrowser *highScoreTextBrowser;

    ImpFiles *highScoresFile;

//    bool highScoresIsShown = false;

public:
    explicit HighScores(QWidget *parent = 0);
    void construct();
    void loadHighScores();

signals:

public slots:

};

#endif // HIGHSCORES_H
