#include <iostream>
#include <SFML/Graphics.hpp>

#include "Calendar.h"

const std::string PATH_FONT = "./Dependencis/Font/Combo-Regular.ttf";

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "ok");

	Calendar cal;

	sf::Font font;
	font.loadFromFile(PATH_FONT);

	cal.fillNumsBoxesDay(font);

	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == ev.Closed)
			{
				window.close();
			}

			cal.pressButton(ev);
		}
		window.clear(sf::Color::Green);

		cal.render(window);
		window.display();
	}

	return 0;
}