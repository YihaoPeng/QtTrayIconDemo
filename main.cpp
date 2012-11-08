#include <QtGui/QApplication>
#include <QTranslator>
#include <QTextCodec>

#include "trayicondemo.h"

int main(int argc, char *argv[])
{
    // ��QMessageBox����ʹ�����İ�ť
    QTranslator oTranslator;
    oTranslator.load(":/qt_zh_CN.qm");
    QApplication app(argc, argv);
    app.installTranslator(&oTranslator);

    // ��QT�������ʹ������
    // ��ȡϵͳ����
    QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    TrayIconDemo w;
    w.show();
    
    return app.exec();
}
