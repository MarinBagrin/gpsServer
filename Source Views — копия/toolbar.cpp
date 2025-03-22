#include <QApplication>
#include <QWidget>
#include <QScreen>
#include <QPainter>
#include <QPropertyAnimation>
#include "toolbar.hpp"
#include "globals.hpp"
#include "buttons.hpp"

Toolbar::Toolbar(QWidget* parrent):
QWidget(parrent),
butSetWsMain(this,&g_workspace->workSpaceProfile),
butSetWsSettings(this,&g_workspace->workSpaceSettings),
butSetWsServer(this,&g_workspace->workSpaceServer){
    QScreen* screen = QApplication::primaryScreen();
    QSize screenSize = screen->size();
    setGeometry(0, 0,screenSize.width() * LEFT_BORDER,screenSize.height() * UP_BORDER);
    QRect frame = rect();
    butSetWsMain.setGeometry(frame.width() * 0.10, frame.height() * 0.1, frame.width() * 0.20, frame.height() * 0.9 );
    butSetWsServer.setGeometry(frame.width() * 0.40, frame.height() * 0.1, frame.width() * 0.20, frame.height() * 0.9 );
    butSetWsSettings.setGeometry(frame.width() * 0.70, frame.height() * 0.1, frame.width() * 0.20, frame.height() * 0.9 );
    
    QObject::connect(&butSetWsMain, &ButtonSetWsMain::clicked, &butSetWsMain, &ButtonSetWsMain::setWsMain);
    QObject::connect(&butSetWsServer, &ButtonSetWsServer::clicked, &butSetWsServer, &ButtonSetWsServer::setWsMain);
    QObject::connect(&butSetWsSettings, &ButtonSetWsSettings::clicked, &butSetWsSettings, &ButtonSetWsSettings::setWsMain);
    
    QRect startGeom = butSetWsServer.geometry();
    QRect endGeom = QRect(startGeom.x() - 5, startGeom.y() - 5, startGeom.width() + 10, startGeom.height() + 10);
    
    QPropertyAnimation* animation = new QPropertyAnimation(&butSetWsServer, "geometry");
    
    QObject::connect(&butSetWsServer,&ButtonSetWsServer::clicked,[startGeom,endGeom,animation](){
        animation->setDuration(100); // Длительность анимации (мс)
        animation->setStartValue(startGeom);
        animation->setEndValue(endGeom);
        animation->setEasingCurve(QEasingCurve::OutBounce); // Эффект плавности
        animation->start();
    });
    
    QPropertyAnimation* reverseAnimation = new QPropertyAnimation(&butSetWsServer, "geometry");
    
    QObject::connect(animation, &QPropertyAnimation::finished, [startGeom,endGeom,reverseAnimation](){
        reverseAnimation->setDuration(200); // Длительность анимации (мс)
        reverseAnimation->setStartValue(endGeom);
        reverseAnimation->setEndValue(startGeom);
        reverseAnimation->setEasingCurve(QEasingCurve::OutBounce); // Эффект плавности
        reverseAnimation->start();
    });

}
    
void Toolbar::paintEvent(QPaintEvent*){
    QScreen* screen = QApplication::primaryScreen();
    QSize screenSize = screen->size();
    QPainter painter(this);
    painter.setPen(QColor("#777777"));
    painter.setBrush(QColor("#777777"));
    painter.drawRect(rect());
    painter.setPen(Qt::black);
    painter.drawLine(screenSize.width() * LEFT_BORDER, 0, screenSize.width() * LEFT_BORDER,screenSize.height() * UP_BORDER);
    painter.setPen(QColor("#4a4a4a"));
    painter.drawLine(0, 0, 0,screenSize.height() * UP_BORDER);
}

