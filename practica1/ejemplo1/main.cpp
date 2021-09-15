#include <QtWidgets>
#include "ejemplo1.h"
/*
 * Authors: Costa Barriga Rubén, Pulido Porras Celia, Curiel Gómez Julia
 * Group: G9-M1
 */
int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    ejemplo1 foo;
    foo.show();
    return app.exec();
}
