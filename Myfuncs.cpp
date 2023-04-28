#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "Mystructs.h"


int Input_variant()
{
    int var{};
    while (!(std::cin >> var) || (std::cin.peek() != '\n') || ((var != 1) && (var != 2) && (var != 3) && (var != 4)))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ââîä íåêêîğåêòåí! Ïîâòîğèòå." << std::endl;
    }
    return var;
}


int alf(char letter)
{
    std::string alphabet_uppercase = "ÀÁÂÃÄÅ¨ÇÆÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÜÛÚİŞß ";
    std::string alphabet_lowercase = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùüûúışÿ ";
    for (int i = 0; i < 34; i++)
        if ((letter == alphabet_uppercase[i]) or (letter == alphabet_lowercase[i]))
            return i;
    return -1;
}


void sort_by_full_name(list& data)
{
    int size = data.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (alf(data.get_full_name(j)[0]) > alf(data.get_full_name(j + 1)[0]))
            {
                data.Change_near_nodes(j);
            }
            else if (alf(data.get_full_name(j)[0]) == alf(data.get_full_name(j + 1)[0]))
            {
                int minlen;
                if (strlen(data.get_full_name(j).c_str()) < strlen(data.get_full_name(j).c_str()))
                    minlen = strlen(data.get_full_name(j).c_str());
                else
                    minlen = strlen(data.get_full_name(j + 1).c_str());
                for (int m = 1; m < minlen; m++)
                {
                    if ((alf(data.get_full_name(j)[m]) > alf(data.get_full_name(j + 1)[m])))
                    {
                        data.Change_near_nodes(j);
                        break;
                    }
                    else if (((alf(data.get_full_name(j)[m]) < alf(data.get_full_name(j + 1)[m])))) break;
                }
            }
        }
    }
}


list Input_from_file()
{
    list data{};
    std::ifstream fin("Data.txt");
    if (!fin.is_open())
    {
        std::cout << "Îøèáêà! Ôàéë íå íàéäåí." << std::endl;
    }
    else
    {
        std::regex regstr("([À-ßà-ÿ]*)([\\s]?)([À-ßà-ÿ]*)([\\s]?)([À-ßà-ÿ]*);([0-9]{0,3});([À-ßà-ÿ]*)");
        std::string strdata;
        std::string rez{};
        std::string full_name;
        int age;
        std::string family_status;
        while (true)
        {
            strdata = ""; getline(fin, strdata);
            if (strdata == "") break;
            if (std::regex_match(strdata.c_str(), regstr))
            {
                int index;
                for (int i = 0; strdata[i] != ';'; i++)
                {
                    index = i;
                    rez = rez + strdata[i];
                }
                full_name = rez; rez = "";

                for (int i = index + 2; strdata[i] != ';'; i++)
                {
                    index = i;
                    rez = rez + strdata[i];
                }
                age = std::atoi(rez.c_str()); rez = "";

                if (age == 0) index++;
                for (int i = index + 2; strdata[i] != '\0'; i++)
                    rez = rez + strdata[i];
                family_status = rez; rez = "";
                data.push_back(full_name, age, family_status);
            }
        }
    }
    fin.close();
    return data;
}


void sort_by_name(list& data)
{
    int size = data.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (alf(data.get_name(j)[0]) > alf(data.get_name(j + 1)[0]))
            {
                data.Change_near_nodes(j);
            }
            else if (alf(data.get_name(j)[0]) == alf(data.get_name(j + 1)[0]))
            {
                int minlen;
                if (strlen(data.get_name(j).c_str()) < strlen(data.get_name(j + 1).c_str()))
                    minlen = strlen(data.get_name(j).c_str());
                else
                    minlen = strlen(data.get_name(j + 1).c_str());
                for (int m = 1; m < minlen; m++)
                {
                    if ((alf(data.get_name(j)[m]) > alf(data.get_name(j + 1)[m])))
                    {
                        data.Change_near_nodes(j);
                        break;
                    }
                    else if (((alf(data.get_name(j)[m]) < alf(data.get_name(j + 1)[m])))) break;
                }
            }
        }
    }
}


void sort_by_ot(list& data)
{
    int size = data.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (alf(data.get_ot(j)[0]) > alf(data.get_ot(j + 1)[0]))
            {
                data.Change_near_nodes(j);
            }
            else if (alf(data.get_ot(j)[0]) == alf(data.get_ot(j + 1)[0]))
            {
                int minlen;
                if (strlen(data.get_ot(j).c_str()) < strlen(data.get_ot(j).c_str()))
                    minlen = strlen(data.get_ot(j).c_str());
                else
                    minlen = strlen(data.get_ot(j + 1).c_str());
                for (int m = 1; m < minlen; m++)
                {
                    if ((alf(data.get_ot(j)[m]) > alf(data.get_ot(j + 1)[m])))
                    {
                        data.Change_near_nodes(j);
                        break;
                    }
                    else if (((alf(data.get_ot(j)[m]) < alf(data.get_ot(j + 1)[m])))) break;
                }
            }
        }
    }
}


void sort_by_age(list& data)
{
    int size = data.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (data.get_age(j) > data.get_age(j + 1))
            {
                data.Change_near_nodes(j);
            }
        }
    }
}