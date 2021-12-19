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
    //x Komplettering: T kan vara av klasstyp, så den ska tas emot som const&.
    void push(T const& value);
    T pop();
    bool is_empty() const;
    int size() const;
    void display() const;
    // Kommentar: Man brukar lägga speciella medlemsfunktioner tillsammans.
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
