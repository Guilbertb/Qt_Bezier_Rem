#ifndef BZVIEW_H
#define BZVIEW_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QPainter>
#include <QPen>
#include <QPainterPath>
#include <QtCore/qmath.h>
#define NBPTS 4
#define PTSIZE 6
#define PTWIDTH 2

class BzView : public QWidget
{
    Q_OBJECT
public:
    explicit BzView(QWidget *parent = 0);
    ~BzView();
    int nbPoints;
    QPoint points[NBPTS];
    int capturedPoint;

    void mousePressEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *p);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

signals:
    void mousePos(QPoint P);

public slots:
    void on_Construire(bool a);
    void on_Effacer();

private slots:

};

#endif // BZVIEW_H
