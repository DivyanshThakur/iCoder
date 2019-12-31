#include <iostream>
#include <string>
#include "UIhandler.h"

void home(const std::string &userID)
{
    system("cls");
    title();
    std::string welcome_message{"Welcome "};
    emessage("Welcome " + userID + "!");
}