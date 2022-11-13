#include "mainDialog.h"
#include "ui_mainDialog.h"
#include <QDebug>
#include <QColor>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QStyleOptionGraphicsItem>
#include <QMouseEvent>

#include "led.h"
#include "constants.h"

void mousePressEvent(QMouseEvent* event)
{
    qDebug() << event->button();
}

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    ui->setupUi(this);
    ui->screenLayout->setStretchFactor(ui->graphicsView, 10);
    ui->screenLayout->setStretchFactor(ui->screenLabel, 1);
    ui->mainLayout->setContentsMargins(15, 15, 15, 15);

    this->setWindowTitle("LB_AMBILIGHT LED Simulator :: TEST");
    this->setLayout(ui->mainLayout);

    QGraphicsScene *graphicsScene = new QGraphicsScene();
    graphicsScene->setSceneRect(0, 0, 600, 300);
    ui->graphicsView->setScene(graphicsScene);

    // We use a timer to repepetively uptade the LEDs and the screenshot in the middle.
    // Timer is connected to the repopulate() enabling us to clear and refill the are with the
    // updated LEDs.
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repopulate()));

    // Initialize the device
    esp = get_Device();

}

Dialog::~Dialog()
{
    delete timer;
    delete ui->graphicsView->scene();
    delete ui;
}

void Dialog::addLED(double coordX, double coordY, QColor& color)
{
    QBrush brush = QBrush(color);
    QPen pen = QPen(12);
    QGraphicsEllipseItem *LED = ui->graphicsView->scene()->addEllipse(coordX, coordY, LEDSize, LEDSize, pen, brush);
    LED->setFlag(QGraphicsItem::ItemIsSelectable);
}

QPixmap Dialog::grabScreen()
{
    QWindow *window = windowHandle();
    QScreen *mainScreen = QGuiApplication::primaryScreen();
    mainScreen = window->screen();
    if(!mainScreen)
    {
        qDebug() << "Could not Acquire the screen!";
        return QPixmap();
    }
    QPixmap grabbed = mainScreen->grabWindow(0);
    return grabbed;
}

void Dialog::updateBackground()
{
    QPixmap pixmap = grabScreen();

    int w = ui->graphicsView->scene()->sceneRect().width();
    int h = ui->graphicsView->scene()->sceneRect().height();
    QSize size = QSize(w - LEDSize - 5, h - LEDSize - 5);

    pixmap = pixmap.scaled(size);
    QGraphicsPixmapItem *bg = ui->graphicsView->scene()->addPixmap(pixmap);
    bg->moveBy(LEDSize / 2 + 3, LEDSize / 2 + 3);
}

void Dialog::repopulate()
{
    // First we need to clear the graphicsScene
    // UPDATE ONLY REAL LED WITH THE SELECTED COLOR...
    if(ui->graphicsView->scene()->selectedItems().count())
    {
        if(espAvailable)
        {
            QPixmap pixmap = grabScreen();
            QImage image = pixmap.toImage();
            QWindow *window = windowHandle();
            QColor color = image.pixelColor(window->cursor().pos());
            QString command = getCommandFromARGB(color);
            esp->write(command.toStdString().c_str());
        }
    }

    ui->graphicsView->scene()->clear();
    updateBackground();

    int horizontalCount = ui->HledCountSpinbox->value();
    int verticalCount = ui->VledCountSpinbox->value();

    double screenWidth = ui->graphicsView->scene()->sceneRect().width();
    double screenHeight = ui->graphicsView->scene()->sceneRect().height();

    double coordX, coordY;
    int pix_coordX, pix_coordY;
    QColor color;
    QPixmap pixmap = grabScreen();
    QScreen *mainScreen = QGuiApplication::primaryScreen();
    QImage image = pixmap.toImage();

    // Calculate the bottom line of LEDs.
    for(int i = 0; i < horizontalCount; i++)
    {
        // We need to modifiy the distance to the actual distance.
        coordX = screenWidth - LEDSize / 2 - i * (screenWidth / (horizontalCount - 1));
        coordY = screenHeight - LEDSize / 2;

        pix_coordX = i * (mainScreen->size().width() / (horizontalCount - 1));
        if(pix_coordX < 0)
            pix_coordX = 0;
        if(pix_coordX > mainScreen->size().width() - 1)
            pix_coordX = mainScreen->size().width() - 1;
        pix_coordX = mainScreen->size().width() - 1 - pix_coordX;
        pix_coordY = mainScreen->size().height() - 1;
        color = image.pixelColor(pix_coordX, pix_coordY);

        addLED(coordX, coordY, color);
    }
    // Calculate the left line of LEDs.
    for(int i = 1; i < verticalCount - 1; i++)
    {
        coordX = - LEDSize / 2;
        coordY = screenHeight - LEDSize / 2 - i * (screenHeight/(verticalCount - 1));

        pix_coordX = i * (mainScreen->size().width() / (horizontalCount - 1));
        pix_coordY = i * (mainScreen->size().height() / (verticalCount - 1));
        if(pix_coordY < 0)
            pix_coordY = 0;
        if(pix_coordY > mainScreen->size().height() - 1)
            pix_coordY = mainScreen->size().height() - 1;
        pix_coordX = 0;
        pix_coordY = mainScreen->size().height() - 1 - pix_coordY;
        color = image.pixelColor(pix_coordX, pix_coordY);

        addLED(coordX, coordY, color);
    }
    // Calculate the top line of LEDs.
    for(int i = 0; i < horizontalCount; i++)
    {
        coordX = - LEDSize / 2 + i * (screenWidth / (horizontalCount - 1));
        coordY = - LEDSize / 2;

        pix_coordX = i * (mainScreen->size().width() / (horizontalCount - 1));
        if(pix_coordX < 0)
            pix_coordX = 0;
        if(pix_coordX > mainScreen->size().width() - 1)
            pix_coordX = mainScreen->size().width() - 1;
        pix_coordY = 0;
        color = image.pixelColor(pix_coordX, pix_coordY);

        addLED(coordX, coordY, color);
    }
    // Calculate the right line of LEDs.
    for(int i = 1; i < verticalCount - 1; i++)
    {
        coordX = screenWidth - LEDSize / 2;
        coordY = i * (screenHeight/(verticalCount - 1)) - LEDSize / 2;
        pix_coordX = i * (mainScreen->size().width() / (horizontalCount - 1));
        pix_coordY = i * (mainScreen->size().height() / (verticalCount - 1));
        if(pix_coordY < 0)
            pix_coordY = 0;
        if(pix_coordY > mainScreen->size().height() - 1)
            pix_coordY = mainScreen->size().height() - 1;
        pix_coordX = mainScreen->size().width() - 1;
        color = image.pixelColor(pix_coordX, pix_coordY);
        addLED(coordX, coordY, color);
    }
}

void Dialog::on_pushButton_pressed()
{

}

void Dialog::on_HledCountSpinbox_valueChanged(int value)
{
    repopulate();
}

void Dialog::on_VledCountSpinbox_valueChanged(int value)
{
    repopulate();
}

void Dialog::resizeEvent(QResizeEvent *event)
{
    repopulate();
    QWidget::resizeEvent(event);

}

void Dialog::on_pushButton_toggled(bool checked)
{
    if (checked)
    {
        ui->pushButton->setText(RTR_BUTTON_CHECKED_TEXT);  //Real time refresh button down state
        timer->start();
    }
    else
    {
        ui->pushButton->setText(RTR_BUTTON_UNCHECKED_TEXT);  //Real time refresh button up state
        timer->stop();
    }

}
