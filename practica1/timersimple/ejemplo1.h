#ifndef ejemplo1_H
#define ejemplo1_H

#include <QtGui>
#include "ui_counterDlg.h"
#include <chrono>
#include "timer.h"


class ejemplo1 : public QWidget, public Ui_Counter {
Q_OBJECT
public:
    ejemplo1();

    virtual ~ejemplo1();

public slots:
    void doButton();
    void doReset();

    void doChangePeriod();
    void doCurrentPeriod();
    void doTotalTime();
    void doLapTime();

private:
    Timer mytimer, mytimerLong;
    int cont = 0;
    bool stopped = false;

    // dos callbacks con diferente número de parámetros
    void cuenta();

//    void doPartialTime();
    int trick = 5;
};

#endif // ejemplo1_H
