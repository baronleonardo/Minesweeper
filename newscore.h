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

#ifndef NEWSCOER_H
#define NEWSCOER_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QLayout>
#include <QSpacerItem>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>

#include "impfiles.h"

class NewScore : public QWidget
{
    Q_OBJECT

public:
    QDialog *newScoreDialog;
    QVBoxLayout *newScoreMainVLayout;

    QLabel *congratulationsLabel;

    QHBoxLayout *hLayout;
        QLabel *newScoreLabel;
        QLineEdit * newScoreLineEdit;
        QSpacerItem *space;

    QLabel *timeScoreLabel;

    QHBoxLayout *hLayout2;
        QSpacerItem *space2;
        QPushButton *saveButton;
        QPushButton *cancelButton;

    int timerValue;

    ImpFiles *newScoreFile;

public:
    explicit NewScore( int timerValue, QWidget *parent = 0);
    void construct();

signals:

private slots:
    void onSave();

};

#endif // NEWSCOER_H
