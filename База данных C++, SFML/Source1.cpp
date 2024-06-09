#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
#include <fstream>

using namespace sf;

class Button
{
public:
	sf::RectangleShape rectangle;
	sf::Text message;
public:

	Button(char text, int level, sf::RenderWindow& MyWindow)
	{
		sf::RectangleShape rectangle1(sf::Vector2f(200, 50));
		rectangle1.setFillColor(sf::Color::Blue);
		rectangle1.setPosition(sf::Vector2f(100, 30 * level));
		sf::Font font;

		sf::Text msg("", font, 24);
		msg.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
		msg.setStyle(sf::Text::Bold | sf::Text::Underlined);
		message = msg;
		rectangle = rectangle1;
	}

	void draw_button(sf::RenderWindow& MyWindow)
	{
		MyWindow.draw(rectangle);
	}

	void draw_msg(sf::RenderWindow& MyWindow)
	{
		MyWindow.draw(message);
	}


};

int main()
{
	setlocale(LC_ALL, "Russian");
	RenderWindow MyWindow(sf::VideoMode(500, 600, 32), "Students");
	MyWindow.setFramerateLimit(60);
	Button but1 = Button('tex', 1, MyWindow);
	while (MyWindow.isOpen())
	{
		sf::Event event;
		while (MyWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				MyWindow.close();


		}
		MyWindow.clear(sf::Color::White);
		but1.draw_button(MyWindow);
		but1.draw_msg(MyWindow);
		MyWindow.display();
	}


	return 0;
}