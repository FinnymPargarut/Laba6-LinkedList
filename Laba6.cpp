#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include "Mystructs.h"
#include "Myfuncs.h"


int main()
{
    setlocale(LC_ALL, "Russian");
    list table = Input_from_file();
    bool reset = false;
    while (true)
    {
        std::cout << std::endl;
        if (!reset)
            table.print();
        else
            table.print_after_reset();
        std::cout << "1) Подсчитать число элементов списка." << std::endl;
        std::cout << "2) Печать всех элементов в отсортированном по ФИО виде." << std::endl;
        std::cout << "3) Сброс значений всех элементов." << std::endl;
        std::cout << "4) Выход." << std::endl;
        int variant = Input_variant();
        if (variant == 1)
        {
            std::cout << "Число элементов: " << table.size() << std::endl;
        }
        else if (variant == 2)
        {
            std::cout << "\n1.По ФИО\n2.По имени\n3.По отчеству\n4.По возрасту" << std::endl;
            int sort_by = Input_variant();
            if (sort_by == 1)
                sort_by_full_name(table);
            else if (sort_by == 2)
                sort_by_name(table);
            else if (sort_by == 3)
                sort_by_ot(table);
            else
                sort_by_age(table);
        }
        else if (variant == 3)
        {
            table.reset_values();
            reset = true;
        }
        else
        {
            break;
        }
    }

    std::ofstream fout("Data.txt");
    if (!fout.is_open())
    {
        std::cout << "Ошибка! Файл для записи не найден." << std::endl;
    }
    else
    {
        Node* p;
        for (int i = 0; i < table.size(); i++)
        {
            p = table.get_Node(i);
            fout << p->full_name << ';' << p->age << ';' << p->family_status << std::endl;
        }
        std::cout << "Данные перезаписаны в файл.";
    }
    return 0;
}