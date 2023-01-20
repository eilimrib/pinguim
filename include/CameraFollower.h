#ifndef CAMERA_FOLLOWER_HEADERS
#define CAMERA_FOLLOWER_HEADERS
#include <Component.h>


class CameraFollower: public Component{
public:
    CameraFollower(GameObject& associated);

    void Update(float dt);
    void Render();
    bool Is(std::string type);
};
#endif