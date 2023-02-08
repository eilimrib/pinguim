#ifndef MINION_HEDAERS
#define MINION_HEADERS

#include "Component.h"
#include "Bullet.h"
#include <memory>

class Minion: public Component{
public:
    Minion(GameObject& associated, 
           std::weak_ptr<GameObject> alienCenter,
           float arcOffsetDrag = 0);
    void Update(float dt);
    void Render();
    void Shoot(Vec2 target);
    bool Is(std::string type);
private:
    float arc;
    std::weak_ptr<GameObject> alienCenter;
};

#endif