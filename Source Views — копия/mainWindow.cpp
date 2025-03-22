#include <QApplication>
#include <QWidget>
#include <QScreen>
#include "main_window.hpp"
#include "globals.hpp"
MainWindow::MainWindow():
QWidget(),
screen(QApplication::primaryScreen()){
    g_mainwindow = this;
    resize(screen->size());
};
