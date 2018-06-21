#include "bzview.h"

BzView::BzView(QWidget *parent) : QWidget(parent)
{
    nbPoints=0;
    capturedPoint=-1;
    setMouseTracking(true);

}

BzView::~BzView()
{

}


void BzView::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton)
    {
        if (nbPoints < NBPTS)
        {
            points[nbPoints]=ev->pos();
            nbPoints++;
        }
        if(nbPoints == NBPTS)
        {
            for (int i=0;i<NBPTS;i++)
            {
                if (qSqrt(qPow(points[i].x()-ev->pos().x(),2)+qPow(points[i].y()-ev->pos().y(),2)) < PTSIZE)
                    capturedPoint=i;
            }
        }
    }

    update();
}

void BzView::mouseReleaseEvent(QMouseEvent *ev)
{
    capturedPoint=-1;
}

void BzView::mouseMoveEvent(QMouseEvent *ev)
{
    if (capturedPoint >= 0)
    {
        points[capturedPoint]=ev->pos();
        update();
    }
    emit mousePos(ev->pos());

}

void BzView::paintEvent(QPaintEvent *p)
{
    QPainter painter(this);
    QPen pen(Qt::red, PTWIDTH, Qt::SolidLine , Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    for(int i=0; i<nbPoints;i++)
    {
        QRectF rectangle(points[i].x()-PTSIZE/2, points[i].y()-PTSIZE/2,PTSIZE, PTSIZE);


        painter.drawEllipse(rectangle);
    }
    if(nbPoints == NBPTS)
    {
        QPainterPath m_PainterPath;
        m_PainterPath.moveTo(points[0].x(),points[0].y());
        m_PainterPath.cubicTo(points[1],points[2],points[3]);
        QPen pen_black(Qt::black, 1, Qt::SolidLine , Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen_black);
        painter.drawPath(m_PainterPath);

    }

}



void BzView::on_Construire(bool a)
{

}

void BzView::on_Effacer()
{
    nbPoints=0;
    update();
}

