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
private:
    void Input();
    void AddObject(GameObject* obj);
    std::vector<std::shared_ptr<GameObject>> objectArray;
    Music music;
    bool quitRequested;
};
#endif