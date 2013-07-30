#include "game.h"
#include "util.h"
#include <iostream>
#include <string>
#include "text.h"

#include <iostream>
using namespace std;

Game::Game(){
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		cout << "SDL not initialized." << endl;
	
	if(TTF_Init() == -1)
		cout << "TTF not initialized." << endl;

	this->screen = SDL_SetVideoMode(SCREEN_W,SCREEN_H,SCREEN_BPP,SDL_SWSURFACE);
	SDL_WM_SetCaption("Eater",NULL);
	TTF_Init();
	this->running = true;

	//Game stuff
	this->center = new Center();
	this->player = new Player();

	this->stream1 = new Stream(1);
	this->stream2 = new Stream(2);
	this->stream3 = new Stream(3);
	this->stream4 = new Stream(4);
}

Game::~Game(){
	SDL_FreeSurface(this->screen);
	TTF_Quit();
	SDL_Quit();
}

void Game::run(){

	this->delta.start();
	
	while(this->running){
		this->start = SDL_GetTicks();
		//Events
		while(SDL_PollEvent(&this->events)){
			switch(this->events.type){
				case SDL_QUIT:
					this->running = false;
				break;
				case SDL_KEYDOWN:
                    switch (events.key.keysym.sym) {
                    	case SDLK_RIGHT:
                    		this->player->move(RIGHT);
                    	break;
                    	case SDLK_LEFT:
                    		this->player->move(LEFT);
                    	break;
                    	case SDLK_ESCAPE:
                        	this->running = false;
                        break;
                        default:;
                    }
			}
		}
		//Logic
		this->player->update(delta.get_ticks());

		this->delta.start();
		//Render
		SDL_FillRect(screen,&screen->clip_rect,SDL_MapRGB(screen->format,0x00,0x00,0x00)); //paints everything with black
		this->center->draw();
		this->player->draw();
		this->stream1->draw();
		this->stream2->draw();
		this->stream3->draw();
		this->stream4->draw();
		SDL_Flip(screen);
		
		//FPS control
		if(1000/FPS > SDL_GetTicks() - this->start)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - this->start));
	}
}
