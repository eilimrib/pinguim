#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#ifndef SPRITE_HEADERS
#define SPRITE_HEADERS

#include "SDL_include.h"
#include "Component.h"
#include "GameObject.h"
#include <string>

class Sprite : public Component{
public:
    Sprite(GameObject &associated);
    Sprite(GameObject &associated, std::string file);
    ~Sprite();

    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render();
    void Render(int x, int y, int w, int h);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    void Update(float dt);
    bool Is(std::string type);
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;
};
#endif