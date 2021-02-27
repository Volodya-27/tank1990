#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Audio.hpp>
#include<list>
#include"Bullet.h"
#include"Tank_player.h"

using namespace sf;
using namespace std;

class Map
{
private:
	Texture menuTexture1;
	Texture menuTexture2;
	Texture pointer;

	Sprite menu1;
	Sprite menu2;
	Sprite pointer_s;

	list<Bullet*> bullet_arr;
	list<Bullet*> bullet_arr2;
	Tank_player t1;
	Tank_player t2;
	bool shoot_two_player1;
	bool shoot_two_player2;
	bool one;
	bool two;
	bool three;
	bool four;

	Bullet* b;
	Bullet* b2;

	void shoot(int cnt_, Tank_player t_player, RenderWindow& window);
	
	void shoot2(int cnt_, Tank_player t_player, RenderWindow& window);
	
public:
	Map();

	void updatebullet(Clock& _time, RenderWindow& window);
	
	void windowOpen();

    void Game_window(RenderWindow& window);
	
	void input_player1(RenderWindow& window);
	
	void input_player2(RenderWindow& window);
	
	void hit_the_wall(Tank_player ttt);

	void map1(RenderWindow& window);
	
};

