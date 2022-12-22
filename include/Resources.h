#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#ifndef RESOURCES_HEADERS
#define RESOURCES_HEADERS

#include <string>
#include <unordered_map>
#include "SDL_include.h"

class Resources{
public:
    Resources();
    ~Resources();
    static SDL_Texture* GetImage(std::string file);
    static void ClearImages();

    static Mix_Music* GetMusic(std::string file);
    static void ClearMusic();

    static Mix_Chunk* GetSound(std::string file);
    static void ClearChunks();
private:
    static std::unordered_map<std::string, SDL_Texture*> imageTable;
    static std::unordered_map<std::string, Mix_Music*> musicTable;
    static std::unordered_map<std::string, Mix_Chunk*> soundTable;
};


#endif