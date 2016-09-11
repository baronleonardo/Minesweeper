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

#include "timer.h"


Timer::Timer( QObject *parent ) :
    QObject( parent )
{
    time = new QTime( 0, 0, 0 );
    timer = new QTimer();
    secondCounting = 0;
}

void Timer::timerConstruction()
{
    connect( timer, SIGNAL(timeout()), this, SLOT(startTicking()) );

    timer->start( 1000 );

}

void Timer::startTicking()
{
    ++secondCounting;
    timerChanged();
}

void Timer::timerChanged()
{
    if( secondCounting != 0 )
        emit onTimerChanged( secondCounting ) ;
}

void Timer::restartTimer()
{
    secondCounting = 0;
}

void Timer::stopTimer()
{
    disconnect( timer, SIGNAL(timeout()), this, SLOT(startTicking()) );
    timer->stop();
    restartTimer();
}

void Timer::pauseTimer()
{
    disconnect( timer, SIGNAL(timeout()), this, SLOT(startTicking()) );
    timer->stop();
}

void Timer::resumeTimer()
{
    if( secondCounting != 0 )
    {
        connect( timer, SIGNAL(timeout()), this, SLOT(startTicking()) );
        timer->start( 1000 );
        startTicking();
    }
}
