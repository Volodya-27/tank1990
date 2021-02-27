#pragma once
//#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/Export.hpp>
#include"Tank_baza.h"


using namespace sf;
using namespace std;

class Tank_player :public Tank_Baza
{
private:
	int cnt;
	size_t life;
public:
	Tank_player();
	size_t getLife();
	void minuslife();
	//void operator-- ();

	Sprite& getSprite();
	int getcnt();
	void setCnt(size_t cnt_);
	void Sprite_Tank_up();
	void Sprite_Tank_Down();
		
	void Sprite_Tank_left();
	void Sprite_Tank_right();
	void Right(float speedTank_);
	void Left(float speedTank_);
	void Up(float speedTank_);
	void Down(float speedTank_);

};
