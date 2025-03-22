#include <QApplication>
#include <QWidget>
#include <QScreen>
#include <QPainter>
#include "globals.hpp"
#include "workspace_settings.hpp"
WorkSpaceSettings::WorkSpaceSettings(QWidget* parrent): WorkspaceProtocol(parrent){}

void WorkSpaceSettings::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setPen(QColor(clr_main_text));
    painter.setBrush(QColor(clr_main_background));
    painter.drawRect(rect());
    painter.drawText(50, 50, "Setings1");
    
    qDebug() << "Рисуется Сетингс " << objectName();

}

