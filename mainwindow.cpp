#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBrush>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();
    PaintCircle(0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Init()
{
    CreateScene();
}

void MainWindow::CreateScene()
{
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

void MainWindow::PaintCircle(const int x, const int y)
{
    scene->clear();
    int h = 40;
    int w = h;
    QBrush brush(Qt::blue, Qt::BrushStyle::SolidPattern);
    QPen pen(brush,w);
    scene->addEllipse(x,y,w,h,pen,brush);
}

void MainWindow::mousePressEvent(QMouseEvent *pe)
{
    PaintCircle(pe->x(), pe->y());
    QMessageBox msgBox;
    msgBox.setText(QString("x = " + QString::number(pe->x())
                           + "y = " + QString::number(pe->y())));
    msgBox.show();
}
