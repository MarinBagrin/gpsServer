#include <QApplication>  // Для запуска приложения
#include <QWidget>       // Базовый класс всех виджетов
#include <QPushButton>       // Базовый класс всех виджетов
#include <QStyleFactory>
#include "main_window.hpp"
#include "servers_navigator.hpp"
#include "tabbar.hpp"
#include "workspace.hpp"
#include "toolbar.hpp"

void startInterface(int argc,char *argv[]) {
    QApplication app(argc, argv);
    
    MainWindow window;
   // ServersNavigator servNavigator(&window);
    TabBar recentServBar(&window);
    Workspace workspace(&window);
    Toolbar toolbar(&window);
    // Устанавливаем стиль Windows
    //QApplication::setStyle(QStyleFactory::create("Windows"));
    
    window.show();
    return app.exec();
}

