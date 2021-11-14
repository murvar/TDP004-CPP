#include <iostream>
#include <sstream>
#include "List.h"

using namespace std;

Linked_List::Linked_List(const Linked_List& list)
{
    if (first != nullptr)
    {
        delete_all();
    }
    Node* cur = list.first;
    while(cur != nullptr)
    {
        push_back(cur->data);
        cur = cur->next;
    }
}

Linked_List::~Linked_List()
{
    delete_all();
}

void Linked_List::push_front(int value) {
    first = new Node{value, first};
    size_of_list += 1;
}

void Linked_List::push_back(int value) {
    Node* cur = first;
    while (cur != nullptr)
    {
        cur = cur->next;
    }
    cur = new Node{value, nullptr};
    size_of_list += 1;
}

void Linked_List::insert(int value)
{
    if (first == nullptr || first->data > value)
    {
        first = new Node{value, first};
        size_of_list += 1;
    }
    else {insert_rec(first->next, value);}
    
}

int Linked_List::pop()
{
    Node* tmp = first->next;
    int tmp_value = first->data;
    delete first;
    first = tmp;
    size_of_list -= 1;
    return tmp_value;
}

int Linked_List::return_first() const //vad göra när tom?
{
    if (first != nullptr)
    {
        return first->data;
    }
    else {return 0;}
}

bool Linked_List::is_empty() const
{
    return(first == nullptr);
}

int Linked_List::size() const
{
    //cout << "size is " << size_of_list << endl;
    return size_of_list;
}

void Linked_List::remove(int value)
{
    Node* tmp = first;
    Node* old = nullptr;

    if (tmp != nullptr && tmp->data == value)
    {
        first = tmp->next;
        delete tmp;
        size_of_list -= 1;
        return;
    }

    while (tmp != nullptr && tmp->data >= value)
    {
        if (tmp->data == value)
        {
            old = tmp->next;
            delete tmp;
            size_of_list -= 1;
            return;
        }
        old = tmp;
        tmp = tmp->next;
    }
}



void Linked_List::print() const
{
    print_r(first);
}

void Linked_List::delete_all()
{
    Node* curr=first;
    while (curr != nullptr)
    {
        Node* tmp{curr->next};
        delete curr;
        curr = tmp;
    }
    size_of_list = 0;
}

void Linked_List::print_r(Node* p) const
{
    if (p != nullptr)
    {
        cout << p->data;
        print_r(p->next);
    }
}

void Linked_List::compare(int value) 
{

}

Linked_List Linked_List::copy() 
{
    return *this;
}

void Linked_List::insert_rec(Node* cur, int value)
{
    if (cur != nullptr && value > cur->data)
    {
        insert_rec(cur->next, value);
    }
    else
    {
        if (cur == nullptr)
        {
            cur = new Node{value, nullptr};
        }
        else {
            cur = new Node{value, cur};
        }
        size_of_list +=1;
    }
}

int Linked_List::get_index(int value)
{
    Node* tmp = first;
    int index{0};

    while (tmp != nullptr)
    {
        cout << "hello" << endl;
        if (tmp->data == value)
        {
            return index;
        }
        tmp = tmp->next;
        index += 1;
    }
    return(-1);
}