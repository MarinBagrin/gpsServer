#ifndef workspace_profile_hpp
#define workspace_profile_hpp

#include <QWidget>
#include "workspace_protocol.hpp"

class WorkSpaceProfile: public WorkspaceProtocol {
    Q_OBJECT
public:
    WorkSpaceProfile(QWidget* parrent = nullptr);
    void paintEvent(QPaintEvent*) override;

};


#endif

