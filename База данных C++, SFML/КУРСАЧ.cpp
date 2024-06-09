#include <SFML/Graphics.hpp>
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <malloc.h>
#include <vector>


#include "Input.h"
#include "Button.h"


using namespace sf;

int check_collison_button(sf::Event& event, Button button1)
{
	if (event.mouseButton.x >= button1.rectangle.getPosition().x and event.mouseButton.x <= (button1.rectangle.getPosition().x + button1.height) and event.mouseButton.y >= button1.rectangle.getPosition().y and event.mouseButton.y <= (button1.rectangle.getPosition().y + button1.width))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int check_collison_input(sf::Event& event, Input button1)
{
	if (event.mouseButton.x >= button1.rectangle.getPosition().x and event.mouseButton.x <= (button1.rectangle.getPosition().x + button1.height) and event.mouseButton.y >= button1.rectangle.getPosition().y and event.mouseButton.y <= (button1.rectangle.getPosition().y + button1.width))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	RenderWindow MyWindow(sf::VideoMode(800, 800), L"База данных студентов");
	MyWindow.setFramerateLimit(60);

	//Главные кнопки
	std::wstring text1 = L"Список студентов";
	Button but1 = Button(text1, 1, MyWindow);
	std::wstring text2 = L"Студенты с наличием академической задоженности";
	Button but2 = Button(text2, 3, MyWindow);
	std::wstring text3 = L"Добавить студента :)";
	Button but3 = Button(text3, 5, MyWindow);
	std::wstring text4 = L"Отчислить студента :(";
	Button but4 = Button(text4, 7, MyWindow);
	std::wstring textEx = L"Выйти ";
	Button butExit = Button(textEx, 11, MyWindow);
	
	//Кнопка для возвращения на главную страницу
	std::wstring text5 = L"На главную страницу";
	Button but_home = Button(text5, 1, MyWindow);


	//Переменные состояний
	bool students_is_open = 0;
	bool home_is_open = 1;
	bool students_with_2_open = 0;
	bool add_student_open = 0;
	bool remove_student_open = 0;
	bool name_success = 0;
	bool sur_success = 0;
	bool patronymic_success = 0;
	bool birth_day_success = 0;

	//Ввод данных
	std::wstring input = L"|";
	std::wstring sur_input = L"|";
	std::wstring patr_input = L"|";
	int flag_fio = 0;
	//Кнопки входных данных
			//Имя
	std::wstring name = L"Имя студента";
	Button but_name = Button(name, 3, MyWindow);
	Input input_name = Input(input, 4);
	//Фамилия
	std::wstring sur = L"Фамилия студента";
	Button but_sur = Button(sur, 6, MyWindow);
	Input input_sur = Input(sur_input, 7);
	//Отчество
	std::wstring patr = L"Отчество студента";
	Button but_patr = Button(patr, 9, MyWindow);
	Input input_patr = Input(patr_input, 10);

	while (MyWindow.isOpen())
	{
		sf::Event event;
		while (MyWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				MyWindow.close();
			//События для скроллинга по окну
			if (sf::Event::MouseWheelScrolled)
			{
				if (students_is_open == 0 and home_is_open == 0 and students_with_2_open == 0 and add_student_open == 1 and remove_student_open == 0)
				{
					if (event.mouseWheel.delta == 1)
					{
						but_home.update_button(1);
						but_name.update_button(1);
						but_sur.update_button(1);
						but_patr.update_button(1);
						input_name.update_input(1);
						input_sur.update_input(1);
						input_patr.update_input(1);
					}
					if (event.mouseWheel.delta == -1)
					{
						but_home.update_button(2);
						but_name.update_button(2);
						but_sur.update_button(2);
						but_patr.update_button(2);
						input_name.update_input(2);
						input_sur.update_input(2);
						input_patr.update_input(2);
					}
				}

			}
			//События для клика мыши
			if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left)
				{

					
					//События для главного окна
					if (students_is_open == 0 and home_is_open == 1 and students_with_2_open == 0 and add_student_open == 0 and remove_student_open == 0)
					{	
						
						//Если была зажата кнопка для открытия студентов
						if (check_collison_button(event,but1))
						{
							students_is_open = 1;
							home_is_open = 0;
							students_with_2_open = 0;
							add_student_open = 0; 
							remove_student_open = 0;
							break;
		
						}
						if (check_collison_button(event, but2))
						{
							students_is_open = 0;
							home_is_open = 0;
							students_with_2_open = 1;
							add_student_open = 0;
							remove_student_open = 0;
							break;
						}
						//Если была зажата кнопка для добавления студента
						if (check_collison_button(event, but3))
						{
							students_is_open = 0;
							home_is_open = 0;
							students_with_2_open = 0;
							add_student_open = 1;
							remove_student_open = 0;
							break;
						}
						//Если была зажата кнопка для удаления студента
						if (check_collison_button(event, but4))
						{
							students_is_open = 0;
							home_is_open = 0;
							students_with_2_open = 0;
							add_student_open = 0;
							remove_student_open = 1;
							break;
						}
						if (check_collison_button(event, butExit))
						{
							students_is_open = 0;
							home_is_open = 0;
							students_with_2_open = 0;
							add_student_open = 0;
							remove_student_open = 0;
							MyWindow.close();
							break;
							
						}
						//Если была зажата кнопка выйти
						// 
					//Если зажата во время ввода данных студентов
					if (students_is_open == 0 and home_is_open == 0 and students_with_2_open == 0 and add_student_open == 1 and remove_student_open == 0)
						{
							sf::Event event;
							if(check_collison_input(event, input_name))
							{
								input_name.write = true;
								input_sur.write = false;
								input_patr.write = false;
								MyWindow.close();
								
							}
							else
							{
								MyWindow.close();
							}
							if (check_collison_input(event, input_sur))
							{
								input_name.write = false;
								input_sur.write = true;
								input_patr.write = false;
								
							}
							if (check_collison_input(event, input_patr))
							{
								input_name.write = false;
								input_sur.write = false;
								input_patr.write = true;
								
							}
							
						}

					}
					//Событие для возвращения домой
					if (home_is_open == 0)
					{
						//Если была зажата кнопка возвращения домой
						if (event.mouseButton.x >= but_home.rectangle.getPosition().x and event.mouseButton.x <= (but_home.rectangle.getPosition().x + but_home.height) and event.mouseButton.y >= but_home.rectangle.getPosition().y and event.mouseButton.y <= (but_home.rectangle.getPosition().y + but_home.width))
						{
							students_is_open = 0;
							home_is_open = 1;
							students_with_2_open = 0;
							add_student_open = 0;
							remove_student_open = 0;
							name_success = 0;
							sur_success = 0;
							patronymic_success = 0;
							break;
						}
					}
				}
			// Проверка ввода текста
			if (event.type == sf::Event::TextEntered)
				{
					
					//Ввод текста для добавления студента
					if (students_is_open == 0 and home_is_open == 0 and students_with_2_open == 0 and add_student_open == 1 and remove_student_open == 0)
					{
						
						if (flag_fio == 1)
						{
							input += event.text.unicode;
							input_name.update_input(3, input, MyWindow);
						}
						else if (flag_fio == 2)
						{
							sur_input += event.text.unicode;
							input_sur.update_input(3, input, MyWindow);
						}
						else if (flag_fio == 3)
						{
							patr_input += event.text.unicode;
							input_patr.update_input(3, input, MyWindow);
						}
						but_name.draw_button(MyWindow);
						input_name.draw_input(MyWindow);
						but_sur.draw_button(MyWindow);
						input_sur.draw_input(MyWindow);
						but_patr.draw_button(MyWindow);
						input_patr.draw_input(MyWindow);
					}
					break;
				}
			if (event.key.scancode == sf::Keyboard::Scan::Backspace and students_is_open == 0 and home_is_open == 0 and students_with_2_open == 0 and add_student_open == 1 and remove_student_open == 0)
				{
					if (input.length() > 0)
						{
							input.pop_back();
						}
					break;
				}
			}
	
		if (students_is_open == 0 and home_is_open == 1 and students_with_2_open == 0 and add_student_open == 0 and remove_student_open == 0)
		{
			but1.draw_button(MyWindow);
			but2.draw_button(MyWindow);
			but3.draw_button(MyWindow);
			but4.draw_button(MyWindow);
			butExit.draw_button(MyWindow);
		}
		if (home_is_open == 0)
		{
			but_home.draw_button(MyWindow);
		}
		if (students_is_open == 0 and home_is_open == 0 and students_with_2_open == 0 and add_student_open == 1 and remove_student_open == 0)
		{
			but_name.draw_button(MyWindow);
			input_name.draw_input(MyWindow);
			but_sur.draw_button(MyWindow);
			input_sur.draw_input(MyWindow);
			but_patr.draw_button(MyWindow);
			input_patr.draw_input(MyWindow);			
		}
		MyWindow.display();
		MyWindow.clear(sf::Color(200, 200, 200));
	}
	return 0;
}