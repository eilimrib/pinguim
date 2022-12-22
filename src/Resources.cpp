#include "Resources.h"
#include "Game.h"

std::unordered_map<std::string, SDL_Texture *> Resources::imageTable;
std::unordered_map<std::string, Mix_Music *> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk *> Resources::soundTable;


Resources::Resources(){
}


Resources::~Resources(){
}


SDL_Texture* Resources::GetImage(std::string file){
    SDL_Texture* texture;

    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    imageTable[file] = texture;

    return texture;
}


void Resources::ClearImages(){
    for(auto &i: imageTable){
        SDL_DestroyTexture(i.second);
    }
    imageTable.clear();
}


Mix_Music* Resources::GetMusic(std::string file){
    Mix_Music* music;

    music = Mix_LoadMUS(file.c_str());
    musicTable[file] = music;

    return music;
}

void Resources::ClearMusic(){
    for(auto &i: musicTable){
        Mix_FreeMusic(i.second);
    }
    musicTable.clear();
}


Mix_Chunk* Resources::GetSound(std::string file){
    Mix_Chunk* sound;

    sound = Mix_LoadWAV(file.c_str());
    soundTable[file] = sound;

    return sound;
}

void Resources::ClearChunks(){
    for(auto &i: soundTable){
        Mix_FreeChunk(i.second);
    }
    soundTable.clear();
}
