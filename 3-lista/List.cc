#include <iostream>
#include <sstream>
#include "List.h"

using namespace std;

Sorted_List::Sorted_List(Sorted_List const& list)
{
    Node* cur = list.first;
    while(cur != nullptr)
    {
        insert(cur->data);
        cur = cur->next;
    }
}

Sorted_List::Sorted_List(Sorted_List&& list)
{
    size_of_list = list.size_of_list;
    list.size_of_list = 0;
    first = list.first;
    list.first = nullptr;
}

Sorted_List::~Sorted_List()
{
    delete_all();
}

void Sorted_List::insert(int value)
{
    // if (first == nullptr || first->data > value)
    // {
    //     first = new Node{value, first};
    //     size_of_list += 1;
    // }
    // else {insert_rec(first->next, value);}
    insert_rec(first, value);
    
}

int Sorted_List::return_first() const //vad göra när tom?
{
    if (first != nullptr)
    {
        return first->data;
    }
    else {return 0;}
}

bool Sorted_List::is_empty() const
{
    return(first == nullptr);
}

int Sorted_List::size() const
{
    return size_of_list;
}

void Sorted_List::remove(int value)
{
    if (first != nullptr && first->data == value)
    {
        first = first->next;
        size_of_list -= 1;
        return;
    }

    Node* tmp = first->next;
    Node* old = first;

    while (tmp != nullptr && tmp->data <= value)
    {
        if (tmp->data == value)
        {
            old->next = tmp->next;
            delete tmp;
            size_of_list -= 1;
            return;
        }
        old = tmp;
        tmp = tmp->next;
    }
}



void Sorted_List::print() const
{
    print_r(first);
}

void Sorted_List::delete_all()
{
    Node* tmp=nullptr;

    while (first != nullptr)
    {
        tmp = first;
        first = first->next;
        delete tmp;
    }
    size_of_list = 0;
}

void Sorted_List::print_r(Node* p) const
{
    if (p != nullptr)
    {
        cout << p->data << endl;;
        print_r(p->next);
    }
}

void Sorted_List::insert_rec(Node*& cur, int const value)
{
    if (cur != nullptr && value > cur->data)
    {
        insert_rec(cur->next, value);
    }
    else
    {
        cur = new Node{value, cur}; 
        size_of_list +=1;
    }
}

int Sorted_List::get_index(int value) const
{
    Node* tmp = first;
    int index{0};

    while (tmp != nullptr)
    {
        if (tmp->data == value)
        {
            return index;
        }
        tmp = tmp->next;
        index += 1;
    }
    return(-1);
}

void Sorted_List::operator=(const Sorted_List& rhs)
{
    Sorted_List l{rhs};
    delete_all();
    first = l.first;
    size_of_list = l.size_of_list;
    l.first = nullptr;
}