#define INCLUDE_SDL

#include "SDL_include.h"
#include "GameObject.h"

GameObject::GameObject(){
    isDead = false;
    components = nullptr;
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

bool GameObject::AddComponent(Component* cpt){
    components.emplace_back(cpt);
}

bool GameObject::RemoveComponent(Component* cpt){
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