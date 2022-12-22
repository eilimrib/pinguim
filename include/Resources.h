#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#ifndef RESOURCES_HEADERS
#define RESOURCES_HEADERS

#include <string>
#include <unordered_map>
#include "SDL_include.h"

class Resources{
public:
    SDL_Texture* GetImage(std::string file);
    void ClearImages();

    Mix_Music* GetMusic(std::string file);
    void ClearMusic();

    Mix_Chunk* GetSound(std::string file);
    void ClearChunks();
private:
    std::unordered_map<std::string, SDL_Texture*> imageTable;
    std::unordered_map<std::string, Mix_Music*> musicTable;
    std::unordered_map<std::string, Mix_Chunk*> soundTable;
};


#endif