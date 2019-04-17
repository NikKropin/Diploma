#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    this->setMinimumHeight(500);
    this->setMinimumWidth(500);

    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void MyGraphicsView::resizeEvent(QResizeEvent *e)
{
    emit resized();
    QGraphicsView::resizeEvent(e);
}
