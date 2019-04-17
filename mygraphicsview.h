#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = 0);

private:
    virtual void resizeEvent(QResizeEvent *e);

signals:
    void resized();
};

#endif // MYGRAPHICSVIEW_H
