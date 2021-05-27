#include "ihmsynchronisation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ihmSynchronisation w;
    w.show();
    return a.exec();
}
