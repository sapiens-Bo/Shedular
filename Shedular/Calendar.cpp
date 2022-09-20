#include "Calendar.h"

#include <iostream>
#include <string>

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
			rect.setPosition(j * 50 + 10, i * 50 + 10);
			rect.setOutlineThickness(1.f);
			rect.setOutlineColor(sf::Color::Black);
			rect.setFillColor(sf::Color::White);
			boxesDays.push_back(rect);
		}
	}

	for (auto& box : boxesDays)
	{
		sfButton button(box);
		buttonsDays.push_back(button);
	}
}

void Calendar::fillNumsBoxesDay(sf::Font& f)
{
	for (int i = 0; i < boxesDays.size(); i++)
	{
		if (i < 30)
		{
			sf::Text number;
			number.setFont(f);
			number.setCharacterSize(24);
			number.setFillColor(sf::Color::Black);

			std::string num = std::to_string(i);
			number.setString(num);
			number.setPosition(boxesDays[i].getPosition() + sf::Vector2f(10, 10));
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

	for (auto& a : buttonsDays)
		a.render(w);
}

void Calendar::pressButton(sf::Event ev)
{
	if (ev.type == sf::Event::MouseButtonReleased)
	{
		for (int i = 0; i < buttonsDays.size(); i++)
		{
			buttonsDays[i].pressed(ev);
			if (buttonsDays[i].IsPressed())
			{
				boxesDays[i].setFillColor(sf::Color::Red);
			}
		}

	}
}
