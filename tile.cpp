#include "tile.h"
#include <QDebug>

const QString Tile::tile1_path =  ":/gamecomponents/images/tile1.png";

Tile::Tile() : Tile(0,0) {
}

Tile::Tile(int x, int y)
{
    QPixmap tilePixmap(tile1_path);
    this->setPixmap(tilePixmap);
    this->setPos(posXFirstTile + tileStep*x, posYFirstTile + tileStep*y);
}

void Tile::setX (int x){
    this->fieldX = x;
}
void Tile::setY (int y){
    this->fieldY = y;
}
