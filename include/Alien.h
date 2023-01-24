#ifndef ALIEN_HEADERS
#define ALIEN_HEADERS

#include "Component.h"
#include "Vec2.h"
#include "Minion.h"
#include <memory>
#include <queue>


class Alien: public Component{
public:
    Alien(GameObject& associated, int numMinions);
    ~Alien();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
private:
    class Action{
    public:
        enum actionType{
            MOVE,
            SHOOT
        };
        Action(actionType type, float x, float y);
        Vec2 pos;
    };

    Vec2 speed;
    int hp;

    std::queue<Action> taskQueue;
    std::vector<std::weak_ptr<GameObject>> miniorArray;
};

#endif