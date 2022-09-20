#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "sfButton.h"

const std::string PATH_FONT_FILE = "./Dependencis/Font/Combo-Regular.ttf";

class Calendar
{
public:
	Calendar();

	~Calendar() {};

	void fillBoxesDays();

	void fillNumsBoxesDay(sf::Font& f);

	void render(sf::RenderWindow& w);

	void pressButton(sf::Event ev);

private:
	std::vector<sf::RectangleShape> boxesDays;
	sf::RectangleShape boxCalendar;

	std::vector<sf::Text> numbers;
	std::vector<sfButton> buttonsDays;

	sf::Text month;
};

