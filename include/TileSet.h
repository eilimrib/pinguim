#include "Sprite.h"
#include "GameObject.h"

#ifndef TILESET_HEADERS
#define TILESET_HEADERS

class TileSet{
public:
    TileSet(GameObject &associated, int tileWidth, int tileHeight, std::string file);
    void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();
private:
    Sprite tiles;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;
};

#endif