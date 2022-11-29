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
    void AddObject(int mouseX, int mouseY);
    std::vector<std::unique_ptr<GameObject>> objectArray;
    Sprite bg;
    Music music;
    bool quitRequested;
};
#endif