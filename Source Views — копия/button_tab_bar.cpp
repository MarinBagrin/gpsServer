#include <QWidget>
#include <QPainter>
#include "button_tab_bar.hpp"

ButtonTabBar::ButtonTabBar(QWidget* parent, QString title, QWidget* tabElem): QPushButton(parent),
titleTab(title),
ptrToTab(tabElem) {
    
}

void ButtonTabBar::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QRect tRect{rect()};
}
