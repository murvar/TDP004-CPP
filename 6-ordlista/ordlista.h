#pragma once

#include <fstream>
#include <vector>
#include <string>
using namespace std;


class WordList 
{
    public:
    Wordlist();
    ~Cleaner();
    

    private:
    list<string> words;
    list<pair<string, int>> frequency;
}

get_file(string filename);


