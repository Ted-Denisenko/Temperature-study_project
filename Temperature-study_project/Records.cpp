#include "Records.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // ��� ������� rand() � srand()

double Records::getRandomNumber(double min, double max)
{
	srand(static_cast<unsigned int>(time(0)));
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// ���������� ������������ ��������� ����� � ����� ���������
	return static_cast<double>(rand() * fraction * (max - min + 1) + min);
}

Records::Records()
{
	//��������� ������ ���������� �������
	for (int count = 0; count < 10; ++count)
	{
		temperatures.push_back(getRandomNumber(-15.0, 30.0));
	}
}

Records::~Records()
{

}

void Records::new_record(float temperature)
{
	if (counter == 10)
	{
		std::cout << "Can not add new record - out of space" << std::endl;
	}
	counter += 1;
	temperatures.push_back(temperature);
	if (temperature > highest)
	{
		highest = temperature;
		std::cout << "Highest temperature's updated. New is " << highest << std::endl;
	}
	if (temperature < lowest)
	{
		lowest = temperature;
		std::cout << "Lowest temperature's updated. New is " << lowest << std::endl;
	}
}

std::list<double> Records::getTemperature() // ������� ������ ������� ������
{
	return temperatures;
}

void Records::remove_record()
{
	
}

void Records::save()
{
	std::ofstream out("records.txt"); // ������� ����� ��� ������ � ��������� ��� � ������
	if (out.is_open())
	{
		auto temp = getTemperature();
		for (auto iter = temp.begin(); iter != temp.end(); iter++)
		{
			out << *iter << std::endl;
		}
	}
}

void Records::showTemperature()
{	
	std::cout << "Recorded temperatures are: " << std::endl;
	auto temp = getTemperature();
	for (auto iter = temp.begin(); iter != temp.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
}

void Records::showExtremums()
{
	std::cout << "Highest temperature is " << Records::getHighest() << " degrees at Celsius" << std::endl;
	std::cout << "Lowest temperature is " << Records::getLowest() << " degrees at Celsius" << std::endl;
}
