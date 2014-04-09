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
    

public slots:
    void process();

signals:
    void finished();
    void error(QString err);

protected:
   std::shared_ptr<NetlinkSocketPrivate> d;
};

#endif // NETLINKSOCKET_H
