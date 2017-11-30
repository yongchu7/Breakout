#include "brickmanager.h"

BrickManager::BrickManager()
{
	brick_number = 0;
}

BrickManager::~BrickManager()
{
	for (int i = 0; i < brick_number; i++)
	{
		delete bricks[i];
	}
	bricks.clear();
}



void BrickManager::update(Ball &ball)
{
	Brick* brick;
	//loop through all the bricks
	//check collision

	for (int i = 0; i < brick_number; i++)
	{
		brick = bricks[i];
		if (!brick->isDead())
		{
			if (ball.ball.getGlobalBounds().intersects(brick->brick.getGlobalBounds()))
			{
				brick->hit();
				ball.velocity.y = -ball.velocity.y;
				ball.score++;
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

		for (int j = 0; j < 11; /*j++*/)
		{
			for (int i = 0; i < 10; i++)
			{
				Brick* brick = new Brick(1, Color::Yellow);
				brick->brick.setPosition(40 + i * 80, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
			}
			j = j + 10;
		}

		for (int j = 1; j < 10; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				Brick* brick = new Brick(2, Color::Blue);
				brick->brick.setPosition(40 + i * 160 + j * 80, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
			}
		}
		break;

	case 2:

		for (int j = 0; j < 12; /*j++*/)
		{
			for (int i = 0; i < 10; i++)
			{
				Brick* brick = new Brick(1, Color::Yellow);
				brick->brick.setPosition(40 + i * 80, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
			}
			j = j + 5;
		}

		for (int j = 1; j < 10; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				Brick* brick = new Brick(2, Color::Blue);
				brick->brick.setPosition(40 + i * 160, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
			}
		}
		break;

	case 3:

		for (int j = 0; j < 6; /*j++*/)
		{
			for (int i = 0; i < 10; i++)
			{
				Brick* brick = new Brick(1, Color::Yellow);
				brick->brick.setPosition(40 + i * 80, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
			}
			j = j + 5;
		}

		for (int j = 1; j < 5; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				Brick* brick = new Brick(2, Color::Blue);
				brick->brick.setPosition(40 + i * 80, 10 + j * 20);
				bricks.push_back(brick);
				brick_number++;
			}
		}
		break;


	default:
		break;
	}
}
