#include "wall.h"



Wall::Wall()
{

	size = Vector2f(160, 50);
	wall.setSize(size);
	wall.setFillColor(sf::Color(0,153,204));
	wall.setPosition(170, 120);
	wall.setOrigin(size.x / 2, size.y / 2);
	wall.setOutlineThickness(1);
	wall.setOutlineColor(sf::Color::Blue);

}


