#pragma once

#include <list>
#include <iostream>

/*������� �������� ����������� � �������� ���������� � ���������� �� ���*/


class Records
{
	std::list<double> temperatures{};
	int counter{ 0 };
	float lowest{ 0 };// ����� ������ �����������
	float highest{ 0 };// �������

public:
	Records();
	~Records();
	std::list<double> getTemperature();
	void new_record(float temperature);
	void remove_record();
	void showTemperature();
	void showExtremums();
	double getHighest() { return highest; }
	double getLowest() { return lowest; }
	double getRandomNumber(double min, double max);
	void save();


};

