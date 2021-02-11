#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include "tile.h"

#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QVector>

class TileManager : QWidget
{
    Q_OBJECT
public:
    TileManager(QGraphicsScene *scene);
    void keyReleaseEvent(QKeyEvent* event) override;
private:
    bool fieldTilesExistence[4][4] = {{false}};
    void createTile(int x, int y);
    QGraphicsScene* scene;
    void down(Tile* tile);
    void up(Tile* tile);
    void left(Tile* tile);
    void right(Tile* tile);
    QVector<Tile*> vectorTiles;
};

#endif // TILEMANAGER_H
