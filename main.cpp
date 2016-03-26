#include "tabbedsoundboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TabbedSoundBoard w;
    w.show();

    return a.exec();
}
