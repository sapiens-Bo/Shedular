#include "Calendar.h"

#include <iostream>

Calendar::Calendar()
{
	fillBoxesDays();
}

void Calendar::fillBoxesDays()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			sf::RectangleShape rect{sf::Vector2f(50, 50)};
			rect.setPosition(i * 50, j * 50);
			rect.setOutlineThickness(1.f);
			rect.setOutlineColor(sf::Color::Black);
			rect.setFillColor(sf::Color::White);
			boxesDays.push_back(rect);
		}
	}
}

void Calendar::fillNumsBoxesDay(sf::Font& f)
{/*
	sf::Font font;
	if (!font.loadFromFile(PATH_FONT_FILE))
	{
		std::cout << "error font" << std::endl;
	}
	*/
	for (int i = 0; i < boxesDays.size(); i++)
	{
		if (i < 30)
		{
			sf::Text number;
			number.setFont(f);
			number.setCharacterSize(24);
			number.setFillColor(sf::Color::Black);

			std::string num("%f", i);
			number.setString(num);
			number.setPosition(boxesDays[i].getPosition() + sf::Vector2f(5, 1));
			numbers.push_back(number);
		}
	}
}

void Calendar::render(sf::RenderWindow& w)
{
	for (auto& a : boxesDays)
		w.draw(a);

	for (auto& a : numbers)
		w.draw(a);
}
