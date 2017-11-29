#include "block.h"



Block::Block()
{
	size = Vector2f(160, 50);
	block.setSize(size);
	block.setFillColor(sf::Color::Green);
	block.setPosition(170, 120);
	block.setOrigin(size.x / 2, size.y / 2);
	block.setOutlineThickness(1);
	block.setOutlineColor(sf::Color::Blue);
}



