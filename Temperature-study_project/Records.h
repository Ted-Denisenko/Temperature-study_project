#pragma once

#include <list>
#include <iostream>

/*������� �������� ����������� � �������� ���������� � ���������� �� ���*/


class Records
{
	std::list<double> temperatures{0.1, 0.16, 0.14 };
	int counter{ 0 };
	float lowest{ 0 };// ����� ������ �����������
	float highest{ 0 };// �������
public:
	std::list<double> getTemperature();
	void new_record(float temperature);
	void remove_record();
	void showHighest() { std::cout << highest << " is the highest temperature recorded" << std::endl; }
	void showLowest() { std::cout << lowest << " is the lowest temperature recorded" << std::endl; }
	void save();


};

