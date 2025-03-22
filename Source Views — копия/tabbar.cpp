#include <QWidget>
#include <QApplication>
#include <QScreen>
#include <QPainter>
#include "globals.hpp"
#include "tabbar.hpp"
TabBar::TabBar(QWidget* parrent): QWidget(parrent) {
    QSize screenSize = g_mainwindow->screen->size();
    setGeometry(screenSize.width() * LEFT_BORDER, 0,screenSize.width()-screenSize.width() * LEFT_BORDER,screenSize.height() * UP_BORDER);
    
}

void TabBar::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setPen(Qt::black);  // Синий цвет пера
    painter.setBrush(QColor("#1d1d1e"));  // Желтая заливка
    painter.drawRect(rect());  // Рисуем квадрат
}
