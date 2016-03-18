#include "dcrumbbutton.h"
#include <QPainter>

DCrumbButton::DCrumbButton(int index, const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    m_index = index;
    m_name = text;
    setCheckable(true);
    setFocusPolicy(Qt::NoFocus);
    setObjectName("DCrumbButton");
}

DCrumbButton::DCrumbButton(int index, const QIcon &icon, const QString &text, QWidget *parent)
    : QPushButton(icon, "", parent)
{
    m_index = index;
    m_name = text;
    setCheckable(true);
    setFocusPolicy(Qt::NoFocus);
    setObjectName("DCrumbButton");
}

int DCrumbButton::getIndex()
{
    return m_index;
}

QString DCrumbButton::getName()
{
    return m_name;
}

void DCrumbButton::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    double w = width();
    double h = height();
    QPolygon polygon;
    polygon << QPoint(w, 2);
    polygon << QPoint(w, h - 2);
    QPen pen(Qt::gray);
    pen.setWidthF(1);
    painter.setPen(pen);
    painter.drawPolygon(polygon);
    painter.end();
    QPushButton::paintEvent(e);
}