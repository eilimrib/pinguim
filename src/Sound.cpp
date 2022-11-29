#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include "Sound.h"
#include <SDL_include.h>
#include <string>


Sound::Sound(GameObject& associated): Component(associated){
    chunk = nullptr;
}


Sound::Sound(GameObject& associated, std::string file): Component(associated){
    Open(file.c_str());
}


Sound::~Sound(){
    Stop();
    Mix_FreeChunk(chunk);
}


void Sound::Play(int times){
    if(chunk == nullptr){
        SDL_LogError(0, "Null Sound: %s", SDL_GetError());
        return;
    }
    Mix_PlayChannel(channel, chunk, times);
}


void Sound::Stop(){
    Mix_HaltChannel(channel);
}


void Sound::Open(std::string file){
    chunk = Mix_LoadWAV(file.c_str());
    if(chunk == nullptr){
        SDL_LogError(0, "Can't open Sound file: %s", SDL_GetError());
        return;
    }
}


bool Sound::IsOpen(){
    if(chunk == nullptr){
        return false;
    }
    return true;
}


