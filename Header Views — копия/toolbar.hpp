#ifndef toolbar_hpp
#define toolbar_hpp
#include <QWidget>
#include <buttons.hpp>

class Toolbar: public QWidget {
    Q_OBJECT
public:
    Toolbar(QWidget* parrent);
    void paintEvent(QPaintEvent*) override;
    ButtonSetWsMain butSetWsMain;
    ButtonSetWsServer butSetWsServer;
    ButtonSetWsSettings butSetWsSettings;
};




#endif
