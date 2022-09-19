#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

const std::string PATH_FONT_FILE = "./Dependencis/Font/Combo-Regular.ttf";

class Calendar
{
public:
	Calendar();

	~Calendar() {};

	void fillBoxesDays();

	void fillNumsBoxesDay(sf::Font& f);

	void render(sf::RenderWindow& w);
private:
	std::vector<sf::RectangleShape> boxesDays;
	sf::RectangleShape boxCalendar;

	std::vector<sf::Text> numbers;
	sf::Text month;
};

