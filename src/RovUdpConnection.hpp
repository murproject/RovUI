#pragma once

#include <QObject>
#include <QtNetwork>

class RovUdpConnection : public QObject {
    Q_OBJECT
public:
    explicit RovUdpConnection(QObject* parent = nullptr);

    ~RovUdpConnection();

public slots:
    void transmitDatagram(QByteArray datagram);

signals:
    void dataReceived(QByteArray datagram);

private:
    void onDatareceived();

    const quint16 m_port = 3010;
    QScopedPointer<QUdpSocket> m_socket;
};
