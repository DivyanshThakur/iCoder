#include <iostream>
#include <conio.h>
#include "../header/Info.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Constants.hpp"

void about()
{
    char ch;

    header(std::string{" ABOUT "});

    std::cout << "Developer: " << dev_name << std::endl
              << "Version: " << version_info;

    border(width_menu);

    std::cout << "Source code:" << std::endl
              << scode_url.substr(8);

    border(width_menu);

    std::cout << "Press i to open URL";

    ch = getch();

    if (::tolower(ch) == 'i') // this code will open github source code in default browser
        system(std::string("start " + scode_url).c_str());
    else
        return;
}

void help()
{
    print_message();
    press_key(); // getch()
}

void download()
{
    print_message();
    press_key(); // getch()
}

void changelog()
{
    print_message();
    press_key();
}