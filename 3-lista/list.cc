#include <iostream>
#include <sstream>
#include "List.h"

// Sorted_List::Node::Node(int data, Node* next)
// {
//     std::cout << "Node constructor: " << data << std::endl;
//     data = data;
//     next = next;
// }

Sorted_List::Sorted_List(const Sorted_List& s)
{
  while(!(s.is_empty()))
  {
    int value = s.return_first();
    insert(value);
    s.remove(value);
  }
}

bool Sorted_List::is_empty() const
{
  if (first == nullptr)
  {
    return true;
  }
  else {return false;}
}
int Sorted_List::size() const
{
  int nsize = 0;
  if (first != nullptr)
  {
    nsize += 1;
    Node* index = first;
    while (index->next != nullptr)
    {
      nsize += 1;
      index = index->next;
    }
  }
  return nsize;
}

void Sorted_List::insert(int value)
{
  std::cout << "Insert: "<< value << std::endl;
  first = new Node{value, first};
}

// int Sorted_List::pop()
// {
  // Node* tmp = first->next;
  // int tmp_value = first->data;
  // delete first;
  // first = tmp;
  // size_of_list -= 1;
  // return tmp_value;
// }

int Sorted_List::return_first() const
{
  if (first != nullptr)
  {
    // std::cout << "Return first: "<< first->data << std::endl;
    return first->data;
  }
}

void Sorted_List::remove(int value)
{
  Node* tmp = first;
  Node* old = tmp;
  if (first == nullptr)
  {
    return;
  }
  else
  {
    while (tmp->data != value)
    {
      if (tmp->next == nullptr)
      {
        return;
      }
      old = tmp;
      tmp = tmp->next;
    }
    old->next = tmp->next;
    delete tmp;
  }
}

// void list::push_front(int value)
// {
//   first = new{value, first};
// }
//
// void List::print() const
// {
//   print_r(first) const;
// }
//
// void List::print_r(Node* p) const
// {
//   if (p != nullptr)
//   {
//     cout << p->data;
//     print(p->next) const;
//   }
// }

Sorted_List::~Sorted_List()
{
  Node* curr=first;
  while (curr != nullptr)
  {
    Node* tmp{curr->next};
    delete curr;
    curr = tmp;
  }
}
