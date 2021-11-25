#include "SaveToFile.h"

void SaveToFile::save()
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
