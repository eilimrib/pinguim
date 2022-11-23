#include "Component.h"
#include "GameObject.h"

#include <algorithm>

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    components.clear();
}

void GameObject::Update(float dt){
  for(auto &cpt: components){
        cpt->Update(dt);
    }
}

void GameObject::Render(){
    for(auto &cpt: components){
        cpt->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    std::remove_if(components.begin(), components.end(), cpt);
}

Component* GameObject::GetComponent(std::string type){
    for(auto &cpt: components){
        if(cpt->Is(type)){
            return cpt;
        }
    }
    return nullptr;
}