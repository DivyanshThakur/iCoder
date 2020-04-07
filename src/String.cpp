#include <iostream>
#include "../header/String.hpp"
#include "../header/UIhandler.hpp"
#include "../namespace/header/cod_string.hpp"

using namespace std;

void String()
{
    border(widthMenu);
    // print_message();
    // cod::string s, c;
    // s = "Divyansh ";
    // c = "Thakur";
    // s.swap(c);
    // cout << s << endl
    //      << s.size() << endl
    //      << s.capacity() << endl
    //      << c << endl
    //      << c.size() << endl
    //      << c.capacity() << endl;

    // cod::string s = "divyansh";
    // cod::string c = "aslkfjslfjsdlfjsljflsdjfsd";
    // s.replace(0, 3, c);

    // cout << s << endl
    //      << s.size() << endl
    //      << s.capacity();

    cod::string s = "ebadjb";

    cod::string s1 = "edadjb";

    cout << boolalpha;

    cout << (s.compare(s1)) << endl;

    getch();
}