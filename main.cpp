#include <QCoreApplication>
#include "netlinksocket.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    NetlinkSocket *p = new NetlinkSocket ;

    return a.exec();
}
