#ifndef STATE_HEADERS
#define STATE_HEADERS

#include "Sprite.h"
#include "GameObject.h"
#include "Music.h"
#include <memory>
#include <vector>

class State{
public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
    void Start();

    std::weak_ptr<GameObject> AddObject(GameObject *go);
    std::weak_ptr<GameObject> GetObjectPtr(GameObject *go);
private:
    void Input();
    std::vector<std::shared_ptr<GameObject>> objectArray;
    Music *music;
    bool quitRequested;
    bool started;
};
#endif