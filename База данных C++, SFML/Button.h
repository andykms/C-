#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#ifndef BUTTON_H
#define BUTTON_H
using namespace sf;

class Button
{
public:
	sf::RectangleShape rectangle;
	sf::Text msg;
	sf::Font font;
	int width = 40;
	int height;
public:

	Button(std::wstring text, int level, sf::RenderWindow& MyWindow)
	{
		//Работаем с прямоугольником кнопки
		int lenn_text = text.length();
		height = 14 * lenn_text;
		sf::RectangleShape rectangle1(sf::Vector2f(height, width));
		rectangle1.setFillColor(sf::Color::Blue);
		rectangle1.setPosition(sf::Vector2f(50, 30 * level));
		rectangle = rectangle1;
		//Работаем с текстом
		font.loadFromFile("font.TTF");
		msg.setCharacterSize(20);
		msg.setString(text);
		msg.setStyle(sf::Text::Bold);
		msg.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y));
		msg.setFont(font);

	}

	void draw_button(sf::RenderWindow& MyWindow)
	{
		if (sf::Mouse::getPosition(MyWindow).x >= rectangle.getPosition().x and sf::Mouse::getPosition(MyWindow).x <= (rectangle.getPosition().x + height) and sf::Mouse::getPosition(MyWindow).y >= rectangle.getPosition().y and sf::Mouse::getPosition(MyWindow).y <= (rectangle.getPosition().y + width))
		{
			rectangle.setFillColor(sf::Color(0, 150, 255));
		}
		else
		{
			rectangle.setFillColor(sf::Color::Blue);
		}
		MyWindow.draw(rectangle);
		MyWindow.draw(msg);
	}

	void update_button(int vector)
	{
		if (vector == 1) 
		{
			rectangle.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y - 35));
			msg.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y));
		}
		if(vector == 2)
		{
			rectangle.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y + 35));
			msg.setPosition(sf::Vector2f(rectangle.getPosition().x, rectangle.getPosition().y));
		}
	}

};

#endif