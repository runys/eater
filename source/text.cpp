#include "text.h"

using namespace std;

Text::Text(string _text, int _fontsize, int x, int y){
	this->box.x = x;
	this->box.y = y;

	SDL_Color _color = {0,0,0,0};
	this->color = _color;
	this->shadedColor = _color;
	
	this->fontsize = _fontsize;
	#ifdef PS3
		this->font = TTF_OpenFont("/dev_hdd0/game/EATER0001/data/Arista.ttf",this->fontsize);
	#else
		this->font = TTF_OpenFont("data/Arista.ttf",this->fontsize);
	#endif
	if(this->font==NULL)
		cout << TTF_GetError() << endl;
	this->text = _text;

	this->renderType = BLENDED;

	update();
}

Text::~Text(){
	TTF_CloseFont(this->font);
}

void Text::draw(){
	SDL_BlitSurface(this->image,NULL,SDL_GetVideoSurface(),&this->box);
}

void Text::update(){
	switch(this->renderType){
		case SOLID:
			this->image = TTF_RenderText_Solid(this->font,this->text.c_str(),this->color);
		break;
		case SHADED:
			this->image = TTF_RenderText_Shaded(this->font,this->text.c_str(),this->color,this->shadedColor);
		break;
		case BLENDED:
			this->image = TTF_RenderText_Blended(this->font,this->text.c_str(),this->color);
		break;
	}
}

void Text::setText(string _text){
	this->text = _text;
}

void Text::setColor(Color _color){
	switch(_color){
		case RED:
			this->color = {0xff,0x00,0x00,0x00};
		break;
		case GREEN:
			this->color = {0x00,0xff,0x00,0x00};
		break;
		case BLUE:
			this->color = {0x00,0x00,0xff,0x00};
		break;
		case WHITE:
			this->color = {0xff,0xff,0xff,0x00};
		break;
		case BLACK:
			this->color = {0x00,0x00,0x00,0x00};
		break;
	}
}

void Text::setShadedColor(Color _color){
	switch(_color){
		case RED:
			this->shadedColor = {0xff,0x00,0x00,0x00};
		case GREEN:
			this->shadedColor = {0x00,0xff,0x00,0x00};
		case BLUE:
			this->shadedColor = {0x00,0x00,0xff,0x00};
		case WHITE:
			this->shadedColor = {0xff,0xff,0xff,0x00};
		case BLACK:
			this->shadedColor = {0x00,0x00,0x00,0x00};
	}
}

void Text::setFontSize(int size){
	this->fontsize = size;
	#ifdef PS3
		this->font = TTF_OpenFont("/dev_hdd0/game/EATER0001/data/Arista.ttf",this->fontsize);
	#else
		this->font = TTF_OpenFont("data/Arista.ttf",this->fontsize);
	#endif
}

void Text::setFont(string _fontpath){
	//TODO: tratamento de erro
	this->font = TTF_OpenFont(_fontpath.c_str(),this->fontsize);
}

void Text::setRenderType(int _renderType){
	switch(_renderType){
		case SOLID:
			this->renderType = SOLID;
		break;
		case SHADED:
			this->renderType = SHADED;
		break;
		case BLENDED:
			this->renderType = BLENDED;
		break;
		default:
			cout << "Error: unknow render type." << endl;

	}
}
