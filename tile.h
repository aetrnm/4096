#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Tile : public QGraphicsPixmapItem
{
public:
    Tile();
    //~Tile();
    void setX(int x);
    void setY(int y);
private:
    int fieldX = 0;
    int fieldY = 0;
    int cost = 1;
};

#endif // TILE_H
