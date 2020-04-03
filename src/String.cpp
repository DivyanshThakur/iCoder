#include <iostream>
#include "../header/String.hpp"
#include "../header/UIhandler.hpp"

using namespace std;

void String()
{
    // cod::scan sc;
    // cod::string s1, s2;
    string s1, s2;
    cout << "\nEnter string 1: ";
    // sc >> s1;
    cin >> s1;

    cout << "\nEnter string 2: ";
    // sc >> s2;
    cin >> s2;
    s1 += s2;
    cout << "\nEntered string concated is" << s1 << endl;

    igetch();
}