#include "udp_sock.h"

UDP_sock::UDP_sock(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
}


void UDP_sock::udp_bind(QString addr, QString port){
    quint16 qport;
    QTextStream ts(&port);
    ts>>qport;
    socket->bind(QHostAddress(addr),qport);
}


void UDP_sock::say(QByteArray str, QString addr, QString port){

    quint16 qport;
    QTextStream ts(&port);
    ts>>qport;
    socket->writeDatagram(str,QHostAddress(addr),qport);
}
