//#include "mallstack.h"
#include <iostream>
#include <iomanip>

using namespace std;

Linked_Stack::Linked_Stack(Linked_Stack const& stack)
{
    if (stack.top != nullptr)
    {
        Node* cur = stack.top;
        Node* temp = new Node{cur->data, nullptr};
        top = temp;

        while (cur->next != nullptr)
        {
            cur = cur->next;
            temp->next = new Node{cur->data, nullptr};
            temp = temp->next;
        }
    }
}

Linked_Stack::Linked_Stack(Linked_Stack&& stack) :
    size_of_stack{stack.size_of_stack},
    top{stack.top}
{
    stack.size_of_stack = 0;
    stack.top = nullptr;
}

Linked_Stack::~Linked_Stack()
{ 
    delete_all();
}

void Linked_Stack::push(int data)
{
    top = new Node{data, top}; 
    size_of_stack += 1;   
}

int Linked_Stack::pop()
{
    int pop = top->data;
    Node* tmp = top;
    top = top->next;
    delete tmp;
    size_of_stack -= 1;
    return pop;
}

bool Linked_Stack::is_empty() const
{
    return(top == nullptr);
}

int Linked_Stack::size() const
{
    return size_of_stack;
}

void Linked_Stack::display() const
{
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        Node* temp = top;
        while (temp != nullptr)
        {
            cout << temp->data; 
            if (temp->next != nullptr)
            {
                cout << "-> ";
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

void Linked_Stack::delete_all()
{
    Node* temp = top;
    
    while (top != nullptr)
    {
        top = top->next;
        delete temp;
        temp = top;
    }
}


Linked_Stack& Linked_Stack::operator=(const Linked_Stack& rhs)
{
    Linked_Stack s{rhs};
    delete_all();
    top = s.top;
    size_of_stack = s.size_of_stack;
    s.top = nullptr;
    return *this;
}

Linked_Stack& Linked_Stack::operator=(Linked_Stack&& rhs)
{
    delete_all();
    top = rhs.top;
    size_of_stack = rhs.size_of_stack;
    rhs.top = nullptr;
    return *this;
}