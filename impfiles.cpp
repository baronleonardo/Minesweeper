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

#include "impfiles.h"

ImpFiles::ImpFiles()
{
    impFilesDir = new QDir( QDir::current() );

    if( !impFilesDir->exists( "important_files" ) )
    {
        impFilesDir->mkdir( "important_files" );
    }

    impFilesDir->cd( "important_files" );
}

void ImpFiles::loadHighScores()
{
    highScoresFile = new QFile( impFilesDir->absolutePath() + "/highscores" );
    textStream = new QTextStream( highScoresFile );

    if( highScoresFile->size() == 0 )
    {
        QMessageBox::warning( NULL, "Warning", "High Scores file not found!\nCreate New File ..." );
        createNewHighScoreFile();
    }

    highScoresFile->open( QIODevice::ReadOnly );
}

void ImpFiles::saveNewScores()
{
    highScoresFile = new QFile( impFilesDir->absolutePath() + "/highscores" );
    textStream = new QTextStream( highScoresFile );

    if( highScoresFile->size() == 0 )
    {
        QMessageBox::warning( NULL, "Warning", "High Scores file not found!\nCreate New File ..." );
        createNewHighScoreFile();
    }

    highScoresFile->open( QIODevice::WriteOnly | QIODevice::Append );
}

void ImpFiles::closeHighScoresFile()
{
    if( highScoresFile != NULL && textStream != NULL )
    {
        highScoresFile->flush();
        highScoresFile->close();

        delete highScoresFile;
        delete textStream;
        delete this;
    }
}

void ImpFiles::createNewHighScoreFile()
{
    highScoresFile->open( QIODevice::WriteOnly );

    *textStream << "==============================="
                 << endl
                 << "---------High Scores----------"
                 << endl << endl << endl;

    highScoresFile->flush();
    highScoresFile->close();
}

void ImpFiles::loadSettings()
{
    settingsFile = new QFile( impFilesDir->absolutePath() + "/settings" );
    textStream = new QTextStream( settingsFile );

    if( settingsFile->size() == 0 )
    {
        QMessageBox::warning( NULL, "Warning", "Settings file not found!\nCreate New File ..." );

        createNewSettingsFile();
    }

    settingsFile->open( QIODevice::ReadOnly );
}

void ImpFiles::saveSettings()
{
    settingsFile = new QFile( impFilesDir->absolutePath() + "/settings" );
    textStream = new QTextStream( settingsFile );

    if( settingsFile->size() == 0 )
    {
        QMessageBox::warning( NULL, "Warning", "Settings file not found!\nCreate New File ..." );

        createNewSettingsFile();
    }

    settingsFile->open( QIODevice::WriteOnly );
}

void ImpFiles::createNewSettingsFile()
{
    settingsFile->open( QIODevice::WriteOnly );

    *textStream << "###BEGINNER###" << endl;

    settingsFile->flush();
    settingsFile->close();
}

void ImpFiles::closeSettingsFile()
{
    if( settingsFile != NULL && textStream != NULL )
    {
        settingsFile->flush();
        settingsFile->close();

        delete settingsFile;
        delete textStream;
        delete this;
    }
}
