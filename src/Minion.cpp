#include "Minion.h"
#include "Sprite.h"
#include <memory>


Minion::Minion(GameObject& associated,
               std::weak_ptr<GameObject> alienCenter,
               float arcOffsetDrag): Component(associated){
    this->alienCenter = alienCenter;
    this->arc = arcOffsetDrag;
    Sprite *minionSprite = new Sprite(associated, "assets/img/minion.png");
    associated.AddComponent(minionSprite);
}


void Minion::Update(float dt){

}


void Minion::Render(){

}


bool Minion::Is(std::string type){
    return (type == "Minion");
}


bool Minion::Shoot(Vec2 target){
    
}