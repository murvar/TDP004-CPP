#pragma once

#include "mallstack.cc"

class Linked_Stack
{
public:
    Linked_Stack() = default;
    Linked_Stack(Linked_Stack const& stack);
    Linked_Stack(Linked_Stack&& stack);
    ~Linked_Stack();
    void push(int value);
    int pop();
    bool is_empty() const;
    int size() const;
    void display() const;
    Linked_Stack& operator=(const Linked_Stack& rhs);
    Linked_Stack& operator=(Linked_Stack&& rhs);


private:
    void delete_all();
    struct Node
    {
        int data;
        Node* next;
    };
    int size_of_stack{0};
    Node* top{nullptr};
};