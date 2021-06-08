#include "mylogo.h"
#include <QPainter>
#include <QColor>
#include <QPainterPath>
MyLogo::MyLogo(QWidget *parent)
    : QWidget(parent)
{

}

void MyLogo::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPainterPath path, path1, path2, path3;

    // Greenish triangle
    qreal startPointX1 = 0.0;
    qreal startPointY1 = 0.0;
    qreal endPointX1   = 260.0;
    qreal endPointY1   = 111.0;
    qreal endPointX2   = 0.0;
    qreal endPointY2   = 300.0;

    //Creating path that would be then filled with certain color
    path1.moveTo (startPointX1, startPointY1);
    path1.lineTo (endPointX1, endPointY1);
    path1.lineTo (endPointX2, endPointY2);
    path1.lineTo (startPointX1, startPointY1);

    painter.setPen (Qt::SolidLine);
    painter.fillPath (path1, QBrush(QColor(qRgb(0, 240, 117))));


    //Blueish triangle
     startPointX1 = 0.0;
     startPointY1 = 0.0;
     endPointX1   = 206.4;
     endPointY1   = 150.0;
     endPointX2   = 0.0;
     endPointY2   = 300.0;

    path.moveTo (startPointX1, startPointY1);
    path.lineTo (endPointX1, endPointY1);
    path.lineTo (endPointX2, endPointY2);
    path.lineTo (startPointX1, startPointY1);

    painter.setPen (Qt::SolidLine);
    painter.fillPath (path, QBrush(QColor(qRgb(1, 207, 255))));


    //Redish
    startPointX1 = 0.0;
    startPointY1 = 300.0;
    endPointX1   = 206.4;
    endPointY1   = 150.0;
    endPointX2   = 260.0;
    endPointY2   = 189.0;

    path2.moveTo (startPointX1, startPointY1);
    path2.lineTo (endPointX1, endPointY1);
    path2.lineTo (endPointX2, endPointY2);
    path2.lineTo (startPointX1, startPointY1);

    painter.setPen (Qt::SolidLine);
    painter.fillPath (path2, QBrush(QColor(qRgb(248, 53, 70))));

    //YellowishThing

    qreal finalPointX = 350;
    qreal finalPointY = 150;
    startPointX1 = 206.4;
    startPointY1 = 150.0;
    endPointX1   = 260.0;
    endPointY1   = 111.0;
    endPointX2   = 260.0;
    endPointY2   = 189.0;
    path3.moveTo(endPointX2, endPointY2);
    path3.lineTo(startPointX1, startPointY1);
    path3.lineTo(endPointX1, endPointY1);
    path3.lineTo(finalPointX, finalPointY);
    path3.moveTo(endPointX2, endPointY2);
    painter.setPen (Qt::SolidLine);
    painter.fillPath (path3, QBrush(QColor(qRgb(255, 211, 0))));
}
