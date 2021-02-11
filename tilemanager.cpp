#include "tilemanager.h"
#include <QDebug>
#include <QKeyEvent>

TileManager::TileManager(QGraphicsScene* scene)
{
    this->grabKeyboard();
    this->scene = scene;
    this->createTile(2,2);
    this->createTile(1,1);
}

//void TileManager::keyReleaseEvent(QKeyEvent *event)
//{
//    if (event->key() == Qt::Key_Up) {
//        for(int i = 0; i < vectorTiles.size(); i++){
//            Tile* t = vectorTiles[i];
//            up(t);
//        }
//    }
//    else if(event->key() == Qt::Key_Down){
//        for(int i = 0; i < vectorTiles.size(); i++){
//            Tile* t = vectorTiles[i];
//            down(t);
//        }
//    }
//    else if(event->key() == Qt::Key_Left){
//        for(int i = 0; i < vectorTiles.size(); i++){
//            Tile* t = vectorTiles[i];
//            left(t);
//        }
//    }
//    else if(event->key() == Qt::Key_Right){
//        for(int i = 0; i < vectorTiles.size(); i++){
//            Tile* t = vectorTiles[i];
//            right(t);
//        }
//    }
//}

void TileManager::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_Up:
            for(int i = 0; i < vectorTiles.size(); i++){
                Tile* t = vectorTiles[i];
                up(t);
            }
            break;
        case Qt::Key_Down:
            for(int i = 0; i < vectorTiles.size(); i++){
                Tile* t = vectorTiles[i];
                down(t);
            }
            break;
        case Qt::Key_Left:
            for(int i = 0; i < vectorTiles.size(); i++){
                Tile* t = vectorTiles[i];
                left(t);
            }
            break;
        case Qt::Key_Right:
            for(int i = 0; i < vectorTiles.size(); i++){
                Tile* t = vectorTiles[i];
                right(t);
            }
            break;
        default:
            return;
    }
}

void TileManager::createTile(int x, int y)
{
    Tile* tile = new Tile(x, y);
    vectorTiles.push_back(tile);
    scene->addItem(tile);
    fieldTilesExistence[x][y] = true;
}

void TileManager::up(Tile* tile)
{
    int posToMove = tile->getFieldY();
    fieldTilesExistence[tile->getFieldX()][tile->getFieldY()] = false;
    for(int i = tile->getFieldY(); i > 0; i--){
        if(fieldTilesExistence[tile->getFieldX()][i-1] == false){
            posToMove = i-1;
        }
        else{
            posToMove = i;
            break;
        }
    }
    tile->setFieldY(posToMove);
    fieldTilesExistence[tile->getFieldX()][posToMove] = true;
}

void TileManager::left(Tile* tile)
{
    int posToMove = tile->getFieldX();
    fieldTilesExistence[tile->getFieldX()][tile->getFieldY()] = false;
    for(int i = tile->getFieldX(); i > 0; i--){
        if(fieldTilesExistence[i-1][tile->getFieldY()] == false){
            posToMove = i-1;
        }
        else{
            posToMove = i;
            break;
        }
    }
    tile->setFieldX(posToMove);
    fieldTilesExistence[posToMove][tile->getFieldY()] = true;
}

void TileManager::right(Tile* tile)
{
    int posToMove = tile->getFieldX();
    fieldTilesExistence[tile->getFieldX()][tile->getFieldY()] = false;
    for(int i = tile->getFieldX(); i < 3; i++){
        if(fieldTilesExistence[i+1][tile->getFieldY()] == false){
            posToMove = i+1;
        }
        else{
            posToMove = i;
            break;
        }
    }
    tile->setFieldX(posToMove);
    fieldTilesExistence[posToMove][tile->getFieldY()] = true;
}

void TileManager::down(Tile* tile)
{
    int posToMove = tile->getFieldY();
    fieldTilesExistence[tile->getFieldX()][tile->getFieldY()] = false;
    for(int i = tile->getFieldY(); i < 3; i++){
        if(fieldTilesExistence[tile->getFieldX()][i+1] == false){
            posToMove = i+1;
        }
        else{
            posToMove = i;
            break;
        }
    }
    tile->setFieldY(posToMove);
    fieldTilesExistence[tile->getFieldX()][posToMove] = true;
}
