#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/gamecomponents/images/field.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    this->setFixedSize(QSize(479, 656));
}

GameWindow::~GameWindow()
{
    delete ui;
}
