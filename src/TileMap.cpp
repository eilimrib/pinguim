#include "TileMap.h"
#include <fstream>
#include <iostream>
#include <sstream>

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileset) : Component(associated){
    this->SetTileSet(tileset);
    this->Load(file);
} 


void TileMap::SetTileSet(TileSet* tileset){
    this->tileset = tileset;
}


void TileMap::Load(std::string file){
    std::ifstream tileFile(file);
    if (!tileFile.is_open())
    {
        SDL_LogError(0, "tileMap file not found");
    }

    std::stringstream tileContent;
    tileContent << tileFile.rdbuf();
    std::string token;

    std::getline(tileContent, token, ',');
    mapWidth = stoi((token));
    std::getline(tileContent, token, ',');
    mapHeight = stoi(token);
    std::getline(tileContent, token, ',');
    mapDepth = stoi(token);

    for (int currentDepth = 0; currentDepth < mapDepth; currentDepth++)
    {
        std::getline(tileContent, token, '\n');
        for (int tileCell = 0; tileCell < (mapWidth * mapHeight); tileCell++)
        {
            std::getline(tileContent, token, ',');
            int currentTile = stoi(token) - 1;
            tileMatrix.push_back(currentTile);
        }
    }
}

void TileMap::Render(){

}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    // Calculate Parallax
    int tileHeight = tileset->GetTileHeight();
    int tileWidth = tileset->GetTileWidth();

    for (int posY = 0; posY < this->GetHeight(); posY++)
    {
        for (int posX = 0; posX < this->GetWidth(); posX++)
        {
            int index = At(posX, posY, layer);
            int y = posY * tileHeight;
            int x = posX * tileWidth;
            tileset->RenderTile(index, x, y);
        }
    }
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
