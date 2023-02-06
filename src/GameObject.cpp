#include "Component.h"
#include "GameObject.h"

#include <algorithm>

GameObject::GameObject(){
    isDead = false;
    started = false;
    this->angleDeg = 0;
}


GameObject::~GameObject(){
    components.clear();
}


void GameObject::Update(float dt){
  for(int i = 0; i < (int) components.size(); i++){
        components[i]->Update(dt);
    }
}


void GameObject::Render(){
    for(int i = 0; i < (int) components.size(); i++){
        components[i]->Render();
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
    // for(int i = 0; i < (int) components.size(); i++){
    //     if(components[i] == cpt){
    //         components.erase(components.begin() + i);
    //     }
    // }
    components.erase(remove(components.begin(),components.end(), cpt), components.end());
}


Component* GameObject::GetComponent(std::string type){
    for(int i = 0; i < (int) components.size(); i++){
        if(components[i]->Is(type)){
            return components[i];
        }
    }
    return nullptr;
}


void GameObject::Start(){
    for(int i = 0; i < (int) components.size(); i++){
        components[i]->Start();
    }
}