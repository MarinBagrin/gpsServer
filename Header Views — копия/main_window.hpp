#ifndef main_window_hpp
#define main_window_hpp

#include <QWidget>
#include <QScreen>

class MainWindow:public QWidget {
    Q_OBJECT
public:
    MainWindow();
    
    QScreen* screen;
};


#endif
