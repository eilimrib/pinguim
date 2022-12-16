#ifndef TILEMAP_HEADERS
#define TILEMAP_HEADERS

#include "Component.h"
#include "TileSet.h"
#include <vector>

class TileMap: public Component{
public:
    TileMap(GameObject& associated, std::string file, TileSet* tileset);
    void Load(std::string file);
    void SetTileSet(TileSet* tileset);
    int& At(int x, int y, int z = 0);
    void Render();
    void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
    int GetWidth();
    int GetHeight();
    int GetDepth();
    void Update(float dt);
    bool Is(std::string type);
private:
    std::vector<int> tileMatrix;
    TileSet* tileset;
    int mapWidth;
    int mapHeight;
    int mapDepth;
};

#endif