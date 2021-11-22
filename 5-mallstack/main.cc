#include "mallstack.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    Linked_Stack stack;
    stack.push(10);
    stack.display();
    stack.push(20);
    stack.push(30);
    stack.display();

    Linked_Stack stack2{stack};
    stack2.display();
    cout << stack.pop() << endl;
    stack.display();
}