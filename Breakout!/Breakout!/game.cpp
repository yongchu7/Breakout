#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "paddle.h"
#include "ball.h"
//#include "block.h"
#include "wall.h"
#include "manager.h"
using namespace sf;
using namespace std;
int PlayerScore = 0;
float life = 3;
Text text;
RenderWindow window;
RectangleShape top;
RectangleShape Left;
RectangleShape Right;
RectangleShape bottom;

bool gamerun = true;
Paddle player(400,580);
Ball ball;
BrickManager manager;
Paddle wall(400, 400);
bool getSpace;
bool getR;
int level = 1;

SoundBuffer buf2;
Sound lost;

SoundBuffer buf3;
Sound gameover;

SoundBuffer buf6;
Sound levelnext;


void check_life() {
	if (ball.ball.getPosition().y > 580){
		buf2.loadFromFile("ball_lost.wav");
		lost.setBuffer(buf2);
		lost.play();
		life = life - 1;
		ball.restart();
		ball.velocity = Vector2f(-100, -100);
		getSpace = false;
	
	}


	
}





void playground() {
	manager.update(ball);
	Font font;
	font.loadFromFile("arial.ttf");

	Texture texture;
	texture.loadFromFile("menu.png");
	Sprite background;
	background.setTexture(texture);
	background.setTextureRect(IntRect(10, 10, 800, 600));
	background.setColor(sf::Color(255, 255, 255, 128));

	top.setPosition(0, 0);
	top.setSize(Vector2f(800, 0));

	bottom.setPosition(0, 600);
	bottom.setSize(Vector2f(800, 600));

	Left.setPosition(0, 0);
	Left.setSize(Vector2f(0, 600));

	Right.setPosition(800, 0);
	Right.setSize(Vector2f(800, 600));

	top.setFillColor(Color(100, 100, 100));
	top.setOutlineColor(Color::Red);
	top.setOutlineThickness(5);

	bottom.setFillColor(Color(100, 100, 100));
	bottom.setOutlineColor(Color::Red);
	bottom.setOutlineThickness(5);

	Left.setFillColor(Color(100, 100, 100));
	Left.setOutlineColor(Color::Red);
	Left.setOutlineThickness(5);

	Right.setFillColor(Color(100, 100, 100));
	Right.setOutlineColor(Color::Red);
	Right.setOutlineThickness(5);

	Text score;
	score.setCharacterSize(50);
	score.setFont(font);
	score.setPosition(20, 500);
	score.setColor(Color::Yellow);
	std::stringstream string;
	string << "Score:"<<PlayerScore;
	score.setString(string.str());

	Text Life;
	Life.setCharacterSize(50);
	Life.setFont(font);
	Life.setPosition(600, 500);
	Life.setColor(Color::Red);
	std::stringstream string1;
	string1 << "Life:" << life;
	Life.setString(string1.str());
	
	Text over;
	over.setCharacterSize(50);
	over.setFont(font);
	over.setPosition(300, 200);
	over.setColor(Color::Red);
	std::stringstream string2;
	string2 << "Game over";
	over.setString(string2.str());
	

	window.clear(Color::Black);
	window.draw(background);
	manager.draw(window);

	window.draw(Left);
	window.draw(Right);
	window.draw(top);
	window.draw(bottom);
	window.draw(player.paddle);
	window.draw(wall.paddle);
	window.draw(ball.ball);
	window.draw(score);
	window.draw(Life);
	check_life();

	if (life <= 0) {
		window.draw(over);
		buf3.loadFromFile("gameover.wav");
		gameover.setBuffer(buf3);
		gameover.play();

		if (Keyboard::isKeyPressed(Keyboard::R))
		{
			getR = true;
		}
		if (getR) {
			level = 1;
			manager.clear();
			manager.create(level);
			life = 3;
			PlayerScore = 0;
			//ball.ball.setPosition(400, 525);
		}

	}


}


int main()
{
	window.create(VideoMode(800, 600), "Breakout!");
	Music music;
	music.openFromFile("BGM.ogg");
	music.play();
	Clock clock;
	manager.create(level);
	
	
	while (window.isOpen())
	{
		if (gamerun == true) {

			
			}
			playground();
			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				
			}

			float dt = clock.restart().asSeconds();
			player.paddle_update(dt);
			wall.paddle_update(dt);
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				getSpace = true;
			}
			if (getSpace) {
				//ball.ball.setPosition(ball.getPosition() + ball.velocity * dt);
				ball.update(dt, player);
				ball.update(dt, wall);
			}
			else
			{
				ball.ball.setPosition(player.getPosition().x, player.getPosition().y -50);
			}

			if (manager.win == true) {
				manager.clear();
				ball.velocity *= 1.3f;
				buf6.loadFromFile("level_complete.wav");
				levelnext.setBuffer(buf6);
				levelnext.play();
				level = level + 1;
				manager.win = false;
				//manager.brick_number = 0;
				//manager.destroy_brick = 0;
				manager.create(level);
				//cout << manager.brick_number << endl;
				//cout << manager.destroy_brick << endl;
				//PlayerScore = PlayerScore + 1;
				//playground();
				ball.ball.setPosition(400,525);
				if (level > 3) {

					level = 1;
					manager.clear();
					manager.create(level);
					//PlayerScore = 0;
					ball.velocity *= 1.1f;
					life = 4;
				}
			
			}
		

		window.display();

	}

}