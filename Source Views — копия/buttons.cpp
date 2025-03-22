#include <QPushButton>
#include <QWidget>
#include <QPainter>
#include "buttons.hpp"
#include "globals.hpp"
#include <QSvgRenderer>


ButtonsToolbar::ButtonsToolbar(QWidget* parent, QWidget* wsElem):
QPushButton(parent),
ptrWsElem(wsElem){
   // QObject::connect(this, &ButtonsToolbar::setWsMain, this, &ButtonsToolbar::setWsMain);
}

void ButtonsToolbar::setWsMain(){
    hideChildsParent(g_workspace);
    ptrWsElem->show();
}

ButtonSetWsMain::ButtonSetWsMain(QWidget* parent, QWidget* wsElem): ButtonsToolbar(parent, wsElem) {
    QIcon icon("gps.png");
    setIcon(icon);
}
void ButtonSetWsMain::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.drawRect(rect());
}

ButtonSetWsSettings::ButtonSetWsSettings(QWidget* parent, QWidget* wsElem): ButtonsToolbar(parent, wsElem) {}
void ButtonSetWsSettings::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.drawRect(rect());
}
ButtonSetWsServer::ButtonSetWsServer(QWidget* parent,QWidget* wsElem): ButtonsToolbar(parent, wsElem) {}
void ButtonSetWsServer::paintEvent(QPaintEvent*) {
    QPen pen(Qt::white);
    pen.setWidth(2);
    QPainter painter(this);
    int w = rect().width();
    int h = rect().height();
    QRect iRect(w * 0.2, h * 0.2, w * 0.6, h * 0.6);
    painter.setPen(Qt::white);
    painter.setBrush(Qt::white);
    painter.drawRoundedRect(iRect, 3, 3);
    
    painter.setPen(QColor("#777777"));
    painter.setBrush(QColor("#777777"));
    painter.drawRect(iRect.x(), iRect.y() + iRect.height() * 0.333, iRect.width(), iRect.height() * 0.1);
    painter.drawRect(iRect.x(), iRect.y() + iRect.height() * 0.666, iRect.width(), iRect.height() * 0.1);
    
    painter.setRenderHint(QPainter::Antialiasing, false);

    painter.setBrush(Qt::red);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawEllipse(iRect.x()*1.5,iRect.y() + iRect.height() * (0.333-0.222),
                        iRect.height() * 0.111, iRect.height() * 0.121);
    pen.setColor(Qt::green);
    painter.setPen(pen);
    painter.setBrush(Qt::green);
    painter.drawEllipse(iRect.x()*1.5,iRect.y() + iRect.height() * (0.666-0.222),
                        iRect.height() * 0.111, iRect.height() * 0.121);
    pen.setColor(QColor("#FF9800"));
    painter.setPen(pen);
    painter.setBrush(QColor("#FF9800"));
    painter.drawEllipse(iRect.x()*1.5,iRect.y() + iRect.height() * (0.999-0.160),
                        iRect.height() * 0.111, iRect.height() * 0.121);

    float radius = iRect.width() * 0.08325;
    QRect aRect(iRect.x()+(iRect.width() * 1.1) - radius,iRect.y()+iRect.height() * 0.666,
                radius * 2,radius * 2);
    QRect a2Rect(iRect.x()+(iRect.width() * 1.1) - radius,iRect.y()+iRect.height() * 0.333,
                 radius * 2,radius * 2);
//    QRect a3Rect(iRect.x()+iRect.width() - radius,iRect.y()+iRect.height() * -0.08,
//                 radius * 2,radius * 2);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawArc(aRect, 90 * 16, -180 * 16);
    painter.drawArc(a2Rect, 90 * 16, -180 * 16);
//    painter.drawArc(a3Rect, 90 * 16, -180 * 16);

//    QSvgRenderer renderer(QString("server-config.svg"));
//    renderer.render(&painter,rect());

}


