#include "tile.h"
#include <QDebug>

const QString Tile::tile1_path =  ":/gamecomponents/images/tile1.png";

Tile::Tile() : Tile(0,0) {
}

Tile::Tile(int x, int y)
{
    QPixmap tilePixmap(tile1_path);
    this->setPixmap(tilePixmap);
    this->setFieldPos(x, y);
}

void Tile::setFieldX (int x){
    setFieldPos(x, fieldY);
}
void Tile::setFieldY (int y){
    setFieldPos(fieldX, y);
}

void Tile::setFieldPos(int x, int y)
{
    fieldX = x;
    fieldY = y;
    this->setPos(posXFirstTile + tileStep*x, posYFirstTile + tileStep*y);
}

int Tile::getFieldX() const
{
    return fieldX;
}

int Tile::getFieldY() const
{
    return fieldY;
}
