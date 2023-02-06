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
        enum ActionType{
            MOVE,
            SHOOT
        };
        Action(ActionType type, float x, float y);
        Vec2 pos;
        ActionType type;
    };

    Vec2 speed;
    int hp;
    int minions;

    std::queue<Action> taskQueue;
    std::vector<std::weak_ptr<GameObject>> minionArray;
    int GetClosestMinion(Vec2 actionPos);
};

#endif