#ifndef HEALTHBAR
#define HEALTHBAR

#include <SDL/SDL.h>
#include "util.h"

class HealthBar{

	SDL_Surface *image;
	SDL_Rect box;


public:
	int health_points;
	HealthBar(int hp);
	~HealthBar();

	void draw();
	void update(Uint32 delta);
	void removeHp(int quantity);
};
#endif