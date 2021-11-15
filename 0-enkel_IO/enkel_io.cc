#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
 Se: https://www.ida.liu.se/divisions/sas/groups/upp/info/lang/cpp/UPP_correct_guide.pdf

 Komplettering:
 4-3 Upprepa inte manipulatorer med effekt som gäller tills vidare.
 4-5. Inkludera enbart bibliotek som faktiskt används.
      Du har glömt att inkludera string biblioteket.
 5-1 Välj variabelnamn som tydligt visar kodens intention.
 7-1 Initiera variabler med klammerparenteser. Gäller för samtliga
 variabler.
*/

int main() {
    int heltal{};
    cout << "Skriv in ett heltal: ";
    cin >> heltal;
    cout << "Du skrev in talet " << heltal << endl;
    cin.ignore(10000, '\n');


    cout << "\nSkriv in fem heltal: ";
    cin >> heltal;
    cout << "Du skrev in talen: " << heltal;
    cin >> heltal;
    cout << ", " << heltal;
    cin >> heltal;
    cout << ", " << heltal;
    cin >> heltal;
    cout << ", " << heltal;
    cin >> heltal;
    cout << ", " << heltal << endl;

    cin.ignore(10000, '\n');


   float flyttal{};
    cout << "\nSkriv in ett flyttal: ";
    cin >> flyttal;
    cout << "Du skrev in flyttalet: " << fixed
    << setprecision(3) << flyttal << endl;

    cin.ignore(10000, '\n');


    cout << "\nSkriv in ett heltal och ett flyttal: " ;
    cin >> heltal;
    cin >>  flyttal;
    cout << "Du skrev in heltalet:" << setw(10) << heltal << endl;
    cout << "Du skrev in flyttalet:" << setw(9) << right
    << flyttal << endl;

    cin.ignore(10000, '\n');


    cout << "\nSkriv in ett flyttal och ett heltal: " ;
    cin >> flyttal;
    cin >> heltal;
    cout << "Du skrev in heltalet:" << setfill('-')
    << setw(10)  << heltal << endl;
    cout << "Du skrev in flyttalet:" << setfill('-')
    << setw(9) << flyttal << endl;

    cin.ignore(10000, '\n');


    char character{};
    cout << "\nSkriv in ett tecken: ";
    cin >> character;
    cout << "Du skrev in tecknet: " << character << endl;

    cin.ignore(10000, '\n');


    string straeng{};
    cout << "\nSkriv in en sträng: ";
    cin >> straeng;
    cout << "strängen '" << straeng << "' har " << straeng.length() << " tecken." << endl;

    cin.ignore(10000, '\n');

    cout << "\nSkriv in ett heltal och en sträng: ";
    cin >> heltal;
    cin >> straeng;
    cout << "Du skrev in talet |" << heltal << "| och strängen |"
    << straeng << "|." << endl;

    cin.ignore(10000, '\n');


    cout << "\nSkriv in en sträng och ett flyttal: ";
    cin >> straeng;
    cin >> flyttal;
    cout << "Du skrev in \""
    << flyttal << "\" och \"" << straeng << "\"." << endl;

    cin.ignore(10000, '\n');


    cout << "\nSkriv in en hel rad med text: ";
    getline(cin, straeng);
    cout << "Du skrev in textraden: '" << straeng << "'" << endl;


    cout << "\nSkriv in en textrad som slutar med ett negativt heltal: ";
    character = '-';
    getline(cin, straeng, character);
    cin >> heltal;
    cout << "Du skrev in textraden: '" << straeng << "' och heltalet '-"
    << heltal << "'" << endl;

    cin.ignore(10000, '\n');

    return 0;
}
