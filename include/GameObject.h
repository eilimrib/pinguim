#define INCLUDE_SDL

#include "SDL_include.h"
#include "Component.h"
#include "Rect.h"
#include <string>

class GameObject{
public:
    GameObject();
    ~GameObject();

    void Update(float dt);
    void Render();
    bool isDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(std::string type);
    Rect box;
private:
    std::vector <Component *> components;
    bool isDead;
}