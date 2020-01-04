#ifndef LED_H
#define LED_H
#include <QtSerialPort>
#include <QMessageBox>
#endif // LED_H

static bool espAvailable = false;
static int espVendorID = 4292;
static int espProductID = 60000;
static QString espPortName;

QSerialPort* get_Device()
{
   int numberOfAvailablePorts = QSerialPortInfo::availablePorts().length();
   qDebug() << "Number of available ports: " << numberOfAvailablePorts;

   if(numberOfAvailablePorts == 0)
   {
       QString warningMessage = "No devices available!";
       qDebug() << warningMessage;
       QMessageBox::warning(nullptr, "WARNING", warningMessage);
//       return nullptr;
   }

   espAvailable = false;
   foreach (const QSerialPortInfo& serialPortInfo, QSerialPortInfo::availablePorts())
   {
       if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier())
       {
           if(serialPortInfo.vendorIdentifier() != espVendorID)
           {
               continue;
           }
           if(serialPortInfo.productIdentifier() != espProductID)
           {
               continue;
           }
           espPortName = serialPortInfo.portName();

           espAvailable = true;
       }
   }
   if (espAvailable)
   {
       QSerialPort *device = new QSerialPort;
       device->setPortName(espPortName);
       device->open(QSerialPort::WriteOnly);
       device->setBaudRate(QSerialPort::Baud115200);
       device->setDataBits(QSerialPort::Data8);
       device->setParity(QSerialPort::NoParity);
       device->setStopBits(QSerialPort::OneStop);
       device->setFlowControl(QSerialPort::NoFlowControl);
       return device;
   }
    return nullptr;
}

QString getCommandFromARGB(QColor& colorInfo)
{
    QString command;
    command += QString::number(static_cast<int>(colorInfo.redF() * 1000)) + ",";
    command += QString::number(static_cast<int>(colorInfo.greenF() * 1000)) + ",";
    command += QString::number(static_cast<int>(colorInfo.blueF() * 1000)) + "\n";
    return command;
}
