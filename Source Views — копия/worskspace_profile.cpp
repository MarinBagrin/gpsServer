#include <QApplication>
#include <QWidget>
#include <QScreen>
#include <QPainter>
#include "globals.hpp"
#include "workspace_profile.hpp"
WorkSpaceProfile::WorkSpaceProfile(QWidget* parrent): WorkspaceProtocol(parrent){
}

void WorkSpaceProfile::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(QColor(clr_main_background));
    painter.drawRect(rect());
    //текст
    painter.setPen(clr_main_text);
    QFont font("Avenir", frame.height() * 0.03, QFont::Bold);
    painter.setFont(font);
    painter.drawText(frame.width()*0.05,frame.height()*0.05,"Search portfolio");
    //search geom
    painter.drawRoundedRect(frame.width()*0.05, frame.height()*0.05, frame.width() * 0.30, frame.height() * 0.10, 15, 15);
    qDebug() << "Рисуется Профайл" << objectName();

}



