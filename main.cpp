#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

#include <iostream>

#include <netlink/netlink.h>
#include <netlink/handlers.h>
#include <linux/if_ether.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include "trx_data.h"

//#include "netlinksocket.h"
#include "bfcontrol.h"
#include "netlink_socket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetlinkSocket *pNS = new NetlinkSocket;
    pNS->Create();
    filter_rule  fr(IPPROTO_UDP,18000,0);
    pNS->SendMsg(MSG_GET_RULES,&fr,sizeof(filter_rule));
    BFControl *bfc = new BFControl;
    // QObject::connect( pNS,SIGNAL(finished()),&a,SLOT(quit()));
    // QObject::connect( pNS,SIGNAL(data(QByteArray)),bfc,SLOT(onDataArrival(QByteArray)),Qt::DirectConnection);
    QObject::connect( pNS,SIGNAL(readyRead()),bfc,SLOT(rdRead()),Qt::DirectConnection);
    // pNS->startListener(2,33); // PROTO, buf size

    std::cout << "Press  any key" << std::endl;
    std::cin.get();
    QTimer::singleShot(10, &a, SLOT(quit()));
    return a.exec();
}
