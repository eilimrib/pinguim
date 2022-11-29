#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "Game.h"
#include "Sprite.h"
#include <SDL_include.h>
#include <string>
#include <iostream>


Sprite::Sprite(GameObject& associated): Component(associated){
    texture = nullptr;
}


Sprite::Sprite(GameObject& associated, std::string file): Component(associated){
    texture = nullptr;
    Open(file.c_str());
}


Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}


void Sprite::Open(std::string file){
    int w = GetWidth();
    int h = GetWidth();

    if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(),file.c_str());
    if(texture == nullptr){
        SDL_LogError(0, "IMG_LoadTexture: %s", SDL_GetError());
        return;
    }

    if(!SDL_QueryTexture(texture, nullptr, nullptr, &w, &h)){
        SDL_GetError();
        return;
    }
    
    SetClip(0, 0, GetWidth(), GetHeight());
    SDL_RenderSetClipRect(Game::GetInstance().GetRenderer(), &clipRect);
}


void Sprite::SetClip(int x, int y, int h, int w){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.h = h;
    clipRect.w = w;
}


void Sprite::Render(int x, int y){
    SDL_Rect dst;

    dst.x = associated.box.x;
    dst.y = associated.box.y;
    dst.h = clipRect.h;
    dst.w = clipRect.w;

    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dst);
}


int Sprite::GetHeight(){
    return height;
}


int Sprite::GetWidth(){
    return width;
}


bool Sprite::IsOpen(){
    if(texture != nullptr){
        return true;
    }
    return false;
}


void Sprite::Update(float dt){   
}


void Sprite::Render(){

}


bool Sprite::Is(std::string type){
    return (type == "Sprite");
}