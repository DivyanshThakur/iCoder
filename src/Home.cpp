#include <iostream>
#include "../header/Home.hpp"
#include "../namespace/header/cod_scan.hpp"

void home(const std::string &userID)
{
    int flag{1};

    if (flag && Global::showWelcome)
    {
        flag = 0;
        title();                                 // display the title = iCoder
        emessage("--> Welcome " + userID + "!"); // display the welcome message
        showedOneTime = false;
    }
}