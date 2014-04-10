#include <QCoreApplication>
#include "netlinksocket.h"
#include <iostream>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetlinkSocket *pNS = new NetlinkSocket ;
    QObject::connect( pNS,SIGNAL(finished()),&a,SLOT(quit()));

    pNS->startListener(2,33); // PROTO, buf size

    int f;
    std::cout << "Press  any key" << std::endl;
    std::cin.get();
    QTimer::singleShot(10, &a, SLOT(quit()));
    return a.exec();
}
