#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include"Config_game_param.cpp"  
using namespace sf;
using namespace std;

class Tank_Baza
{
protected:
	
	Vector2f position;
	Texture texture_tank;
	Sprite sprite_tank;
public:
	Tank_Baza();

	virtual	Sprite& getSprite() = 0;
};