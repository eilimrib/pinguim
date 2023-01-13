#define INCLUDE_SDL

#include <InputManager.h>
#include <SDL_include.h>
#include <iostream>


InputManager::InputManager(){
    updateCounter = 0;
    quitRequested = false;
    mouseX = 0;
    mouseY = 0;
    for (int i = 0; i < 6; i++){
        mouseUpdate[i] = 0;
        mouseState[i] = false;
    }
}


InputManager::~InputManager(){
    
}


void InputManager::Update()
{
    updateCounter++;
    SDL_Event event;
    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequested = false;
    while (SDL_PollEvent(&event)){
        switch (event.type){
        case SDL_KEYDOWN:
            if (event.key.repeat){
                break;
            }
            keyState[event.key.keysym.sym] = true;
            keyUpdate[event.key.keysym.sym] = updateCounter;
            break;

        case SDL_KEYUP:
            keyState[event.key.keysym.sym] = false;
            keyUpdate[event.key.keysym.sym] = updateCounter;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event.key.repeat){
                break;
            }
            mouseState[event.button.button] = true;
            mouseUpdate[event.button.button] = updateCounter;
            break;

        case SDL_MOUSEBUTTONUP:
            mouseState[event.button.button] = false;
            mouseUpdate[event.button.button] = updateCounter;
            break;

        case SDL_QUIT:
            quitRequested = true;
            break;

        default:
            break;
        }
    }
}



InputManager& InputManager::GetInstance(){
    static InputManager instance;
    return instance;
}


bool InputManager::KeyPress(int key){
    std::unordered_map<int, int>::const_iterator iter = keyUpdate.find(key);
    if (iter != keyUpdate.end()){
        if (iter->second == updateCounter)
        {
            return keyState.find(key)->second;
        }
    }

    return false;
}


bool InputManager::KeyRelease(int key){
    std::unordered_map<int, int>::const_iterator iter = keyUpdate.find(key);
    if (iter != keyUpdate.end() && iter->second == updateCounter){
        std::cout << "key released\n";
        return !keyState.find(key)->second;
    }

    return false;
}


bool InputManager::IsKeyDown(int key){
    std::unordered_map<int, bool>::const_iterator iter = keyState.find(key);

    if (iter != keyState.end()){
        return keyState.find(key)->second;
    }

    return false;
}


bool InputManager::MousePress(int button){
    if (mouseUpdate[button] == updateCounter){
        return IsMouseDown(button);
    }

    return false;
}


bool InputManager::MouseRelease(int button){
    if (mouseUpdate[button] == updateCounter){
        return !IsMouseDown(button);
    }
    return false;
}


bool InputManager::IsMouseDown(int button){
    return mouseState[button];
}



bool InputManager::QuitRequested(){
    return this->quitRequested;
}


int InputManager::GetMouseX(){
    return this->mouseX;
}



int InputManager::GetMouseY(){
    return this->mouseY;
}