#include <string>
#ifndef LIST_H
#define LIST_H

class Sorted_List
{
public:
    Sorted_List() = default;
    Sorted_List(Sorted_List const& list);
    Sorted_List(Sorted_List&& list);
    ~Sorted_List();
    void insert(int value);
    int return_first() const;
    bool is_empty() const;
    int size() const;
    void remove(int value);
    void print() const;
    void delete_all();
    int get_index(int value) const;
    // X Komplettering: Tilldelning ska inte returnera void. 
    Sorted_List operator=(const Sorted_List& rhs);
    // Komplettering: Flyttilldelning saknas.


private:
    struct Node
    {
        int data;
        Node* next;
    };
    int size_of_list{0};
    // X Komplettering 7-1
    Node* first{nullptr};
    void print_r(Node* p) const;
    void insert_rec(Node*& p, int const value);
};

#endif
