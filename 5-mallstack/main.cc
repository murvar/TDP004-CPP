#include "mallstack.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>

using namespace std;

template<typename Container, typename T>
Linked_Stack<T> mal_func(Container const& c)
{
    Linked_Stack<T> stack;
    for (auto iterator = c.rbegin(); iterator != c.rend(); ++iterator)
    {
        stack.push(*iterator);
    }
    return stack;
}


int main()
{
    vector<int> v = { 7, 5, 16, 8 };
    mal_func<vector<int>, int>(v);
    list<double> l = { 7.0, 5.12, 16.3, 8.032 };
    mal_func<list<double>, double>(l);
    

    // Komplettering: Du har ingen kod som testar att implementationen som helhet
    // fungerar. Du behöver inte använda catch, men du ska åtminstone instansiera
    // stacken med olika datatyper och anropa alla medlemsfunktioner.
}
