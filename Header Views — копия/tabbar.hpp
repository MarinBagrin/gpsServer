#ifndef tabbar_hpp
#define tabbar_hpp
#include <QWidget>
#include <QPainter>

class TabBar: public QWidget {
    Q_OBJECT
public:
    TabBar(QWidget* parrent = nullptr);
    void paintEvent(QPaintEvent*) override;
};

#endif
