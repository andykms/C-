#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <malloc.h>
#include <vector>
#ifndef INPUT_H
#define INPUT_H
using namespace sf;

class Input
{
public:
	std::wstring input;
	sf::Text msg;
	sf::Font font;
	int width = 30;
	int height = 500;
	sf::RectangleShape rectangle;
	bool write = false;
public:
	Input(std::wstring user_unput, int level, bool user_write = false)
	{
		write = user_write;
		sf::RectangleShape rectangle1(sf::Vector2f(height, width));
		rectangle1.setFillColor(sf::Color(150,150,150));
		rectangle1.setPosition(sf::Vector2f(50, 30 * level));
		rectangle = rectangle1;
		rectangle.setOutlineThickness(5);
		//Работаем с текстом
		font.loadFromFile("font.TTF");
		msg.setCharacterSize(20);
		msg.setString(user_unput);
		msg.setStyle(sf::Text::Bold);
		msg.setPosition(sf::Vector2f(rectangle.getPosition().x + 5, rectangle.getPosition().y + 5));
		msg.setFont(font);
	}
	void draw_input(sf::RenderWindow& MyWindow)
	{
		if (sf::Mouse::getPosition(MyWindow).x >= rectangle.getPosition().x and sf::Mouse::getPosition(MyWindow).x <= (rectangle.getPosition().x + height) and sf::Mouse::getPosition(MyWindow).y >= rectangle.getPosition().y and sf::Mouse::getPosition(MyWindow).y <= (rectangle.getPosition().y + width))
		{
			rectangle.setFillColor(sf::Color(0, 150, 255));
		}
		else
		{
			rectangle.setFillColor(sf::Color(150, 150, 150));
		}
		MyWindow.draw(rectangle);
		MyWindow.draw(msg);
	}
	void update_input(int vector)
	{
		if (vector == 1)
		{
			rectangle.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y - 35));
			msg.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y));
		}
		if (vector == 2)
		{
			rectangle.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y + 35));
			msg.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y));
		}
	}
	void update_input(int vector, std::wstring user_input, sf::RenderWindow& MyWindow)
	{
		if (vector == 1)
		{
			rectangle.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y - 35));
			msg.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y));
		}
		if (vector == 2)
		{
			rectangle.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y + 35));
			msg.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y));
		}
		if (vector == 3)
		{
			msg.setString(user_input);
			draw_input(MyWindow);
		}
	}
};

#endif

