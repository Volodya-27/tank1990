#include"Bullet.h"


Bullet::Bullet(float dx, float dy):
	texture_bullet(),
	sprite_bullet(),
	last_bullet_cange(0)
{
	//last_bullet_cange = 0;
	downloads_sprite(dx, dy);
};

Sprite& Bullet::getSprite()
{
	return sprite_bullet;
}

void Bullet::downloads_sprite(float dx, float dy)
{
	texture_bullet.loadFromFile(bullet_texture);
	sprite_bullet.setTexture(texture_bullet);
	sprite_bullet.setTextureRect(IntRect(0, 0, Bullet_wight_lenght, Bullet_wight_lenght));
	sprite_bullet.setPosition(dx, dy);
	sprite_bullet.setScale(0.4, 0.4);
}
void Bullet::update(int cnt_)
{
	switch (cnt_)
	{
	case 1:
		sprite_bullet.move(10, 0);
		break;
	case 2:
		sprite_bullet.move(-10, 0);
		break;
	case 3:
		sprite_bullet.move(0, -10);
		break;
	case 4:
		sprite_bullet.move(0, 10);
		break;
	default:
		break;
	}

}
void Bullet::draw(RenderWindow& window)
{
	window.draw(sprite_bullet);
}









