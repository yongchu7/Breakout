#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

//extern RenderWindow window;
using namespace sf;

class Brick
{
public:
	RectangleShape brick;

	Vector2f bricksize;
	int hp;
	Brick(int hp, Color col);
	Color col;
	Texture tex;
	SoundBuffer buf;
	void hit() { --hp; }
	bool isDead() { return hp <= 0; }
};