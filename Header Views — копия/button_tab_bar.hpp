#ifndef button_tab_bar_hpp
#define button_tab_bar_hpp

#include <QWidget>
#include <QPushButton>
class ButtonTabBar: public QPushButton {
    Q_OBJECT
public:
    ButtonTabBar(QWidget* parent, QString title,QWidget* tabElem);
    void paintEvent(QPaintEvent*) override;
    QWidget* ptrToTab;
    QString titleTab;
};

#endif
