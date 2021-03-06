#ifndef TEXT_H
#define TEXT_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

#include <string>
#include <iostream>

enum Color{
	RED,
	GREEN,
	BLUE,
	WHITE,
	BLACK
};

enum RenderType{
	SOLID,
	SHADED,
	BLENDED
};

using namespace std;

class Text{

	TTF_Font* font;

	SDL_Surface* image;
	SDL_Color color;
	SDL_Color shadedColor;

	SDL_Rect box;

	string text;
	
	int fontsize;

	RenderType renderType;

	public:
		Text(string _text, int _fontsize, int x, int y);
		~Text();

		void draw();
		void update();

		void setText(string _text);
		void setColor(Color _color);
		void setShadedColor(Color _color);
		void setFontSize(int size);
		void setFont(string _fontpath);
		void setRenderType(int _renderType);

};

#endif
