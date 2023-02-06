#include "Minion.h"
#include "Sprite.h"
#include <memory>


Minion::Minion(GameObject& associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDrag) : Component(associated){
    this->alienCenter = alienCenter;
    this->arc = arcOffsetDrag;
    Sprite *minionSprite = new Sprite(associated, "assets/img/minion.png");
    associated.AddComponent(minionSprite);

    std::shared_ptr<GameObject> gameObject = alienCenter.lock();
    Vec2 origin = gameObject->box.Center() + (associated.box.Measures() / 2);
    associated.box.SetOrigin(origin);
    associated.angleDeg = this->arc;
    associated.AddComponent(minionSprite);
}


void Minion::Update(float dt){
    Vec2 minionCenter = associated.box.Measures() / 2;
    Vec2 aCenter = alienCenter.lock()->box.Center();
    Vec2 mCenter = associated.box.Center();
    Vec2 initialPos = aCenter - minionCenter + Vec2(150, 0).GetRotated(this->arc);

    this->arc += 1 / (M_PI * 16);

    associated.box.SetOrigin(initialPos);
    associated.angleDeg = -(mCenter.Direct(aCenter) * 180) / (M_PI);
}


void Minion::Render(){

}


bool Minion::Is(std::string type){
    return (type == "Minion");
}


bool Minion::Shoot(Vec2 target){
    
}