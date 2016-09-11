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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QMessageBox>
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QDialog>
#include <QLineEdit>
#include <QSpacerItem>
#include <QGroupBox>
#include <QTextStream>
#include <QFile>
#include <QValidator>
#include <QApplication>

#include "impfiles.h"

class Settings : public QWidget
{
    Q_OBJECT
public:
    explicit Settings(QWidget *parent = 0);
    void construct();

public:
    QWidget *settingsMainWidget;
    QGridLayout *settingsMainGridLayout;

    QLabel *diffcultyOfGameLabel;
    QVBoxLayout *diffcultyOfGameLayout;
        QGroupBox *diffcultyOfGameGroupBox;
            QRadioButton *beginnerRadioButton;
            QRadioButton *intermediateRadioButton;
            QRadioButton *expertRadioButton;
            QRadioButton *customRadioButton;
                QHBoxLayout *hLayout1;
                    QSpacerItem *space1;
                    QLabel *numOfRowsLabel;
                    QLineEdit *numOfRowsLineEdit;
                    QSpacerItem *space2;
                QHBoxLayout *hLayout2;
                    QSpacerItem *space3;
                    QLabel *numOfColumnsLabel;
                    QLineEdit *numOfColumnsLineEdit;
                    QSpacerItem *space4;
                QBoxLayout * hLayout3;
                    QSpacerItem *space5;
                    QLabel *numOfMinesLabel;
                    QLineEdit *numOfMinesLineEdit;
                    QLabel *numOfMinesHintLabel;
                    QSpacerItem *space6;

    QVBoxLayout *layout;
    ImpFiles *settingsFile;

private:
    void createNewSettingsFile();

signals:

public slots:
    void loadSettings();
};

#endif // SETTINGS_H
