#include "ejemplo1.h"


ejemplo1::ejemplo1() : Ui_Counter() {
    setupUi(this);
    show();
    connect(button, SIGNAL(clicked()), this, SLOT(doButton()));
    connect(pushButton, SIGNAL(clicked()), this, SLOT(doReset()));
    connect(pushButton_3, SIGNAL(clicked()),this, SLOT(doCurrentPeriod()));
    connect(pushButton_4, SIGNAL(clicked()),this,SLOT(doTotalPeriod()));

    mytimer.connect(std::bind(&ejemplo1::cuenta, this));
    mytimer.setInit(cont);
    mytimer.start(500);
}

ejemplo1::~ejemplo1() {}

void ejemplo1::doButton() {
    stopped = !stopped;
    if (stopped) {
        mytimer.stop();
    }else {
        mytimer.setInit(cont);
        mytimer.start(500);
    }
    qDebug() << "click on button";
}

void ejemplo1::doReset() {
    cont = 0;
    mytimer.setInit(cont);
    mytimer.start(500);
    stopped = false;

    qDebug() << "click on reset";
}
void ejemplo1::doCurrentPeriod(){

    currentPeriodT();

}

void ejemplo1::doTotalPeriod() {
    totalPeriodT();
}

void ejemplo1::cuenta() {
    lcdNumber->display(++cont);
    trick++;
}

void ejemplo1::changePeriodT(int period) {
    mytimer.setPeriod(period);
}

int ejemplo1::currentPeriodT() {
    qDebug("The current period is: %d",mytimer.getPeriod());
     return mytimer.getPeriod();
}

int ejemplo1::totalPeriodT() {
    qDebug("Total period is: %d",(mytimer.getPeriod()- mytimer.getInit()));
    return mytimer.getPeriod() - mytimer.getInit();
}
