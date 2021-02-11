#ifndef TILE_H
#define TILE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Tile : public QGraphicsPixmapItem
{
public:
    Tile();
    Tile(int x, int y);

    void setFieldX(int x);
    void setFieldY(int y);
    void setFieldPos(int x, int y);
    //QRect fieldCoordsToImageCoords(QRect fieldsCoords);
    int getFieldX() const;
    int getFieldY() const;

private:
    int fieldX = 0;
    int fieldY = 0;
    //int cost = 1;
    static const QString tile1_path;
    constexpr static const double tileStep = 117.5;
    constexpr static const double posXFirstTile = 16.5;
    constexpr static const double posYFirstTile = 193;
};

#endif // TILE_H
