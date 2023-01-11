#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include "Sound.h"
#include "Resources.h"
#include <SDL_include.h>
#include <string>


Sound::Sound(GameObject& associated): Component(associated){
    chunk = nullptr;
}


Sound::Sound(GameObject& associated, std::string file): Component(associated){
    Open(file);
}


Sound::~Sound(){
}


void Sound::Play(int times){
    if(chunk == nullptr){
        SDL_LogError(0, "Null Sound: %s", SDL_GetError());
        return;
    }
    channel = Mix_PlayChannel(-1, chunk.get(), times - 1);
    Mix_VolumeChunk(chunk.get(), 50);
}


void Sound::Stop(){
    if (chunk != nullptr){
        Mix_HaltChannel(channel);
    }
}


void Sound::Open(std::string file){
    chunk = Resources::GetSound(file);
    if (chunk == nullptr){
        SDL_Log("Cant load sound: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}


bool Sound::IsOpen(){
    if(chunk == nullptr){
        return false;
    }
    return true;
}


void Sound::Update(float dt){

}


void Sound::Render(){

}


bool Sound::Is(std::string type){
    return (type == "Sound");
}
