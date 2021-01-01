#include "paint.h"
#include "ui_paint.h"

Paint::Paint(QWidget *parent) : QWidget(parent), ui(new Ui::Paint){
    ui->setupUi(this);
    scene = new paintScene();
    ui->graphicsView->setScene(scene);
    timer = new QTimer();
    timer_1 = new QTimer();
    connect(timer_1, &QTimer::timeout, this, &Paint::notifyTimer);
    connect(timer, &QTimer::timeout, this, &Paint::slotTimer);
    timer->start(100);
}

Paint::~Paint(){
    delete ui;
}

void Paint::slotTimer(){
    /*Переопределяем размеры графической сцены в зависимости от размеров окна*/
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void Paint::notifyTimer(){
    ui->label->setText("");
    timer_1->stop();
}

void Paint::resizeEvent(QResizeEvent *event){
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Paint::on_pushButton_clicked(){
    QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter(&image);
    scene->render(&painter);
    image.save ("res.png", "PNG", 85);
    ui->label->setText("Saving");
    timer_1->start(2000);
}





void Paint::on_pushButton_4_clicked()
{
    scene->mode = 2;
}

void Paint::on_pushButton_1_clicked()
{
    scene->mode = 1;
}

void Paint::on_pushButton_3_clicked()
{
    scene->mode = 0;
}

void Paint::on_pushButton_2_clicked()
{
    scene->mode = 3;
}
