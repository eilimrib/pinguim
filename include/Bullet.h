#ifndef BULLET_HEADERS
#define BULLET_HEADERS

#include "Component.h"
#include "Sprite.h"

class Bullet: public Component{
public:
    Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, std::string sprite);

    void Update(float dt);
    void Render();
    bool Is(std::string type);
    int GetDamage();
private:
    Vec2 speed;
    int damage;
    float distanceLeft;
};
#endif