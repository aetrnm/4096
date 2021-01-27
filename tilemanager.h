#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include "tile.h"

#include <QObject>

class TileManager : QObject
{
    Q_OBJECT
public:
    TileManager();
private:
    Tile* tile;
//    void down();
//    void up();
//    void left();
//    void right();
};

#endif // TILEMANAGER_H
