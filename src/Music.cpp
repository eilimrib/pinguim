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
    Open(file);
}


Music::~Music(){
    Stop();
}


void Music::Play(int times){
    if(Mix_PlayMusic(music.get(), times) == -1) {
        SDL_Log("Can't play music: %s", SDL_GetError());
    }
    Mix_VolumeMusic(50);
}


void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}


void Music::Open(std::string file){
    music = Resources::GetMusic(file);
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


