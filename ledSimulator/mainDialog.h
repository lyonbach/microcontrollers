#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVector>
#include <QWindow>
#include <QScreen>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog() override;

private slots:
    void on_pushButton_pressed();
    void on_HledCountSpinbox_valueChanged(int value);
    void on_VledCountSpinbox_valueChanged(int value);
    void repopulate();
    void on_pushButton_toggled(bool checked);

private:
    QTimer *timer;
    QColor currentColor = Qt::black;
    QSerialPort *esp;

private:
    Ui::Dialog *ui;
    void addLED(double coordX, double coordY, QColor& color);
    void updateBackground();
    QPixmap grabScreen();

protected:
    void resizeEvent(QResizeEvent *) override;

};
#endif // DIALOG_H
