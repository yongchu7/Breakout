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

Ball::Ball()
{
	radius = 10;
	ball.setFillColor(sf::Color::Yellow);
	ball.setRadius(radius);
	ball.setPosition(400, 525);
	velocity = Vector2f(-300, -300);
	

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
	}
	if (ball.getPosition().x > (800 - radius))
	{
		velocity.x = -velocity.x;
	}
	if (ball.getPosition().y < (0 + radius))
	{
		velocity.y = -velocity.y;
	}
	if (ball.getPosition().x < (0 + radius))
	{
		velocity.x = -velocity.x;
	}
	if (ball.getGlobalBounds().intersects(player.paddle.getGlobalBounds())) {
		velocity.y = -velocity.y;
	}
}


Vector2f Ball::getPosition()
{
	return ball.getPosition();
}
