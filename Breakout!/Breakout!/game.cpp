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
#include "block.h"
#include "wall.h"
using namespace sf;
int PlayerScore = 14;
int life = 3;
Text text;
RenderWindow window;
RectangleShape top;
RectangleShape left;
RectangleShape right;
RectangleShape bottom;
bool gamerun = true;
Paddle player(400,580);
Ball ball;
Block block;
Block block1;
Block block2;
Block block3;
Block block4;
Block block5;
Block block6;
Block block7;
Block block8;
Block block9;
Wall wall;
Wall wall1;
Wall wall2;
Wall wall3;
Wall wall4;
bool getSpace;
void draw_block() {
	


		block.block.setPosition(80, 100);
		
		if (block.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block.collide = true;
				PlayerScore = PlayerScore + 1;

			}
			window.draw(block.block);
		}
	}


void draw_block1() {



		block1.block.setPosition(240, 100);

		if (block1.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block1.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block1.collide = true;
				PlayerScore = PlayerScore + 1;
			}
			window.draw(block1.block);
		}
	}


void draw_block2() {


		block2.block.setPosition(400, 100);

		if (block2.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block2.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block2.collide = true;
				PlayerScore = PlayerScore + 1;
			}
			window.draw(block2.block);
		}
	}


void draw_block3() {



		block3.block.setPosition(560, 100);

		if (block3.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block3.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block3.collide = true;
				PlayerScore = PlayerScore + 1;
			}
			window.draw(block3.block);
		}
	}


void draw_block4() {



		block4.block.setPosition(720, 100);

		if (block4.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block4.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block4.collide = true;
				PlayerScore = PlayerScore + 1;
			}
			window.draw(block4.block);
		}
	}


void draw_block5() {



		block5.block.setPosition(80, 50);

		if (block5.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block5.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block5.collide = true;
				PlayerScore = PlayerScore + 1;
			}
			window.draw(block5.block);
		}
	}


void draw_block6() {



		block6.block.setPosition(240, 50);

		if (block6.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block6.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block6.collide = true;
				PlayerScore = PlayerScore + 1;
			}
			window.draw(block6.block);
		}
	}


void draw_block7() {



		block7.block.setPosition(400, 50);

		if (block7.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block7.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block7.collide = true;
				PlayerScore = PlayerScore + 1;
			}
			window.draw(block7.block);
		}
	
}

void draw_block8() {



		block8.block.setPosition(560, 50);

		if (block8.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block8.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block8.collide = true;
				PlayerScore = PlayerScore + 1;
			}
			window.draw(block8.block);
		}
	}


void draw_block9() {



		block9.block.setPosition(720, 50);

		if (block9.collide == false)
		{
			if (ball.ball.getGlobalBounds().intersects(block9.block.getGlobalBounds())) {
				ball.velocity.y = -ball.velocity.y;
				block9.collide = true;
				PlayerScore = PlayerScore + 1;
			}
			window.draw(block9.block);
		}
	}


void draw_wall() {

	wall.wall.setPosition(80, 150);
	if (wall.collide == false)
	{
		if (ball.ball.getGlobalBounds().intersects(wall.wall.getGlobalBounds())) {
			wall.hp = wall.hp - 1;
			ball.velocity.y = -ball.velocity.y;
			if (wall.hp == 0) {
			wall.collide = true;
			PlayerScore = PlayerScore + 1;
			}
		}
			window.draw(wall.wall);
		}
	}




void draw_wall1() {

	wall1.wall.setPosition(240, 150);
	if (wall1.collide == false)
	{
		if (ball.ball.getGlobalBounds().intersects(wall1.wall.getGlobalBounds())) {
			wall1.hp = wall1.hp - 1;
			ball.velocity.y = -ball.velocity.y;
			if (wall1.hp == 0) {
				wall1.collide = true;
				PlayerScore = PlayerScore + 1;
			}
		}
		window.draw(wall1.wall);
	}
}

void draw_wall2() {

	wall2.wall.setPosition(400, 150);
	if (wall2.collide == false)
	{
		if (ball.ball.getGlobalBounds().intersects(wall2.wall.getGlobalBounds())) {
			wall2.hp = wall2.hp - 1;
			ball.velocity.y = -ball.velocity.y;
			if (wall2.hp == 0) {
				wall2.collide = true;
				PlayerScore = PlayerScore + 1;
			}
		}
		window.draw(wall2.wall);
	}
}

void draw_wall3() {

	wall3.wall.setPosition(560, 150);
	if (wall3.collide == false)
	{
		if (ball.ball.getGlobalBounds().intersects(wall3.wall.getGlobalBounds())) {
			wall3.hp = wall3.hp - 1;
			ball.velocity.y = -ball.velocity.y;
			if (wall3.hp == 0) {
				wall3.collide = true;
				PlayerScore = PlayerScore + 1;
			}
		}
		window.draw(wall3.wall);
	}
}

void draw_wall4() {

	wall4.wall.setPosition(720, 150);
	if (wall4.collide == false)
	{
		if (ball.ball.getGlobalBounds().intersects(wall4.wall.getGlobalBounds())) {
			wall4.hp = wall4.hp - 1;
			ball.velocity.y = -ball.velocity.y;
			if (wall4.hp == 0) {
				wall4.collide = true;
				PlayerScore = PlayerScore + 1;
			}
		}
		window.draw(wall4.wall);
	}
}

void build_bricks() {
	draw_block();
	draw_block1();
	draw_block2();
	draw_block3();
	draw_block4();
	draw_block5();
	draw_block6();
	draw_block7();
	draw_block8();
	draw_block9();
	draw_wall();
	draw_wall1();
	draw_wall2();
	draw_wall3();
	draw_wall4();
}


void check_life() {
	if (ball.ball.getPosition().y > 580){
		life = life - 1;
		ball.restart();
		ball.velocity = Vector2f(-300, -300);
		getSpace = false;
	
	}
	
}







void playground() {
	Font font;
	font.loadFromFile("arial.ttf");

	Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite background;
	background.setTexture(texture);
	background.setTextureRect(IntRect(10, 10, 800, 600));
	background.setColor(sf::Color(255, 255, 255, 128));

	top.setPosition(0, 0);
	top.setSize(Vector2f(800, 0));

	bottom.setPosition(0, 600);
	bottom.setSize(Vector2f(800, 600));

	left.setPosition(0, 0);
	left.setSize(Vector2f(0, 600));

	right.setPosition(800, 0);
	right.setSize(Vector2f(800, 600));

	top.setFillColor(Color(100, 100, 100));
	top.setOutlineColor(Color::Red);
	top.setOutlineThickness(5);

	bottom.setFillColor(Color(100, 100, 100));
	bottom.setOutlineColor(Color::Red);
	bottom.setOutlineThickness(5);

	left.setFillColor(Color(100, 100, 100));
	left.setOutlineColor(Color::Red);
	left.setOutlineThickness(5);

	right.setFillColor(Color(100, 100, 100));
	right.setOutlineColor(Color::Red);
	right.setOutlineThickness(5);

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
	Life.setPosition(650, 500);
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
	window.draw(left);
	window.draw(right);
	window.draw(top);
	window.draw(bottom);
	window.draw(player.paddle);
	window.draw(ball.ball);
	window.draw(score);
	window.draw(Life);
	build_bricks();
	check_life();

	if (life == 0) {
		window.draw(over);
		gamerun = false;
		//system("pause");
		//window.close();
		window.display();
	}


}



int main()
{
	window.create(VideoMode(800, 600), "Breakout!");
	Music music;
	music.openFromFile("BGM.ogg");
	music.play();
	Clock clock;
	while (window.isOpen())
	{

		if (gamerun == true) {
			playground();

			if (PlayerScore == 15) {
				playground();
			}

			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			float dt = clock.restart().asSeconds();
			player.paddle_update(dt);

			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				getSpace = true;
			}
			if (getSpace) {
				//ball.ball.setPosition(ball.getPosition() + ball.velocity * dt);
				ball.update(dt, player);
			}
			else
			{
				ball.ball.setPosition(player.getPosition().x, player.getPosition().y -50);
			}
			
			

		}

		window.display();

	}

}