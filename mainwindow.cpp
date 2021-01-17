#include "gamewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->exitButton, &QAbstractButton::clicked, this, &MainWindow::exit);
    connect(this->ui->startButton, &QAbstractButton::clicked, this, &MainWindow::start);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exit()
{
    this->close();
}

void MainWindow::start()
{
    GameWindow* w = new GameWindow();
    w->show();
    this->close();
}

