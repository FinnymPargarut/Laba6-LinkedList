#pragma once


#include <string>
#include <algorithm>


struct Node
{
    std::string full_name;
    int age;
    std::string family_status;
    Node* next;
    Node(std::string fn, int age, std::string fs) : full_name(fn), age(age), family_status(fs), next(nullptr) {}
};


struct list
{
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty();
    void push_back(std::string fn, int age, std::string fs);
    Node* get_Node(int index);
    int size();
    void reset_values();
    void assign(Node* receiver, Node* give);
    void Change_near_nodes(int index_min);
    std::string get_full_name(int index);
    void print_after_reset();
    void print();
    std::string get_name(int index);
    std::string get_ot(int index);
    int get_age(int index);
};