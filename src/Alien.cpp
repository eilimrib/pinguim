#include "Alien.h"
#include "Sprite.h"
#include "Camera.h"
#include "Game.h"
#include "InputManager.h"
#include <cmath>


Alien::Action::Action(ActionType type, float x, float y){
    this->type = type;
    pos = Vec2(x, y);
}


Alien::Alien(GameObject& associated, int numMinions): Component(associated){
    Sprite *alienSprite = new Sprite(associated, "assets/img/alien.png");
    associated.AddComponent(alienSprite);

    this->speed = Vec2();
    this->hp = 30;
    minions = numMinions;
}


Alien::~Alien(){
    minionArray.clear();
}

void Alien::Start(){
    for (int i = 0; i < minions; i++)
    {
        State *state = &Game::GetInstance().GetState();
        std::weak_ptr<GameObject> alienCenter = state->GetObjectPtr(&associated);

        GameObject *gameObject = new GameObject();
        float minionDegree = (M_PI * i * 360 / this->minions) / 180;
        Minion *minion = new Minion(*gameObject, alienCenter, minionDegree);
        this->minionArray.push_back(state->AddObject(gameObject));
        gameObject->AddComponent(minion);
    }
}


bool Alien::Is(std::string type){
    return (type == "Alien");
}


void Alien::Render(){

}


void Alien::Update(float dt)
{
    if (this->hp <= 0)
    {
        associated.RequestDelete();
    }
    InputManager instance = InputManager::GetInstance();
    bool clickToShoot = instance.MousePress(LEFT_MOUSE_BUTTON);
    bool clickToMove = instance.MousePress(RIGHT_MOUSE_BUTTON);
    int clickPosX = instance.GetMouseX() + Camera::pos.x;
    int clickPosY = instance.GetMouseY() + Camera::pos.y;
    if (clickToMove)
    {
        taskQueue.push(Action(Action::ActionType::MOVE, clickPosX, clickPosY));
    }
    if (clickToShoot)
    {
        taskQueue.push(Action(Action::ActionType::SHOOT, clickPosX, clickPosY));
    }
    associated.angleDeg += M_PI * dt * 6;
    // Reset speed
    speed = Vec2();
    if (taskQueue.size() > 0)
    {
        Action currentAction = taskQueue.front();
        if (currentAction.type == Action::ActionType::MOVE)
        {
            Vec2 destination = currentAction.pos - (associated.box.Center());
            Vec2 currentPos = associated.box.Center();

            speed = Vec2::Normalize(destination - currentPos);
            associated.box = associated.box + speed * dt;

            bool tooClose = (std::abs(Vec2::Mag(destination) - Vec2::Mag(currentPos)) < 10);
            if (tooClose)
            {
                associated.box.SetOrigin(destination);
                taskQueue.pop();
            }
        }
        if (currentAction.type == Action::ActionType::SHOOT)
        {
            int closestMinion = Alien::GetClosestMinion(currentAction.pos);
            std::shared_ptr<GameObject> objectPointer = minionArray[closestMinion].lock();
            Minion *minionObject = (Minion *)objectPointer->GetComponent("Minion");
            minionObject->Shoot(currentAction.pos);
            taskQueue.pop();
        }
    }
}


int Alien::GetClosestMinion(Vec2 actionPos)
{
    int closestMinion = 0;
    float minDistance = MAXFLOAT;
    for (int mini = 0; mini < (int)minionArray.size(); mini++)
    {
        std::shared_ptr<GameObject> minionObject = minionArray[mini].lock();
        float minionDistance = minionObject->box.Center().DistanceTo(actionPos);
        if (minionDistance < minDistance)
        {
            closestMinion = mini;
            minDistance = minionDistance;
        }
    }
    return closestMinion;
}