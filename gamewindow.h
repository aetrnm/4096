#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE


class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();
private:
    Ui::GameWindow* ui;
signals:

};

#endif // GAMEWINDOW_H
