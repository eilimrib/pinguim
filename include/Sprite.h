#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include "Component.h"
#include <string>


class Sprite: public Component{
public:
    Sprite(GameObject& associated);
    Sprite(GameObject& associated, std::string file);
    ~Sprite();

    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render()
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
private:
    SDL_Texture * texture;
    int width;
    int height;
    SDL_Rect clipRect;
};