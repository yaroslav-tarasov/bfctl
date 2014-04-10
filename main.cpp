#include <QCoreApplication>
#include "netlinksocket.h"
#include <iostream>
#include <QTimer>
#include "bfcontrol.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetlinkSocket *pNS = new NetlinkSocket ;
    BFControl *bfc = new BFControl;
    QObject::connect( pNS,SIGNAL(finished()),&a,SLOT(quit()));
    QObject::connect( pNS,SIGNAL(data(QByteArray)),bfc,SLOT(onDataArrival(QByteArray)),Qt::DirectConnection);

    pNS->startListener(2,33); // PROTO, buf size

    int f;
    std::cout << "Press  any key" << std::endl;
    std::cin.get();
    QTimer::singleShot(10, &a, SLOT(quit()));
    return a.exec();
}
