#include "gamewindow.h"
#include "tile.h"
#include "ui_gamewindow.h"
#include "tilemanager.h"

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::GameWindow)
{
    // connects ui description with the window
    ui->setupUi(this);

    // load bg image to memory
    QPixmap background(":/gamecomponents/images/field.png");
    // get image size
    auto size = background.size();
    // set the size of the window
    this->setFixedSize(size.width(), size.height()+20);
    // set the size of the view within the window
    ui->graphicsView->setFixedSize(size.width(), size.height());
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // create scene
    QGraphicsScene* scene = new QGraphicsScene();
    QRectF sceneRect = QRectF(0,0,size.width(), size.height());
    scene->setSceneRect(sceneRect);
    //ui->graphicsView->setSceneRect(sceneRect);
    // set scene to view
    ui->graphicsView->setScene(scene);
    // create pixmap item based on background
    QGraphicsPixmapItem* bgItem = new QGraphicsPixmapItem(background);
    // analogous to:
    // auto bgItem = new QGraphicsPixmapItem();
    // bgItem->setPixmap(background);

    // put bg on the scene
    scene->addItem(bgItem);
    bgItem->setPos(0, 0);
    ui->graphicsView->update();
    TileManager* tm = new TileManager(scene);
}

GameWindow::~GameWindow()
{
    delete ui;
}
