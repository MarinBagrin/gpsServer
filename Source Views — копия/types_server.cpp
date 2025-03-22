#include <QWidget>
#include <QPainter>
#include "types_server.hpp"
#include "globals.hpp"

void TypeServerProtocol::resizeEvent(QResizeEvent* event) {
    setGeometry(parentWidget()->rect());
}

WSProxyServer::WSProxyServer(QWidget* parent): TypeServerProtocol(parent){}

void WSProxyServer::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(QColor("#1E1E2E"));
    painter.drawRect(rect());
}

WSFluxServer::WSFluxServer(QWidget* parent): TypeServerProtocol(parent){}

void WSFluxServer::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(QColor("#FF0000"));
    painter.drawRect(rect());
}
