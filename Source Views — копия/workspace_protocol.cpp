#include <QWidget>
#include "workspace_protocol.hpp"
WorkspaceProtocol::WorkspaceProtocol(QWidget* parent):QWidget(parent){};

void WorkspaceProtocol::resizeEvent(QResizeEvent* event) {
    frame = parentWidget()->rect();
    setGeometry(frame);
}
