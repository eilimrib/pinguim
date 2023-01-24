#ifndef MINION_HEDAERS
#define MINION_HEADERS

#include "Component.h"


class Minion: public Component{
public:
    Minion(GameObject& associated, 
           std::weak_ptr<GameObject> alienCenter,
           float arcOffsetDrag = 0);
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    bool Shoot(Vec2 target);
private:
    float arc;
    GameObject& alienCenter;
}

#endif