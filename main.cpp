#include "picker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Picker w;
    w.show();
    return a.exec();
}
