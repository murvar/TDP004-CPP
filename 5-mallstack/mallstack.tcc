#include <iostream>
using namespace std;

template <typename T>
Linked_Stack<T>::Linked_Stack(Linked_Stack const& stack)
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

template <typename T>
Linked_Stack<T>::Linked_Stack(Linked_Stack&& stack) :
    size_of_stack{stack.size_of_stack},
    top{stack.top}
{
    stack.size_of_stack = 0;
    stack.top = nullptr;
}

template <typename T>
Linked_Stack<T>::~Linked_Stack()
{
    delete_all();
}

template <typename T>
void Linked_Stack<T>::push(T data)
{
    top = new Node{data, top};
    size_of_stack += 1;
}

template <typename T>
T Linked_Stack<T>::pop()
{
    if (size_of_stack > 0)
    {
        int pop = top->data;
        Node* tmp = top;
        top = top->next;
        delete tmp;
        size_of_stack -= 1;
        return pop;
    }
    else
    {
        cout << "The stack seems to be empty" << endl;
        exit(1);
    }

}

template <typename T>
bool Linked_Stack<T>::is_empty() const
{
    return(top == nullptr);
}

template <typename T>
int Linked_Stack<T>::size() const
{
    return size_of_stack;
}

template <typename T>
void Linked_Stack<T>::display() const
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

template <typename T>
void Linked_Stack<T>::delete_all()
{
    Node* temp = top;

    while (top != nullptr)
    {
        top = top->next;
        delete temp;
        temp = top;
    }
}

template <typename T>
Linked_Stack<T>& Linked_Stack<T>::operator=(const Linked_Stack<T>& rhs)
{
    Linked_Stack s{rhs};
    delete_all();
    top = s.top;
    size_of_stack = s.size_of_stack;
    s.top = nullptr;
    return *this;
}

template <typename T>
Linked_Stack<T>& Linked_Stack<T>::operator=(Linked_Stack<T>&& rhs)
{
    delete_all();
    top = rhs.top;
    size_of_stack = rhs.size_of_stack;
    rhs.top = nullptr;
    return *this;
}
