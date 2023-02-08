#include "Bullet.h"

Bullet::Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, std::string sprite) : Component(associated) {
    associated.AddComponent(new Sprite(associated, sprite));

    this->speed = Vec2::Rotate(Vec2(speed, 0), angle);
    this->distanceLeft = maxDistance;
    this->damage = damage;
}


void Bullet::Update(float dt){
    associated.box = associated.box + speed * dt;
    this->distanceLeft -= Vec2::Mag(speed * dt);
    if (this->distanceLeft <= 0){
        associated.RequestDelete();
    }
}


void Bullet::Render(){

}


bool Bullet::Is(std::string type){
    return (type == "Bullet");
}


int Bullet::GetDamage(){
    return damage;
}