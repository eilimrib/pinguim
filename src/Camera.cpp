#include <Camera.h>


void Camera::Follow(GameObject* newFocus){
    this->focus = newFocus;
}


void Camera::Unfollow(){
    this->focus = nullptr;
}


void Camera::Update(float dt){

}