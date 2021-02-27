#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include"Config_game_param.cpp"


using namespace sf;
using namespace std;

class Bullet
{
private:
	
	Texture texture_bullet;
	Sprite sprite_bullet;
public:
	unsigned long long last_bullet_cange;

	Bullet() = delete;
	Bullet(float dx, float dy);


	Sprite& getSprite();
	

	void downloads_sprite(float dx, float dy);
	
	void update(int cnt_);
	
	void draw(RenderWindow& window);

};
