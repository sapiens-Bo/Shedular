#pragma once
#include<SFML/Graphics.hpp>

class sfButton
{
public:
	sfButton() {};

	sfButton(sf::RectangleShape& rect);

	void makeButton(sf::RectangleShape& rect);

	void pressed(sf::Event ev);

	bool IsPressed() { return bIsPressed; }

	void render(sf::RenderWindow& w) { w.draw(button); }

private:
	sf::RectangleShape button;

	bool bIsPressed;
};

