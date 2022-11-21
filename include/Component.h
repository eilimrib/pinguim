#define INCLUDE_SDL

#include "SDL_include.h"
#include "GameObject.h"
#include <string>


class Component{
public:
    Component(GameObject& associated);
    virtual ~Component();
    void virtual pure Update(float dt);
    void virtual pure Render();
    bool virtual pure Is(std::string type);
protected:
    GameObject& associated;
};