#include "SaveToFile.h"

void SaveToFile::save()
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
