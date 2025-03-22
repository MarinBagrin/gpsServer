#include <QApplication>
#include <QWidget>
#include <QScreen>
#include <QPainter>
#include "workspace_server.hpp"
#include "globals.hpp"
#include <iostream>
WorkSpaceServer::WorkSpaceServer(QWidget* parrent): WorkspaceProtocol(parrent){
}
//proxyServer(this),
//fluxServer(this){}

void WorkSpaceServer::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setPen(clr_main_text);
    painter.setBrush(QColor(clr_main_background));
    painter.drawRect(rect());
    qDebug() << "Рисуется Сервер" << objectName();

}

