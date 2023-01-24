#include "Alien.h"
#include "Sprite.h"


Alien::Alien(GameObject& associated, int numMinions): Component(associated){
    Sprite *alienSprite = new Sprite(associated, "assets/img/alien.png");
    associated.AddComponent(alienSprite);

    this->speed = Vec2();
    this->hp = 30;
}

bool Alien::Is(std::string type){
    return (type == "Alien");
}