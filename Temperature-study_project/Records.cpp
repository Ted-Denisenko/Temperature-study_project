#include "Records.h"
#include <iostream>
#include <fstream>

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
	std::ofstream out("records.txt");          // ������� ����� ��� ������ � ��������� ��� � ������
	if (out.is_open())
	{
		auto temp = getTemperature();
		for (auto iter = temp.begin(); iter != temp.end(); iter++)
		{
			out << *iter << std::endl;
		}
	}
}
