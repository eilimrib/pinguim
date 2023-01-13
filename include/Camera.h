#ifndef CAMERA_HEADERS
#define CAMERA_HEADERS

#include <Vec2.h>
#include <GameObject.h>

class Camera{
public:
    void Follow(GameObject* newFocus);
    void Unfollow();
    void Update(float dt);
private:
    Vec2 pos;
    Vec2 speed;
    GameObject* focus;
};

#endif