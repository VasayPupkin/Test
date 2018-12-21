#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

struct Frame
{
    //Y-coordinate
    int _top;
    int _bottom;
    //X-coordinate
    int _left;
    int _right;
    //size
    int _height;
    int _width;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void Init();
    void CreateScene();
    void PaintCircle(const int x, const int y);

protected:
    void mousePressEvent(QMouseEvent *pe) override;

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = nullptr;
};

#endif // MAINWINDOW_H
