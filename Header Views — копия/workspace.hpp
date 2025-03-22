#ifndef workspace_hpp
#define workspace_hpp
#include <QWidget>
#include "workspace_profile.hpp"
#include "workspace_settings.hpp"
#include "workspace_server.hpp"
class Workspace: public QWidget {
  Q_OBJECT
public:
    Workspace(QWidget* parrent);
    
    void paintEvent(QPaintEvent*) override;
    
    void resizeEvent(QResizeEvent *event) override;
    
    WorkSpaceProfile workSpaceProfile;
    WorkSpaceServer workSpaceServer;
    WorkSpaceSettings workSpaceSettings;
};

#endif
