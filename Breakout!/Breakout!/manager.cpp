#include "manager.h"
#include "brick.h"
#include "ball.h"

using namespace sf;
using namespace std;
//Ball ball;
SoundBuffer buf4;
Sound shatter;
extern int PlayerScore;
extern float life;

bool win = false;
BrickManager::BrickManager()
{
	brick_number = 0;
	destroy_brick = 0;
	//int PlayerScore = 0;
}

BrickManager::~BrickManager()
{
	for (int i = 0; i < brick_number; i++)
	{
		delete bricks[i];
	}
	bricks.clear();
}

void BrickManager::clear()
{
	for (int i = 0; i < brick_number; i++)
	{
		delete bricks[i];
	}
	bricks.clear();
	brick_number = 0;
	destroy_brick = 0;
}




void BrickManager::update(Ball &ball)
{
	Brick* brick;

	for (int i = 0; i < brick_number; i++)
	{
		brick = bricks[i];
		if (!brick->isDead())
		{
			if (ball.ball.getGlobalBounds().intersects(brick->brick.getGlobalBounds()))
			{
				brick->hit();
				buf4.loadFromFile("shatter.wav");
				shatter.setBuffer(buf4);
				shatter.play();
				tex.loadFromFile("cracked brick.png");
				brick->brick.setTexture(&tex);
				if (ball.ball.getPosition().y > brick->brick.getPosition().y - brick->bricksize.y / 2 && (ball.ball.getPosition().y < brick->brick.getPosition().y + brick->bricksize.y / 2))
				{
					ball.velocity.x = -ball.velocity.x;
				}
				else
				{
					ball.velocity.y = -ball.velocity.y;
				}
				PlayerScore = PlayerScore + 50;
				life = life + 0.1;
				if (brick->isDead())
				{
					destroy_brick++;
					if (destroy_brick == brick_number)
					{
						win = true;
					}
					//bricks.erase(bricks.begin());
					//continue;
				}
				else
				{
					buf.loadFromFile("break.wav");
					hitbrick.setBuffer(buf);
					hitbrick.play();
				}
			}
		}
	}
}

void BrickManager::draw(RenderWindow &window)
{
	for (int i = 0; i < brick_number; i++)
	{
		cout << bricks[i]->hp << endl;
		if (!bricks[i]->isDead())
		{
			window.draw(bricks[i]->brick);

		}
	}
}

void BrickManager::create(int level)
{
	
	switch (level)
	{
	case 1:

		for (int j = 0; j < 10; /*j++*/)
		{
			for (int i = 0; i < 10; i++)
			{

				Brick* brick = new Brick(1, Color::Transparent);
				brick->brick.setPosition(40 + i * 80, 300 + j * 20);
				bricks.push_back(brick);
				brick_number++;
				brick->brick.setOutlineColor(Color::Red);
				brick->brick.setOutlineThickness(1);

			}
			j = j + 10;
		}


		for (int j = 0; j < 10; /*j++*/)
		{
			for (int i = 0; i < 10; i++)
			{
				
				Brick* brick = new Brick(1, Color::Yellow);
				brick->brick.setPosition(40 + i * 80, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
				brick->brick.setOutlineColor(Color::Red);
				brick->brick.setOutlineThickness(1);
			}
			j = j + 10;
		}

		for (int j = 1; j < 2; /*j++*/)
		{
			for (int i = 0; i < 10; i++)
			{
				Brick* brick = new Brick(2, Color::Blue);
				brick->brick.setPosition(40 + i * 80 , 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
				brick->brick.setOutlineColor(Color::Green);
				brick->brick.setOutlineThickness(1);
			}
			j = j + 10;
		}
		break;

	case 2:

		for (int j = 0; j < 10; /*j++*/)
		{
			for (int i = 0; i < 10; i++)
			{
				Brick* brick = new Brick(1, Color::Yellow);
				brick->brick.setPosition(40 + i * 80, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
				brick->brick.setOutlineColor(Color::Red);
				brick->brick.setOutlineThickness(1);
			}
			j = j + 10;
		}

		for (int j = 1; j < 10; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				Brick* brick = new Brick(2, Color::Blue);
				brick->brick.setPosition(40 + i * 160, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
				brick->brick.setOutlineColor(Color::Green);
				brick->brick.setOutlineThickness(1);
			}
		}
		break;

	case 3:

		for (int j = 0; j < 10; /*j++*/)
		{
			for (int i = 0; i < 10; i++)
			{
				Brick* brick = new Brick(1, Color::Yellow);
				brick->brick.setPosition(40 + i * 80, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
				brick->brick.setOutlineColor(Color::Red);
				brick->brick.setOutlineThickness(1);
			}
			j = j + 5;
		}

		for (int j = 1; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				Brick* brick = new Brick(2, Color::Blue);
				brick->brick.setPosition(40 + i * 80, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
				brick->brick.setOutlineColor(Color::Green);
				brick->brick.setOutlineThickness(1);
			}
		}
		break;


	default:
		break;
	}
}