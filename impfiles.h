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

#ifndef IMPFILES_H
#define IMPFILES_H

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCoreApplication>
#include <QDir>

class ImpFiles
{
public:
    QFile *highScoresFile;
    QFile *settingsFile;
    QTextStream *textStream;

    QDir *impFilesDir;

public:
    ImpFiles();

    void createNewHighScoreFile();
    void closeHighScoresFile();
    void loadHighScores();
    void saveNewScores();

    void createNewSettingsFile();
    void closeSettingsFile();
    void loadSettings();
    void saveSettings();
};

#endif // IMPFILES_H
