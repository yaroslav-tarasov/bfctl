#ifndef NETLINKSOCKET_H
#define NETLINKSOCKET_H

#include <QObject>
#include <memory>

class NetlinkSocketPrivate;

class NetlinkSocket : public QObject
{
    Q_OBJECT
public:
    explicit NetlinkSocket(QObject *parent = 0);
    void startListener(int proto, int buffsize);
    virtual void OnReceive(int nErrorCode);

protected:
    static void threadStart(NetlinkSocket *p);
    void runListener();

signals:
    void finished();
    void error(QString err);
    void data(QByteArray ba);

protected:
   std::shared_ptr<NetlinkSocketPrivate> d;
   std::shared_ptr<unsigned char> mBuff;
   int mProto;
   int mBuffSize;
};

#endif // NETLINKSOCKET_H
