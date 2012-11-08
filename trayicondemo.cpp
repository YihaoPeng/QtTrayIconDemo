#include <QSystemTrayIcon>
#include "trayicondemo.h"
#include "ui_trayicondemo.h"

TrayIconDemo::TrayIconDemo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrayIconDemo),
    _strIconPath("D:/QtPorjects/TrayIconDemo/res/barcaTray.ico")
{
    ui->setupUi(this);

    createTrayIcon();

    setWindowIcon(QIcon(_strIconPath));
}

TrayIconDemo::~TrayIconDemo()
{
    delete ui;
}

void TrayIconDemo::createTrayIcon()
{
    // ���������Ҽ��˵�
    CreatTrayMenu();

    if(!QSystemTrayIcon::isSystemTrayAvailable())
        return;

    // ��������ͼ��
    _pTrayIcon = new QSystemTrayIcon(this);
    _pTrayIcon->setIcon(QIcon(_strIconPath));
    _pTrayIcon->setContextMenu(_pMenu);
    _pTrayIcon->setToolTip(tr("֧����"));
    _pTrayIcon->showMessage(tr("֧����"), tr("֧���ܼ�������"),
        QSystemTrayIcon::Information, 5000);
    _pTrayIcon->show();

    // �����¼���Ӧ
    connect(_pTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void TrayIconDemo::CreatTrayMenu()
{
    _pminiSizeAction = new QAction("��С��(&N)",this);
    _pmaxSizeAction = new QAction("���(&X)",this);
    _prestoreWinAction = new QAction("�� ԭ(&R)",this);
    _pquitAction = new QAction("�˳�(&Q)",this);

    connect(_pminiSizeAction,SIGNAL(triggered()),this,SLOT(hide()));
    connect(_pmaxSizeAction,SIGNAL(triggered()),this,SLOT(showMaximized()));
    connect(_prestoreWinAction,SIGNAL(triggered()),this,SLOT(showNormal()));
    connect(_pquitAction,SIGNAL(triggered()),qApp,SLOT(quit()));

    _pMenu = new QMenu((QWidget*)QApplication::desktop());
    _pMenu->addAction(_pminiSizeAction);
    _pMenu->addAction(_pmaxSizeAction);
    _pMenu->addAction(_prestoreWinAction);
    _pMenu->addSeparator();     //����һ�������
    _pMenu->addAction(_pquitAction);
}

void TrayIconDemo::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        this->showNormal();
        break;
    default:
        break;
    }
}

// �ػ�ر��¼�����Щ������ʾ
void TrayIconDemo::closeEvent(QCloseEvent *event)
{
    if (_pTrayIcon->isVisible())
    {
        _pTrayIcon->showMessage("֧����","˫������ͼ��ɻָ�����",QSystemTrayIcon::Information,3000);

        this->hide();     //��С��
        event->ignore();
    }
    else
    {
        event->accept();
    }
}










