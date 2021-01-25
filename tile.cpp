#include "tile.h"
#include <QDebug>

Tile::Tile() : QGraphicsPixmapItem()
{
    QPixmap tilePixmap(":/gamecomponents/images/tile1.png");
    this->setPixmap(tilePixmap);
    //this->setPos(100,100);
    qDebug() << this->boundingRect();
}

void Tile::setX (int x){
    this->fieldX = x;
}
void Tile::setY (int y){
    this->fieldY = y;
}
