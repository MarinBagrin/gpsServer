#include <QApplication>
#include <QWidget>
#include <QScreen>
#include <QPainter>
#include "workspace.hpp"
#include "globals.hpp"
Workspace::Workspace(QWidget* parrent): QWidget(parrent),
workSpaceSettings(this),
workSpaceServer(this),
workSpaceProfile(this){
    g_workspace = this;
    workSpaceSettings.raise();
    workSpaceServer.raise();
    workSpaceProfile.raise();
}

void Workspace::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(QColor("FFFF11")); //#47433d
    painter.drawRect(rect());
}

void Workspace::resizeEvent(QResizeEvent* event) {
    QSize screenSize = g_mainwindow->screen->size();
    QRect rectmw = g_mainwindow->rect();
    setGeometry(screenSize.width()*LEFT_BORDER,screenSize.height()*UP_BORDER,
                rectmw.width()-screenSize.width()*LEFT_BORDER,rectmw.height()-screenSize.height()*UP_BORDER);
}
