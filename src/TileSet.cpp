#include "TileSet.h"


TileSet::TileSet(GameObject& associated, int tileWidth, int tileHeight, std::string file): tiles(associated){
 this->tileHeight = tileHeight;
 this-> tileWidth = tileWidth;
 this->tiles.Open(file);
 this->columns = tiles.GetWidth();
 this->rows = tiles.GetHeight();
}


void TileSet::RenderTile(unsigned index, float x, float y){
    if(index < unsigned(rows * columns)){
        int curX = (index % columns) * tileWidth;
        int curY = (index / columns) * tileHeight;

        tiles.SetClip(curX, curY, tileWidth, tileHeight);
        tiles.Render(x, y);        
    }
}

int TileSet::GetTileHeight(){
    return tileHeight;
}


int TileSet::GetTileWidth(){
    return tileWidth;
}
