#include "Map.h"
void Map::shoot(int cnt_, Tank_player t_player, RenderWindow& window)
{
	switch (cnt_)
	{
	case 1:
		bullet_arr.push_back(new Bullet(t_player.getSprite().getPosition().x + 30, t_player.getSprite().getPosition().y + 10));
		break;
	case 2:
		bullet_arr.push_back(new Bullet(t_player.getSprite().getPosition().x - 10, t_player.getSprite().getPosition().y + 10));
		break;
	case 3:
		bullet_arr.push_back(new Bullet(t_player.getSprite().getPosition().x + 10, t_player.getSprite().getPosition().y - 10));
		break;
	case 4:
		bullet_arr.push_back(new Bullet(t_player.getSprite().getPosition().x + 10, t_player.getSprite().getPosition().y + 10));
		break;
	default:
		break;
	}
}
void Map::shoot2(int cnt_, Tank_player t_player, RenderWindow& window)
{
	switch (cnt_)
	{
	case 1:
		bullet_arr2.push_back(new Bullet(t_player.getSprite().getPosition().x + 30, t_player.getSprite().getPosition().y + 10));
		break;
	case 2:
		bullet_arr2.push_back(new Bullet(t_player.getSprite().getPosition().x - 10, t_player.getSprite().getPosition().y + 10));
		break;
	case 3:
		bullet_arr2.push_back(new Bullet(t_player.getSprite().getPosition().x + 10, t_player.getSprite().getPosition().y - 10));
		break;
	case 4:
		bullet_arr2.push_back(new Bullet(t_player.getSprite().getPosition().x + 10, t_player.getSprite().getPosition().y + 10));
		break;
	default:
		break;
	}
}
Map::Map() :one(false),
b(nullptr),b2(nullptr), 
two(false), three(false), 
four(false), 
shoot_two_player1(false),
shoot_two_player2(false),
bullet_arr(),
bullet_arr2(),
t1(), t2()
{
	pointer.loadFromFile("Game_resource/newTank.png");
	menuTexture1.loadFromFile("Game_resource/play.png");
	menuTexture2.loadFromFile("Game_resource/exit.PNG");
	menu1.setTexture(menuTexture1);
	menu2.setTexture(menuTexture2);
	pointer_s.setTexture(pointer);
	pointer_s.setPosition(270, 130);
	pointer_s.setScale(0.3, 0.3);
	menu1.setPosition(350, 100);
	menu1.setScale(0.5, 0.5);
	menu2.setPosition(333, 300);
}

void Map::updatebullet(Clock& _time, RenderWindow& window)
{
	if (shoot_two_player1 == true)
	{
		for (auto* b : bullet_arr)
		{
			size_t a;
			a = _time.getElapsedTime().asMicroseconds();

			if (a - b->last_bullet_cange > lenght_bullet)
			{
				b->last_bullet_cange = a;
				//so that the tank alone does not move the bullet of the tank 2
				b->update(t1.getcnt());
				
			}
			//hit the tank bahahahahh  :-)
			if (b->getSprite().getPosition().y >= t2.getSprite().getPosition().y
				&& b->getSprite().getPosition().y < t2.getSprite().getPosition().y + 20 &&
				b->getSprite().getPosition().x >= t2.getSprite().getPosition().x && b->getSprite().getPosition().x < t2.getSprite().getPosition().x + 20)
			{
				t2.minuslife();
				bullet_arr.remove(b);
				break;
			}

			if (b->getSprite().getPosition().x > H - 20)
			{
				bullet_arr.remove(b);
				break;
			}
			if (b->getSprite().getPosition().y > W - 10)
			{
				bullet_arr.remove(b);
				break;
			}
			if (b->getSprite().getPosition().y < 10) //перевірка на стик карти 
			{
				bullet_arr.remove(b);
				break;
			}
			else if (b->getSprite().getPosition().x < 10) //перевірка на стик карти 
			{
				bullet_arr.remove(b);
				break;
			}
			b->draw(window);
		}
	}
	if (shoot_two_player2 == true)
	{
		for (auto* b2 : bullet_arr2)
		{
			size_t a;
			a = _time.getElapsedTime().asMicroseconds();

			if (a - b2->last_bullet_cange > lenght_bullet)
			{
				b2->last_bullet_cange = a;
				//so that the tank alone does not move the bullet of the tank 2
				b2->update(t2.getcnt());
			}
			if (b2->getSprite().getPosition().y >= t1.getSprite().getPosition().y
				&& b2->getSprite().getPosition().y < t1.getSprite().getPosition().y + 20 &&
				b2->getSprite().getPosition().x >= t1.getSprite().getPosition().x && b2->getSprite().getPosition().x < t1.getSprite().getPosition().x + 20)
			{
				t1.minuslife();
				bullet_arr2.remove(b2);
				break;
			}

			if (b2->getSprite().getPosition().x > H - 20)
			{
				bullet_arr2.remove(b2);
				break;
			}
			if (b2->getSprite().getPosition().y > W - 10) //перевірка на стик карти 
			{
				bullet_arr2.remove(b2);
				break;
			}
			if (b2->getSprite().getPosition().y < 10) //перевірка на стик карти 
			{
				bullet_arr2.remove(b2);
				break;
			}
			if (b2->getSprite().getPosition().x < 10) //перевірка на стик карти 
			{
				bullet_arr2.remove(b2);
				break;
			}
			b2->draw(window);
		}
	}
}
void Map::windowOpen()
{

	RenderWindow window(VideoMode(H, W), "Tank");

	while (window.isOpen())
	{
	
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		menu1.setColor(Color::White);
		window.clear(Color::White);
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			pointer_s.setPosition(270, 130 + 200);
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			pointer_s.setPosition(270, 130);
		}

		if (pointer_s.getPosition().y == 130 + 200 && Keyboard::isKeyPressed(Keyboard::Enter))
			window.close();

		if (pointer_s.getPosition().y == 130 && Keyboard::isKeyPressed(Keyboard::Enter))
		{

			Game_window(window);
		}

		window.draw(pointer_s);
		window.draw(menu1);
		window.draw(menu2);

		window.display();
	}
}
void Map::Game_window(RenderWindow& window)
{
	Clock time;
	Sound sound;
	SoundBuffer buffer;
	buffer.loadFromFile("Game_resource/bah3.ogg");
	sound.setBuffer(buffer);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Space)
				{
					shoot_two_player1 = true;
					shoot_two_player2 = false;
					shoot(t1.getcnt(), t1, window);
					sound.play();
				}
			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Q)
				{
					shoot_two_player2 = true;
					shoot_two_player1 = false;

					shoot2(t2.getcnt(), t2, window);
					sound.play();

				}
		}
		hit_the_wall(t1);
		hit_the_wall(t2);

		window.clear();
		map1(window);

		updatebullet(time, window);
		if (t1.getLife() != 0)
		{
			input_player1(window);
			window.draw(t1.getSprite());
		}
		else break;
		if (t2.getLife()!= 0)
		{
			input_player2(window);
			window.draw(t2.getSprite());
		}
		else break;
		window.display();
	}

}
void Map::input_player1(RenderWindow& window)
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		if (one != true)
			t1.Right(speedTank);
		t1.setCnt(1);
		two = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		if (two != true)
			t1.Left(speedTank);
		t1.setCnt(2);

		one = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (three != true)
			t1.Up(speedTank);
		t1.setCnt(3);

		four = false;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		if (four != true)
			t1.Down(speedTank);
		t1.setCnt(4);

		three = false;
	}
}
void Map::input_player2(RenderWindow& window)
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (one != true)
			t2.Right(speedTank);
		t2.setCnt(1); 

	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (two != true)
			t2.Left(speedTank);
		t2.setCnt(2);

	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (three != true)
			t2.Up(speedTank);
		t2.setCnt(3);

	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (four != true)
			t2.Down(speedTank);
		t2.setCnt(4);
	}
}
void Map::hit_the_wall(Tank_player ttt)
{
	if (ttt.getSprite().getPosition().x > H - 45)
		one = true;
	if (ttt.getSprite().getPosition().x < 12)
		two = true;
	if (ttt.getSprite().getPosition().y < 12)
		three = true;
	if (ttt.getSprite().getPosition().y > W - 45)
		four = true;
}
void Map::map1(RenderWindow& window)
{
	RectangleShape rectangle1(Vector2f(2, 2));
	rectangle1.setFillColor(Color(115, 134, 120));

	rectangle1.setTextureRect(IntRect(0, 0, 2, 2));
	rectangle1.setPosition(0, 0);
	rectangle1.setSize(Vector2f(H, 10));


	RectangleShape rectangle2(Vector2f(2, 2));
	rectangle2.setFillColor(Color(115, 134, 120));
	rectangle2.setPosition(0, 0);
	rectangle2.setSize(Vector2f(10, W));

	RectangleShape rectangle3(Vector2f(2, 2));
	rectangle3.setFillColor(Color(115, 134, 120));
	rectangle3.setPosition(H - 10, 0);
	rectangle3.setSize(Vector2f(10, W));

	RectangleShape rectangle4(Vector2f(2, 2));
	rectangle4.setFillColor(Color(115, 134, 120));
	rectangle4.setPosition(0, W - 10);
	rectangle4.setSize(Vector2f(H, 10));
	window.draw(rectangle1);
	window.draw(rectangle2);
	window.draw(rectangle3);
	window.draw(rectangle4);
}
