#include "ordlista.cc"

int main()
{
    WordList wordlist{};
    ifstream ifs{filename};
    string data;
    while (ifs >> data) 
    {
        wordlist.words.push_back(data);
    }  
}