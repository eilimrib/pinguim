#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

#include "Game.h"
#include <string>
#include <SDL_include.h> 


Game* Game::instance = nullptr;

Game& Game::GetInstance() {
    if(instance != nullptr){
        return *instance;
    }
    new Game();
    return *instance;
}

Game::Game(){
    if(instance != nullptr){
        return;
    }
    instance = this;
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
        SDL_GetError();
    }

    if(!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
        SDL_GetError();
    }

    if(Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3)){
        SDL_GetError();
    }
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);
    Mix_AllocateChannels(32);
    this->width = DEFAULT_WIDTH;
    this->height = DEFAULT_HEIGHT;
    this->window = SDL_CreateWindow(DEFAULT_GAME_NAME, 
                              SDL_WINDOWPOS_CENTERED, 
                              SDL_WINDOWPOS_CENTERED, 
                              this->width, 
                              this->height, 
                              0);

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    this->state = new State();
    this->state->Start();
    this->dt = 0.0;
    this->frameStart = 0;
}


Game::Game(std::string title, int width, int height){
    if(instance != nullptr){
        return;
    }
    instance = this;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER)){
        SDL_GetError();
    }

    if(!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)){
        SDL_GetError();
    }

    if(Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3)){
        SDL_GetError();
    }
    this->width = width;
    this->height = height;
    window = SDL_CreateWindow(title.c_str(), 
                              SDL_WINDOWPOS_CENTERED, 
                              SDL_WINDOWPOS_CENTERED, 
                              width, 
                              height, 
                              0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    state = new State();
}


Game::~Game(){
    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    
    SDL_DestroyWindow(window);
    window = nullptr;

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}


State& Game::GetState(){
    return *state;
}


SDL_Renderer* Game::GetRenderer(){
    return renderer;
}



void Game::run(){
    while(!state->QuitRequested()){
        CalculateDeltaTime();
        state->Update(dt);
        state->Render();

        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}


void Game::CalculateDeltaTime(){
    this->dt = this->frameStart - SDL_GetTicks();
    this->frameStart++;
}


float Game::GetDeltaTime(){
    return this->dt;
}