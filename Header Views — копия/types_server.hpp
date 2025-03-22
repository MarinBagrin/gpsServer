#ifndef ws_servers_hpp
#define ws_servers_hpp

#include <QWidget>

class TypeServerProtocol: public QWidget {
    Q_OBJECT
public:
    using QWidget::QWidget;
    void resizeEvent(QResizeEvent* event) override;
};


class WSProxyServer: public TypeServerProtocol {
    Q_OBJECT
public:
    WSProxyServer(QWidget* parent);
    void paintEvent(QPaintEvent*) override;
};

class WSFluxServer: public TypeServerProtocol {
    Q_OBJECT
public:
    WSFluxServer(QWidget* parent);
    void paintEvent(QPaintEvent*) override;
};

#endif
