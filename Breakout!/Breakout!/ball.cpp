#include "ball.h"
#include "paddle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
using namespace sf;
bool Space;
SoundBuffer buf1;
Sound hitwall;

SoundBuffer buf5;
Sound hitpaddle;
Ball::Ball()
{
	radius = 10;
	ball.setFillColor(sf::Color::Yellow);
	ball.setRadius(radius);
	ball.setPosition(400, 525);
	velocity = Vector2f(-100, -100);
	

}

void Ball::restart() {
	ball.setPosition(400, 525);


	//srand(time(NULL));
	//velocity = Vector2f(-300, -300);
}

void Ball::update(float deltaTime, Paddle player)
{
	ball.setPosition(ball.getPosition() + velocity * deltaTime);

	if (ball.getPosition().y > (600 - radius))
	{
		velocity.y = -velocity.y;
		buf1.loadFromFile("wall_bounce.wav");
		hitwall.setBuffer(buf1);
		hitwall.play();
	}
	if (ball.getPosition().x > (800 - radius))
	{
		velocity.x = -velocity.x;
		buf1.loadFromFile("wall_bounce.wav");
		hitwall.setBuffer(buf1);
		hitwall.play();
	}
	if (ball.getPosition().y < (0 + radius))
	{
		velocity.y = -velocity.y;
		buf1.loadFromFile("wall_bounce.wav");
		hitwall.setBuffer(buf1);
		hitwall.play();
	}
	if (ball.getPosition().x < (0 + radius))
	{
		velocity.x = -velocity.x;
		buf1.loadFromFile("wall_bounce.wav");
		hitwall.setBuffer(buf1);
		hitwall.play();
	}
	if (ball.getGlobalBounds().intersects(player.paddle.getGlobalBounds())) {
		velocity.y = -velocity.y;
		buf5.loadFromFile("paddle_bounce.wav");
		hitpaddle.setBuffer(buf5);
		hitpaddle.play();
	}
}


Vector2f Ball::getPosition()
{
	return ball.getPosition();
}
