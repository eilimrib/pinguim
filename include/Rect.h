#define INCLUDE_SDL

#include "SDL_include.h"
#include <string>

class Rect{
    private:
    float x, y, w, h;
    public:
    Rect();
    Rect(float x, float y, float w, float h);
};