#ifndef TILESET_HEADERS
#define TILESET_HEADERS

#include "Sprite.h"
#include "GameObject.h"


class TileSet
{
private:
    Sprite *tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;

public:
    TileSet(int tileWidth, int tileHeight, std::string file);
    ~TileSet();

    void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();
};

#endif