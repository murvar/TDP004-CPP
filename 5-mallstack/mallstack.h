#ifndef MALLSTACK_H
#define MALLSTACK_H

template <typename T>
class Linked_Stack
{
public:
    Linked_Stack() = default;
    Linked_Stack(Linked_Stack const& stack);
    Linked_Stack(Linked_Stack&& stack);
    ~Linked_Stack();
    void push(T value);
    T pop();
    bool is_empty() const;
    int size() const;
    void display() const;
    Linked_Stack& operator=(const Linked_Stack& rhs);
    Linked_Stack& operator=(Linked_Stack&& rhs);


private:
    void delete_all();
    struct Node
    {
        T data;
        Node* next;
    };
    int size_of_stack{0};
    Node* top{nullptr};
};
#include "mallstack.tcc"
#endif
