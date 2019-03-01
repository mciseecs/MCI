#include "tabledialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TableDialog w;
    w.show();

    return a.exec();
}
