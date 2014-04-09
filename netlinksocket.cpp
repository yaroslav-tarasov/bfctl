#include "netlinksocket.h"
#include <netlink/netlink.h>
#include <netlink/handlers.h>
#include <QThread>

class NetlinkSocketPrivate
{
public:
    explicit NetlinkSocketPrivate(NetlinkSocket * pp): mpp(pp){};
    ~NetlinkSocketPrivate(){destroy();};

//    void Create()
//    {
//        thread = new QThread;
//        mpp->moveToThread(thread);
//        QObject::connect(mpp, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
//        QObject::connect(thread, SIGNAL(started()), mpp, SLOT(process()));
//        QObject::connect(mpp, SIGNAL(finished()), thread, SLOT(quit()));
//        QObject::connect(mpp, SIGNAL(finished()), mpp, SLOT(deleteLater()));
//        QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
//        thread->start();

//    };

    inline int  create ()
    {
#ifdef HAVE_LIBNL3
     nls = nl_socket_alloc();
#else
     nls = nl_handle_alloc();
#endif
      return nls?0:1;
    }

    inline int  connect (int protocol)
    {
        return nl_connect(nls, protocol);
    }

    inline int send_simple( int type, int flags, void *buf, size_t size)
    {
        return nl_send_simple(nls, type, flags, buf, size);
    }

    inline void destroy()
    {
    #ifdef HAVE_LIBNL3
        nl_socket_free(nls);
    #else
        nl_handle_destroy(nls);
    #endif
    }

#ifdef HAVE_LIBNL3
    struct nl_sock *nls;
#else
    struct nl_handle *nls;
#endif

    NetlinkSocket* mpp;

//protected:
//    QThread* thread;
};


NetlinkSocket::NetlinkSocket(QObject *parent) :
    QObject(parent)
{
    d.reset(new NetlinkSocketPrivate(this));
}

void NetlinkSocket::process() {
    // allocate resources using new here
    qDebug("Hello World!");
    emit finished();
}
