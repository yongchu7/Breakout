#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include<iostream>
#include <algorithm>
#include <memory>
#include<vector>
#include"block.h"
#include "ball.h"

using namespace sf;
using namespace std;

class BrickManager
{
public:

	vector< Block*> bricks;
	int brick_number;

	BrickManager();
	~BrickManager();

	void update(Ball &ball);
	void draw(RenderWindow &window);
	void create(int level);

};