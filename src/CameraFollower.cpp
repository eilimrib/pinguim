#include "CameraFollower.h"
#include "Camera.h"


CameraFollower::CameraFollower(GameObject& associated): Component(associated){

}


void CameraFollower::Update(float dt){
    associated.box.SetOrigin(Camera::pos);
}


void CameraFollower::Render(){

}


bool CameraFollower::Is(std::string type){
    return (type == "CameraFollower");
}