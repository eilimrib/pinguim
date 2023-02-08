#define INCLUDE_SDL
#ifndef GAME_HEADERS
#define GAME_HEADERS

#include "State.h"
#include "Resources.h"
#include <string>
#include <SDL_include.h>

#define DEFAULT_HEIGHT 600
#define DEFAULT_WIDTH 1024
#define DEFAULT_GAME_NAME "Eileen Lima Ribeiro 16/0049458"


class Game{
public:
    ~Game();

    SDL_Renderer * GetRenderer();
    State& GetState();

    static Game& GetInstance();
    float GetDeltaTime();
    void run();
    int width;
    int height;
private:
    int frameStart;
    float dt;
    void CalculateDeltaTime();
    static Game *   instance;
    SDL_Window *    window;
    SDL_Renderer *  renderer;
    State *         state;

    Game();
    Game(std::string title, int width, int height);
};
#endif