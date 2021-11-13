#include <string>
#ifndef LIST_H
#define LIST_H

class Sorted_List
{
public:
  Sorted_List() = default;
  Sorted_List(const Sorted_List& s);
  //void push_front(int value);
  //void push_back(int value);
  void insert(int value);
  //int pop();
  int return_first() const;
  bool is_empty() const;
  int size() const;
  void remove(int value);
  //Sorted_List* copy() const;
  //void print() const;
  //Sorted_List copy(list);
  ~Sorted_List();

private:
  //void compare(int value);
  //void print_r(Node* next) const;
  struct Node
  {
    // Node(int data, Node* next);
    int data;
    Node* next;
  };
  Node* first = nullptr;
};

#endif
