#ifndef types_server_hpp
#define types_server_hpp

#include <QWidget>

class WorkspaceProtocol: public QWidget {
    Q_OBJECT
public:
    WorkspaceProtocol(QWidget* parent);
    void resizeEvent(QResizeEvent *event) override;
    QRect frame;
};

#endif
