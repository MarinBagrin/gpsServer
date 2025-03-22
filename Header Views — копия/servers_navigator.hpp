#ifndef servers_navigator
#define servers_navigator

#include <QWidget>

class ServersNavigator: public QWidget {
    Q_OBJECT
public:
    ServersNavigator(QWidget* parrent = nullptr);
    void paintEvent(QPaintEvent*) override;
};


#endif
