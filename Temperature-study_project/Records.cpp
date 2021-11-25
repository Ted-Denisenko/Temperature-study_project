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

std::list<double> Records::getTemperature() // выведет первый элемент списка
{
	return temperatures;
}

void Records::remove_record()
{
	
}

void Records::save()
{
	std::ofstream out("records.txt");          // создаем поток для записи и связываем его с файлом
	if (out.is_open())
	{
		for (auto iter = getTemperature().begin(); iter != getTemperature().end(); iter++)
		{
			out << *iter << std::endl;
		}
	}
}
