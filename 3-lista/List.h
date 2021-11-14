#include <string>
#ifndef LIST_H
#define LIST_H

class Linked_List
{
public:
    Linked_List() = default;
    Linked_List(const Linked_List& list);
    ~Linked_List();
    void push_front(int value);
    void push_back(int value);
    void insert(int value);
    int pop();
    int return_first() const;
    bool is_empty() const;
    int size() const;
    void remove(int value);
    void print() const;
    Linked_List copy();
    void delete_all();
    int get_index(int value);


private:
    struct Node
    {
        int data;
        Node* next;
    };
    int size_of_list{0};
    void compare(int value);
    void print_r(Node* p) const;
    Node* first = nullptr;
    void insert_rec(Node* p, int value);
};

#endif
