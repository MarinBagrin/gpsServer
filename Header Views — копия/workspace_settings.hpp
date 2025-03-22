#ifndef workspace_setings_hpp
#define workspace_setings_hpp

#include <QWidget>
#include "workspace_protocol.hpp"

class WorkSpaceSettings: public WorkspaceProtocol {
    Q_OBJECT
public:
    WorkSpaceSettings(QWidget* parrent = nullptr);
    void paintEvent(QPaintEvent*) override;

};


#endif

