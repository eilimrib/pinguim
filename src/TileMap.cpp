#include "TileMap.h"


TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileset) : Component(associated){
    SetTileSet(tileset);
    Load(file);
} 


void TileMap::SetTileSet(TileSet* tileset){
    this->tileset = tileset;
}


void TileMap::Load(std::string file){
    
}

void TileMap::Render(){

}


int& TileMap::At(int x, int y, int z){
   z = z * mapHeight * mapWidth;
   y = y * mapWidth;
   return tileMatrix.at(x+y+z);
}

int TileMap::GetDepth(){
    return mapDepth;
}


int TileMap::GetHeight(){
    return mapHeight;
}


int TileMap::GetWidth(){
    return mapWidth;
}


void TileMap::Update(float dt){   
}   


bool TileMap::Is(std::string type){
    return (type == "TileMap");
}