#include "Paddle.h"



Paddle::Paddle(float xPos, float yPos)
{
	size = Vector2f(70, 20);
	paddle.setSize(size);
	paddle.setFillColor(sf::Color(222, 184, 135));
	paddle.setPosition(xPos, yPos);
	paddle.setOrigin(size.x / 2, size.y / 2);
	paddle.setOutlineThickness(3);
}


void Paddle::paddle_update(float deltaTime)
{
	Vector2f pos = paddle.getPosition();


	if (Keyboard::isKeyPressed(Keyboard::Left))
		if (paddle.getPosition().x - 50 > 0)
			pos.x -= 200 * deltaTime;
	if (Keyboard::isKeyPressed(Keyboard::Right))
		if (paddle.getPosition().x + 50 < 800)
			pos.x += 200 * deltaTime;

	paddle.setPosition(pos);

}





Vector2f Paddle::getPosition()
{
	return paddle.getPosition();
}
