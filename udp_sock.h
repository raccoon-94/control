#ifndef UDP_SOCK_H
#define UDP_SOCK_H

#include <QObject>
#include <QUdpSocket>



class UDP_sock : public QObject
{
    Q_OBJECT
public:
    explicit UDP_sock(QObject *parent = 0);
    void say(QByteArray str,QString addr,QString port);
    void udp_bind(QString addr,QString port);
signals:


public slots:

private:
    QUdpSocket *socket;
};

#endif // UDP_SOCK_H
