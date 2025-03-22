#ifndef buttons_hpp
#define buttons_hpp
#include <QPushButton>
#include <QWidget>

class ButtonsToolbar: public QPushButton {
    Q_OBJECT
public:
    ButtonsToolbar(QWidget* parent, QWidget* wsElem);
    void setWsMain();
protected:
    QWidget* ptrWsElem;
};

class ButtonSetWsMain: public ButtonsToolbar {
    Q_OBJECT
public:
    ButtonSetWsMain(QWidget* parent, QWidget* wsElem);
    void paintEvent(QPaintEvent*) override;

};

class ButtonSetWsServer: public ButtonsToolbar {
    Q_OBJECT
public:
    ButtonSetWsServer(QWidget* parent, QWidget* wsElem);
    void paintEvent(QPaintEvent*) override;

};

class ButtonSetWsSettings: public ButtonsToolbar {
    Q_OBJECT
public:
    ButtonSetWsSettings(QWidget* parent, QWidget* wsElem);
    void paintEvent(QPaintEvent*) override;

};


#endif

