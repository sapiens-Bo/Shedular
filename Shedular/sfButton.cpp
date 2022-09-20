#include "sfButton.h"

sfButton::sfButton(sf::RectangleShape& rect)
{
	button = rect;
	button.setFillColor(sf::Color::Transparent);
	bIsPressed = false;
}

void sfButton::makeButton(sf::RectangleShape& rect)
{
	button = rect;
}

void sfButton::pressed(sf::Event ev)
{
	if (ev.type == sf::Event::MouseButtonReleased)
	{
		sf::Vector2f pos(ev.mouseButton.x, ev.mouseButton.y);
		if (button.getGlobalBounds().contains(pos))
			bIsPressed = true;
		else
			bIsPressed = false;
	}
}
