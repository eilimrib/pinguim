#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "Game.h"
#include "Sprite.h"
#include "Resources.h"
#include <SDL_include.h>
#include <string>
#include <iostream>


Sprite::Sprite(GameObject& associated): Component(associated){
    texture = nullptr;
    this->scale = Vec2(1, 1);
}


Sprite::Sprite(GameObject& associated, std::string file): Component(associated){
    texture = nullptr;
    this->scale = Vec2(1, 1);
    Open(file.c_str());
}


Sprite::~Sprite(){
}


void Sprite::Open(std::string file){
    int w = GetWidth();
    int h = GetWidth();

   texture = Resources::GetImage(file);

    if (texture == nullptr)
    {
        SDL_Log("Cant load sprite: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_QueryTexture(texture.get(), nullptr, nullptr, &w, &h);
    associated.box.w = w;
    associated.box.h = h;
    SetClip(0, 0, w, h);
}


void Sprite::SetClip(int x, int y, int h, int w){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.h = h;
    clipRect.w = w;
}


void Sprite::Render(int x, int y, int w, int h)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w * scale.x;
    dst.h = h * scale.y;

    if (SDL_RenderCopyEx(
            Game::GetInstance().GetRenderer(), // renderer
            texture.get(),                            // texture
            &clipRect,                          // source rect
            &dst,                                // destination rect
            associated.angleDeg,
            nullptr,
            SDL_FLIP_NONE
            ))
    {
        SDL_LogError(0, "Unable to render sprite: %s", IMG_GetError());
    }
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
    Render(associated.box.x - Camera::pos.x, associated.box.y - Camera::pos.y, associated.box.w, associated.box.h);
}


bool Sprite::Is(std::string type){
    return (type == "Sprite");
}


void Sprite::SetScale(float scaleX, float scaleY){
    float newWidth = associated.box.w * (scaleX - scale.x);
    float newHeight = associated.box.h * (scaleY - scale.y);

    associated.box.w *= (1 + (scaleX - scale.x));
    associated.box.h *= (1 + (scaleY - scale.y));
    associated.box.x -= newWidth / 2;
    associated.box.y -= newHeight / 2;

    this->scale = Vec2(scaleX, scaleY);
}


Vec2 Sprite::GetScale(){
    return this->scale;
}