#include <iostream>
#include "Face.h"

Face::Face(GameObject &associated) : Component(associated)
{
    hitpoints = 30;
}

Face::~Face()
{
}

void Face::Damage(int damage)
{
    hitpoints -= damage;

    if (hitpoints <= 0)
    {
        // play sound here and destroy on state
        // RequestDelete must come first to avoid multiple sounds
        associated.RequestDelete();
        Sound *soundToRemove = (Sound *)associated.GetComponent("Sound");
        if (soundToRemove != nullptr)
        {
            soundToRemove->Play();
        }
    }
}

void Face::Update(float dt)
{
}

void Face::Render()
{
}

bool Face::Is(std::string type)
{
    return (type == "Face");
}