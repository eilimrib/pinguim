#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include "Music.h"
#include "Resources.h"
#include <SDL_include.h>
#include <string>


Music::Music(){
    music = nullptr;
}


Music::Music(std::string file){
    Open(file.c_str());
}


Music::~Music(){
    Stop();
}


void Music::Play(int times){
    if(music == nullptr){
        SDL_LogError(0, "Null music: %s", SDL_GetError());
        return;
    }
    Mix_PlayMusic(music, times);
}


void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}


void Music::Open(std::string file){
    music = Resources::GetMusic(file.c_str());
    if(music == nullptr){
        SDL_LogError(0, "Can't open music file: %s", SDL_GetError());
        return;
    }
}


bool Music::IsOpen(){
    if(music == nullptr){
        return false;
    }
    return true;
}


