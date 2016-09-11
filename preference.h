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

#ifndef PREFERENCE_H
#define PREFERENCE_H

#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QSpacerItem>
#include <QApplication>
#include <QTextStream>

#include "board.h"
#include "settings.h"
#include "howtoplay.h"
#include "highscores.h"
#include "about.h"
#include "impfiles.h"

class Preference : public QWidget
{

    Q_OBJECT

public:

    Board *board;

    QDialog *constructPreferenceWindow;
    QGridLayout *mainGridLayout;

    Settings *settingsTab;
    HighScores *highScoresTab;
    HowToPlay *howToPlayTab;
    About *aboutTab;

    QHBoxLayout *hLayout;
        QButtonGroup *preferenceButtonsGroup;
            QPushButton *settingsButton;
            QPushButton *highScoresButton;
            QPushButton *howToPlayButton;
            QPushButton *aboutButton;

    QHBoxLayout *hLayout2;
        QSpacerItem *space;
        QPushButton *saveButton;
        QPushButton *cancelButton;

    bool isSaveButtonClicked;
    ImpFiles *settingsFile;

public:
    explicit Preference( QWidget *parent = 0 );
    void construct();

public slots:
    void onTabsClicked( QAbstractButton* );
    void onSave();
};

#endif // PREFERENCE_H
