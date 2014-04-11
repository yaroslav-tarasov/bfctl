#include "bfcontrol.h"
#include <netlink/netlink.h>
#include <netlink/handlers.h>
#include <QDebug>

BFControl::BFControl(QObject *parent) :
    QObject(parent)
{
}


void BFControl::onDataArrival(QByteArray ba)
{
    struct nlmsghdr * hdr = (struct nlmsghdr *) ba.data();
    qDebug() << "onDataArrives" << hdr->nlmsg_type;
}


void BFControl::rdRead()
{
//    struct nlmsghdr * hdr = (struct nlmsghdr *) ba.data();
     qDebug() << "onDataArrives"; // << hdr->nlmsg_type;
}
