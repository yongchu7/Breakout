#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <memory>
using namespace std;
#include "ball.h"
#include"brick.h"
//extern RenderWindow window;
vector<unique_ptr<Brick>> bricks;
//Ball ball;
//Color col;


Brick::Brick(int hp, Color col)
{
	this->hp = hp;
	bricksize = Vector2f(70, 20);
	brick.setSize(bricksize);
	brick.setFillColor(col);
	brick.setOrigin(bricksize.x / 2, bricksize.y / 2);
	tex.loadFromFile("brick.png");
	brick.setTexture(&tex);

}