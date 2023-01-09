#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include "SDL_include.h"
#include "GameObject.h"
#include "Face.h"
#include "Sprite.h"
#include "State.h"
#include "TileMap.h"
#include "TileSet.h"
#include <string>
#include "math.h"



State::State(){
    quitRequested = false;

	GameObject *goOcean = new GameObject();

	Sprite *bg = new Sprite(*goOcean, "assets/img/ocean.jpg");
	goOcean->AddComponent(bg);
	objectArray.emplace_back(goOcean);

 	GameObject *gameObjectMap = new GameObject();

    TileSet *tileSet = new TileSet(64, 64, "assets/img/tileset.png");
    TileMap *tileMap = new TileMap(*gameObjectMap, "assets/map/tileMap.txt", tileSet);
    gameObjectMap->AddComponent(tileMap);
    gameObjectMap->box.x = 0;
    gameObjectMap->box.y = 0;
    objectArray.emplace_back(gameObjectMap);

	music = new Music("asssets/audio/stageStage.ogg");
	music->Play();
}

State::~State(){
    objectArray.clear();
}


void State::Update(float dt){
    if(SDL_QuitRequested()){
        quitRequested = true;
    }
}


bool State::QuitRequested(){
    return quitRequested;
}

void State::AddObject(GameObject* go){
	std::shared_ptr<GameObject> shared(go);
	objectArray.emplace_back(shared);
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

			// Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
			for(int i = objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				std::shared_ptr<GameObject> shared(objectArray[i].get());
				// Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
				// O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
				// ao usar get(), violamos esse princípio e estamos menos seguros.
				// Esse código, assim como a classe Face, é provisório. Futuramente, para
				// chamar funções de GameObjects, use objectArray[i]->função() direto.

				if(shared->box.Contains((float)mouseX, (float)mouseY) ) {
					Face* face = (Face*)shared->GetComponent( "Face" );
					if ( nullptr != face ) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (só queremos acertar um)
						break;
					}
				}
			}
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