#include "SaveToFile.h"

void SaveToFile::save()
{
    std::ofstream out("records.txt");          // создаем поток для записи и связываем его с файлом
    if (out.is_open())
    {
        auto temp = getTemperature();
        for (auto iter = temp.begin(); iter != temp.end(); iter++)
        {
            out << *iter << std::endl;  
        }
    }
}
