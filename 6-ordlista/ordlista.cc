#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

int largest{0};

string clean_word(string word)
{
    word.erase(0, word.find_first_not_of("\"'("));
    word.erase(word.find_last_not_of("!?;,:.\"')") + 1);
    
    if (word.find("--") != string::npos)
    {
        return "";
    }
    if (word.find('.') != string::npos)
    {
        return "";
    }
    if (word.find("()") != string::npos)
    {
        return "";
    }
    if (word.find("'s's") != string::npos)
    {
        return "";
    }
    if (word.find('#') != string::npos)
    {
        return "";
    }
    if (word.find('!') != string::npos)
    {
        return "";
    }
    if (word.find('<') != string::npos)
    {
        return "";
    }
    else
    {
        word = word.substr(0, word.find("'s"));
        if (word.length() < 3)
        {
            return "";
        }
        transform(word.begin(), word.end(), word.begin(),
        [](unsigned char c){ return tolower(c);});
        if (word.size() > largest)
        {
            largest = word.size();
        }
        return word; 
    }        
}

list<string> get_file_list(string const& file_name)
{
    ifstream ifs{file_name};
    istream_iterator<string> iter(ifs);
    istream_iterator<string> eof;

    list<string> words;

    copy(iter, eof, back_inserter(words));

    return words;
}

list<string> clean_file(list<string> file_list)
{
    transform(begin(file_list), end(file_list), begin(file_list), clean_word);
    file_list.remove("");
    return(file_list);
}

bool compare_strings (const pair<string,int>& a, const pair<string,int>& b)
{
  unsigned int i=0;
  while ( (i<a.first.length()) && (i<b.first.length()) )
  {
    if (a.first[i]<b.first[i]) return true;
    else if (a.first[i]>b.first[i]) return false;
    ++i;
  }
  return ( a.first.length() < b.first.length() );
}

bool compare_frequency (const pair<string,int>& a, const pair<string,int>& b)
{
  return ( a.second > b.second );
}

string get_a_string(const pair<string,int>& word_pair)
{
    stringstream ss;
    ss << left << setw(largest+1) << word_pair.first << right << word_pair.second << endl;
    return(ss.str());
}

string get_f_string(const pair<string,int>& word_pair)
{
    stringstream ss;
    ss << right << setw(largest) << word_pair.first << " " << word_pair.second << endl;
    return(ss.str());
}


int main(int argc, char** argv)
{
    if (argc == 1) {
        cout << "Error: No arguments given.\nUsage: a.out FILE [-a] [-f] [-o N]" << endl;
        return -1;
    }

    if (argc == 2) {
        cout << "Error: Second argument missing or invalid.\nUsage: ./a.out FILE [-a] [-f] [-o N]" << endl;
        return -1;
    }

    string file_name{};
    char parameter{};
    int charLimit{};

    try {
        file_name = argv[1];
        parameter = argv[2][1];

        if ((parameter == 'o') && (argc = 4)) 
        {
            charLimit = stoi(argv[3]);
            if (charLimit < 4) 
            {
                cout << "Error: Words are defined as containing 3 or more characters." << endl;
                return -1;
            }
        } 
        else if (parameter == 'o') 
        {
            cout << "Error: Second argument missing or invalid." << endl;
            return -1;
        }
    } catch (const exception& e) {
        cout << "Error: Incorrect argument list." << endl;
        return -1;
    }

    list<string> v = get_file_list(file_name);
    v = clean_file(v);

    set<string> vs{};
    copy(begin(v), end(v), inserter(vs, begin(vs)));

    list<pair<string,int>> word_pairs{};
    transform(begin(vs), end(vs), back_inserter(word_pairs),
    [v](string const& word) -> pair<string, int>{return make_pair(word, count(begin(v), end(v), word));});
            

    switch (parameter)
    {
        case 'a':        
            word_pairs.sort(compare_strings);

            transform(begin(word_pairs), end(word_pairs), ostream_iterator<string>(cout, ""), 
            [](pair<string, int> const& word_pair) -> string{return get_a_string(word_pair);});

            break;

        case 'f':
            word_pairs.sort(compare_frequency);

            transform(begin(word_pairs), end(word_pairs), ostream_iterator<string>(cout, ""), 
            [](pair<string, int> const& word_pair) -> string{return get_f_string(word_pair);});

            break;

        case 'o':
            int size{};

            auto wordPlacer = [&size, &charLimit](string const& word) {
                if ((size + word.size()) < charLimit) 
                {
                    size += word.size() + 1;
                    cout << word << " ";
                } 
                else 
                {
                    size = word.size() + 1;
                    cout << endl;
                    cout << word << " ";
                }
            };

            for_each(v.begin(), v.end(), wordPlacer);
            cout << endl;

            break;
    }   
    
}