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

#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QTime>
#include <QObject>


class Timer : public QObject
{
    Q_OBJECT

public:
    explicit Timer( QObject *parent = 0 );

public:
    QTimer *timer;

    const int maxTimerInSec = 999;
    int secondCounting;

    QTime *time;

protected:
    void timerChanged();

signals:
    void onTimerChanged( int );

public slots:
    void startTicking();
    void restartTimer();
    void timerConstruction();
    void stopTimer();
    void pauseTimer();
    void resumeTimer();

signals:

};

#endif // TIMER_H
