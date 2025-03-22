#include <QApplication>
#include <QWidget>
#include <QScreen>
#include <QPainter>
#include "servers_navigator.hpp"
#include <iostream>
#include "globals.hpp"
ServersNavigator::ServersNavigator(QWidget* parrent): QWidget(parrent) {
    QScreen* screen = QApplication::primaryScreen();
    QSize screenSize = screen->size();
    setGeometry(0, screenSize.height()*UP_BORDER,screenSize.width() * LEFT_BORDER, screenSize.height() - screenSize.height() * UP_BORDER);
//    QPalette palette = this->palette();
//    palette.setColor(QPalette::Window, Qt::darkGray);
//    setAutoFillBackground(true);
//    setPalette(palette);

}
void ServersNavigator::paintEvent(QPaintEvent*) {
    QSize screenSize = g_mainwindow->screen->size();
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(QColor("#454545"));  
    painter.drawRect(rect());  // Рисуем квадрат
    
    painter.setPen(QColor("#454545"));
    painter.drawLine(0,0,screenSize.width()*LEFT_BORDER,0);
}

