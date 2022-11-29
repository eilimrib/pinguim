#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#ifndef SOUND_HEADERS
#define SOUND_HEADERS

#include "SDL_include.h"
#include "Component.h"
#include <string>


class Sound: public Component{
public:
    Sound(GameObject& associated);
    Sound(GameObject& associated, std::string file);
    ~Sound();

    void Play(int times = 1);
    void Stop();
    void Open(std::string file);
    bool IsOpen();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
private:
    Mix_Chunk * chunk;
    int channel;
};
#endif