#ifndef GAMEOBJECT_HEADERS
#define GAMEOBJECT_HEADERS

#include "Component.h"
#include "Rect.h"
#include <string>
#include <vector>

class Component;

class GameObject {
public:
    GameObject();
    ~GameObject();

    void Update(float dt);
    void Render();
    bool IsDead();
    void Start();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(std::string type);
    Rect box;
private:
    std::vector <Component *> components;
    bool isDead;
    bool started;
};

#endif