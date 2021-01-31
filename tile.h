#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Tile : public QGraphicsPixmapItem
{
public:
    Tile();
    Tile(int x, int y);

    // tile = new Tile().setX(1).setY(2);
    void setX(int x);
    void setY(int y);
    QRect fieldCoordsToImageCoords(QRect fieldsCoords);
    // H/W: implement, remove virtual and "=0" upon implementing
private:
    int fieldX = 0;
    int fieldY = 0;
    int cost = 1;
    static const QString tile1_path;
    constexpr static const double tileStep = 117.5;
    constexpr static const double posXFirstTile = 16.5;
    constexpr static const double posYFirstTile = 193;
};

#endif // TILE_H
