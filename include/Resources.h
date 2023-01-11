#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_TTF
#ifndef RESOURCES_HEADERS
#define RESOURCES_HEADERS

#include <string>
#include <memory>
#include <unordered_map>
#include "SDL_include.h"

class Resources{
public:
    static std::shared_ptr<SDL_Texture> GetImage(std::string file);
    static void ClearImages();

    static std::shared_ptr<Mix_Music> GetMusic(std::string file);
    static void ClearMusic();

    static std::shared_ptr<Mix_Chunk> GetSound(std::string file);
    static void ClearSounds();

    static std::shared_ptr<TTF_Font> GetFont(std::string file, int size);
    static void ClearFonts();
private:
    static std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> imageTable;
    static std::unordered_map<std::string, std::shared_ptr<Mix_Music>> musicTable;
    static std::unordered_map<std::string, std::shared_ptr<Mix_Chunk>> soundTable;
    static std::unordered_map<std::string, std::shared_ptr<TTF_Font>> fontTable;
};

#endif