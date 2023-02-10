#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include "GameObject.h"
#include "Sprite.h"
#include "State.h"
#include "TileMap.h"
#include "TileSet.h"
#include <string>
#include "math.h"



State::State(){
    quitRequested = false;
	started = false;
}

State::~State(){
    objectArray.clear();
}


void State::LoadAssets(){
	GameObject *gameObjectOcean = new GameObject();

    Sprite *bg = new Sprite(*gameObjectOcean, "assets/img/ocean.jpg");
    CameraFollower *OceanFollower = new CameraFollower(*gameObjectOcean);
    gameObjectOcean->AddComponent(bg);
    gameObjectOcean->AddComponent(OceanFollower);

    objectArray.emplace_back(gameObjectOcean);

    GameObject *gameObjectMap = new GameObject();

    TileSet *tileSet = new TileSet(64, 64, "assets/img/tileset.png");
    TileMap *tileMap = new TileMap(*gameObjectMap, "assets/map/tileMap.txt", tileSet);
    gameObjectMap->AddComponent(tileMap);
    gameObjectMap->box.SetOrigin(Vec2(0, 0));

    objectArray.emplace_back(gameObjectMap);

    GameObject *gameObjectAlien = new GameObject();
    Alien *alien = new Alien(*gameObjectAlien, 3);

    gameObjectAlien->AddComponent(alien);
    gameObjectAlien->box.SetOrigin((Vec2(1024, 600) - gameObjectAlien->box.Measures())/2);

    objectArray.emplace_back(gameObjectAlien);

    Camera::Follow(gameObjectAlien);

    music = new Music("assets/audio/stageState.ogg");
    music->Play();
}


void State::Update(float dt){
	Camera::Update(dt);

	if (InputManager::GetInstance().QuitRequested()){
		quitRequested = true;
	}

	for (unsigned i = 0; i < objectArray.size(); i++){
		objectArray[i]->Update(dt);
	}
}


void State::Render(){
	for (unsigned i = 0; i < objectArray.size(); i++){
		objectArray[i]->Render();
	}

}

bool State::QuitRequested(){
    return quitRequested;
}

std::weak_ptr<GameObject> State::AddObject(GameObject* go){
	std::shared_ptr<GameObject> shared(go);
	objectArray.emplace_back(shared);
	return shared;
}


std::weak_ptr<GameObject> State::GetObjectPtr(GameObject* go){
	std::shared_ptr<GameObject> shared;
	for(int i = 0; i < (int) objectArray.size(); i++){
		if(go == objectArray[i].get()){
			shared = objectArray[i];
			return shared;
		}
	}
	shared = nullptr;
	return shared;
}


void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para terminação
		if(event.type == SDL_QUIT) {
			quitRequested = true;
		}
		
		// Se o evento for clique...
		if(event.type == SDL_MOUSEBUTTONDOWN) {
		}
		if( event.type == SDL_KEYDOWN ) {
			// Se a tecla for ESC, setar a flag de quit
			if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			}
			// Se não, crie um objeto
			else {
				Vec2 objPos = Vec2( 200, 0 ).GetRotated( -M_PI + M_PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
				GameObject go = GameObject();
				go.box.x = objPos.x;
				go.box.y = objPos.y;
				AddObject(&go);
			}
		}
	}

}


void State::Start(){
	LoadAssets();
	for(int i = 0; i < (int) objectArray.size(); i++){
		objectArray[i]->Start();
	}
	started = true;
}