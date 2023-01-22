#ifndef COMPONENT_HEADERS
#define COMPONENT_HEADERS
#include "GameObject.h"
#include <string>

class GameObject;

class Component{
public:
    Component(GameObject& associated);
    virtual ~Component();
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual void Start();
    virtual bool Is(std::string type) = 0;
protected:
    GameObject& associated;
};

#endif