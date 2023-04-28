#include <iostream>
#include "Mystructs.h"

bool list::is_empty()
{
	return first == nullptr;
}

void list::push_back(std::string fn, int age, std::string fs)
{
    Node* p = new Node(fn, age, fs);
    if (is_empty())
    {
        first = p;
        last = p;
        return;
    }
    last->next = p;
    last = p;
}

Node* list::get_Node(int index)
{
    Node* p = first;
    int i = 0;
    while (p)
    {
        if (i == index) break;
        p = p->next;
        i++;
    }
    return p;
}

int list::size()
{
    int s = 0;
    if (is_empty()) return s;
    Node* p = first;
    while (p)
    {
        s += 1;
        p = p->next;
    }
    return s;
}

void list::reset_values()
{
    if (is_empty()) return;
    Node* p = first;
    while (p)
    {
        p->full_name = "";
        p->age = 0;
        p->family_status = "";
        p = p->next;
    }
}

void list::assign(Node* receiver, Node* give)
{
    receiver->full_name = give->full_name;
    receiver->age = give->age;
    receiver->family_status = give->family_status;
}

void list::Change_near_nodes(int index_min)
{
    if (is_empty()) return;
    Node* p = first;
    for (int i = 0; i < index_min; i++) p = p->next;
    Node* medium = new Node("", 0, "");
    assign(medium, p);
    assign(p, p->next);
    assign(p->next, medium);
    delete medium;
}

std::string list::get_full_name(int index)
{
    if (is_empty()) return "Empty";
    Node* p = first;
    int i = 0;
    while (p)
    {
        if (i == index) return p->full_name;
        p = p->next;
        i++;
    }
    return "Error";
}

void list::print_after_reset()
{
    if (is_empty()) return;
    Node* p = first;
    std::cout << "ФИО\tВозраст\tСемейное положение" << std::endl;
    while (p)
    {
        std::cout << p->full_name << '\t' << p->age << '\t' << p->family_status << std::endl;
        p = p->next;
    }
    std::cout << std::endl;
}

void list::print()
{
    if (is_empty()) return;
    Node* p = first;
    int maxlen = 0;
    for (int i = 0; i < size(); i++)
        if (strlen(get_full_name(i).c_str()) > maxlen)
            maxlen = strlen(get_full_name(i).c_str());

    int i = 0;
    std::cout << "ФИО";
    for (int j = 0; j < (maxlen - 3) + 1; j++) std::cout << ' ';
    std::cout << "Возраст\tСемейное положение" << std::endl;
    while (p)
    {
        int lenfn = strlen(get_full_name(i).c_str());
        std::cout << p->full_name;
        for (int j = 0; j < maxlen - lenfn + 1; j++) std::cout << ' ';
        std::cout << p->age << "\t\t" << p->family_status << std::endl;
        p = p->next;
        i++;
    }
    std::cout << std::endl;
}

std::string list::get_name(int index)
{
    if (is_empty()) return "Empty";
    Node* p = first;
    int i = 0;
    std::string name{};
    while (p)
    {
        if (i == index)
        {
            bool space = false;
            for (int j = 0; j < strlen(p->full_name.c_str()); j++)
            {
                if (space)
                {
                    if (p->full_name[j] == ' ') break;
                    name = name + p->full_name[j];
                }
                if (p->full_name[j] == ' ') space = true;
            }
            return name;
        }
        p = p->next;
        i++;
    }
    return "Error";
}

std::string list::get_ot(int index)
{
    if (is_empty()) return "Empty";
    Node* p = first;
    int i = 0;
    std::string ot{};
    while (p)
    {
        if (i == index)
        {
            bool space_1 = false;
            bool space_2 = false;
            for (int j = 0; j < strlen(p->full_name.c_str()); j++)
            {
                if (space_1)
                {
                    if (space_2) ot = ot + p->full_name[j];
                    if (p->full_name[j] == ' ') space_2 = true;
                }
                if (p->full_name[j] == ' ') space_1 = true;
            }
            return ot;
        }
        p = p->next;
        i++;
    }
    return "Error";
}

int list::get_age(int index)
{
    if (is_empty()) return 0;
    Node* p = first;
    int i = 0;
    while (p)
    {
        if (i == index) return p->age;
        p = p->next;
        i++;
    }
    return 0;
}