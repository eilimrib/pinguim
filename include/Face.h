#ifndef FACE_HEADERS
#define FACE_HEADERS

#include "GameObject.h"
#include "Component.h"

class Face: public Component{
public:
    Face(GameObject& associated);
    void Damage(int damage);
    void Update(float dt);
    void Render();
    bool Is(std::string type);
private:
    int hitpoints;
}; 
#endif