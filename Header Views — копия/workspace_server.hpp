#ifndef workspace_server_hpp
#define workspace_server_hpp

#include <QWidget>
#include <QLabel>
#include "types_server.hpp"
#include "workspace_protocol.hpp"

class WorkSpaceServer: public WorkspaceProtocol {
    Q_OBJECT
public:
    WorkSpaceServer(QWidget* parrent = nullptr);
    void paintEvent(QPaintEvent*) override;
    //WSProxyServer proxyServer;
    //WSFluxServer fluxServer;
};


#endif

