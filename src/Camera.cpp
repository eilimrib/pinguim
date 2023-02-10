#include <Camera.h>
#include <InputManager.h>
#include <Game.h>


Vec2 Camera::pos;
Vec2 Camera::speed;
GameObject* Camera::focus = nullptr;


void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
    pos = Vec2();
    speed = Vec2();
}


void Camera::Unfollow(){
    focus = nullptr;
}


void Camera::Update(float dt){
    if (focus != nullptr){
        Game &game = Game::GetInstance();
        pos.x = focus->box.Center().x - (game.width/2);
        pos.y = focus->box.Center().y - (game.height/2);
    }
    else{
        InputManager *input = &InputManager::GetInstance();
        if(input->IsKeyDown(LEFT_ARROW_KEY)){
            speed += Vec2(-1, 0);
        }
        else if (input->IsKeyDown(RIGHT_ARROW_KEY)){
            speed += Vec2(1, 0);
        }
        else if(input->IsKeyDown(UP_ARROW_KEY)){
            speed += Vec2(0, 1);
        }
        else if(input->IsKeyDown(DOWN_ARROW_KEY)){
            speed += Vec2(0, -1);
        }
        pos = speed * dt * 200;
    }
}