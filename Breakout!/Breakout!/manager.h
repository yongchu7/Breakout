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
#include"brick.h"
#include "ball.h"

using namespace sf;
using namespace std;

class BrickManager
{
public:

	vector<Brick*> bricks;
	int brick_number;
	int destroy_brick;
	BrickManager();
	~BrickManager();
	void clear();
	bool win;
	void update(Ball &ball);
	void draw(RenderWindow &window);
	void create(int level);
	SoundBuffer buf;
	Sound hitbrick;
	Texture tex;
};