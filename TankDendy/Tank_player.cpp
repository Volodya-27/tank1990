#include "Tank_player.h"

Tank_player::Tank_player() :Tank_Baza(), cnt(0), life(life_tank1)
{
	
	Sprite_Tank_up();
}

size_t Tank_player::getLife()
{
	return life;
}

void Tank_player::minuslife()
{
	life--;
}

Sprite& Tank_player::getSprite()
{
	return sprite_tank;
}
int Tank_player::getcnt()
{
	return cnt;
}
void Tank_player::setCnt(size_t cnt_)
{
	cnt = cnt_;
}
void Tank_player::Sprite_Tank_up()
{
	texture_tank.loadFromFile(up);
	sprite_tank.setTexture(texture_tank);
	sprite_tank.setTextureRect(IntRect(0, 0, wight_lenght, wight_lenght));
	sprite_tank.setPosition(position);
	sprite_tank.setScale(0.4, 0.4);
}
void Tank_player::Sprite_Tank_Down()
{
	texture_tank.loadFromFile(up);
	sprite_tank.setTexture(texture_tank);
	sprite_tank.setTextureRect(IntRect(0, 0 + wight_lenght, wight_lenght, -wight_lenght));
	sprite_tank.setPosition(position);
	sprite_tank.setScale(0.4, 0.4);
}
void Tank_player::Sprite_Tank_left()
{
	texture_tank.loadFromFile(right_);
	sprite_tank.setTexture(texture_tank);
	sprite_tank.setTextureRect(IntRect(0 + wight_lenght, 0, -wight_lenght, wight_lenght));
	sprite_tank.setPosition(position);
	sprite_tank.setScale(0.4, 0.4);
}
void Tank_player::Sprite_Tank_right()
{
	texture_tank.loadFromFile(right_);
	sprite_tank.setTexture(texture_tank);
	sprite_tank.setTextureRect(IntRect(0, 0, wight_lenght, wight_lenght));

	sprite_tank.setPosition(position);
	sprite_tank.setScale(0.4, 0.4);
}
void Tank_player::Right(float speedTank_)
{
	Sprite_Tank_right();
	position.x += speedTank_;
	/*if (move_in_shot_ == true)
		cnt = 1;*/
}
void Tank_player::Left(float speedTank_)
{
	Sprite_Tank_left();
	position.x -= speedTank_;
	/*if (move_in_shot_ == true)
		cnt = 2;*/

}
void Tank_player::Up(float speedTank_)
{
	Sprite_Tank_up();
	position.y -= speedTank_;
	/*if (move_in_shot_ == true)
		cnt = 3;*/

}
void Tank_player::Down(float speedTank_)
{
	Sprite_Tank_Down();
	position.y += speedTank_;
	/*	if (move_in_shot_ == true)
			cnt = 4;*/

}

