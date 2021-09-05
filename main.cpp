#include <QApplication>
#include <QTranslator>
#include <QTextCodec>

#include "trayicondemo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TrayIconDemo w;
    w.show();
    
    return app.exec();
}
