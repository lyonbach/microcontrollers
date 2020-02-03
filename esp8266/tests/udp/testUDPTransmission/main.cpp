#include <QCoreApplication>
#include <QUdpSocket>
#include <QDebug>
#include <QThread>

void sendMessage(QString* message, QUdpSocket* socket)
{
    if(socket->state() != QAbstractSocket::ConnectedState)
    {
        qDebug() << "Socket not connected! Aborted.";
    }
    socket->write(message->toStdString().c_str());
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QUdpSocket *usock = new QUdpSocket();
    usock->bind(QHostAddress("127.0.0.1"), 512);
    usock->connectToHost("127.0.0.1", 512);
    qDebug() << usock->state();
    if(usock->state() == QAbstractSocket::ConnectedState)
    {
        QString message = "#191919191919181818181818181818181818181818191919191919191919191919191919191919191919191919191919191919191919191919191919B3B3B31919191919191919191919192B2B2B4747472B2B2B4747472B2B2B";
        for(int i = 0; i < 500; i++)
        {
            qDebug() << "Sending Message: " << message;
            sendMessage(&message, usock);
            QThread::msleep(1);
        }
    }
    return a.exec();
}
